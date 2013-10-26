-module(euler065).
-export([
    frac_div/2
    ,frac_add/2
    ,cont_frac_e/1
    ,cont_frac_e/2
    ,euler/1
    ,digit_sum/1
  ]
).

euler() -> euler(99). % My "first" term is start + the first fraction.
euler(X) -> 
  {N,_D} = cont_frac_e(X),
  digit_sum(N).

digit_sum(N) ->
  digit_sum(N,[]).
digit_sum(0,List) -> lists:foldl(fun(X,Sum) -> X + Sum end, 0, List);
digit_sum(N,List) ->
  X = N rem 10,
  Y = (N - X) div 10,
  digit_sum(Y,[X | List]).

%% @doc Compute a continuted fraction for N convergences of e.
cont_frac_e(Nconvergents) ->
  cont_frac_e(Nconvergents, {2,[1,0,1]}).
cont_frac_e(Nconvergents, {Start,DenomList}) ->
  CyclePos = 1,
  frac_add(
    {Start,1}, 
    cont_denom_e(1, Nconvergents, {1,DenomList,CyclePos})
  ).

%% @doc Compute the numerator-array continued fractioin recursively.
%% Modify the denominator list for each iteration as per the e pattern.
cont_denom_e(Iter, Nconvergents, {Numer, DenomList,CyclePos}) ->
  Nitems = length(DenomList),
  if
    CyclePos >  Nitems -> 
      Index = CyclePos - Nitems;
    CyclePos =< Nitems -> 
      Index = CyclePos
  end,
  [Lead, Middle, Last] = DenomList,  
  if 
    Index == 1 -> NewDenomList = DenomList;
    Index == 2 -> NewDenomList = [Lead, 2 + Middle, Last];
    Index == 3 -> NewDenomList = DenomList
  end,
  Denom = lists:nth(Index,NewDenomList),
  if 
    Iter >= Nconvergents -> 
      frac_div({Numer,1},{Denom,1});
    Iter <  Nconvergents -> 
      frac_div(
        {Numer,1},
        frac_add(
          {Denom,1}, 
          cont_denom_e(Iter+1, Nconvergents, {Numer, NewDenomList, Index+1})
        )
      )
  end.

%% @doc Do ``fractional addition'' where the tuple  {A,B} represents
%% the {numerator, denominator}:  A/B + C/D = (A*D + C*B)/(B*D)
frac_add({A,B},{C,D}) ->
  frac_reduce({A*D + B*C, B*D}).

%% @doc Do ``fractional division'' where the tuple {A,B} represents
%% the {numerator, denominator}:  A/B / C/D = (A*D)/(B*C)
frac_div({A,B},{C,D}) ->
  frac_reduce({A*D, B*C}).

%% @doc Reduce the fraction where the tuple {A,B} represents
%% the {numerator, denominator}.
frac_reduce({X,Y}) ->
  Gcd = dijkstra_gcd({X,Y}),
  {X div Gcd, Y div Gcd}.

%% @doc Compute the greatest common denominator of two numbers.
dijkstra_gcd({M,N}) ->
  if
    M == N -> M;
    M > N  -> dijkstra_gcd({M-N,N});
    M < N  -> dijkstra_gcd({M,N-M})
  end.

