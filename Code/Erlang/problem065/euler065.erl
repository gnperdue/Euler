-module(euler065).
-export([
    eval_frac/1
    ,frac_div/2
    ,frac_add/2
    ,cont_frac/2
    ,cont_denom/3
    ,cont_frac_l/2
  ]
).

eval_frac({Numer,Denom}) -> Numer / Denom.

%% @doc Compute a continuted fraction for N convergences with an
%% array-numerator and report the answer as a fraction.
cont_frac_l(Nconvergents, {Start,DenomList}) ->
  CyclePos = 1,
  io:format("~w + ~n",[Start]),
  frac_add(
    {Start,1}, 
    cont_denom_l(1, Nconvergents, {1,DenomList,CyclePos})
  ).

%% @doc Compute the numerator-array continued fractioin recursively.
cont_denom_l(Iter, Nconvergents, {Numer, DenomList,CyclePos}) ->
  % io:format("Iter = ~w, CyclePos = ~w~n", [Iter, CyclePos]),
  Nitems = length(DenomList),
  if
    CyclePos >  Nitems -> 
      Index = CyclePos - Nitems,
      Cycle = CyclePos - Nitems;
    CyclePos =< Nitems -> 
      Index = CyclePos,
      Cycle = CyclePos
  end,
  % io:format("   Index = ~w~n", [Index]),
  Denom  = lists:nth(Index,DenomList),
  if 
    Iter >= Nconvergents -> 
      io:format(" ~w/~w~n",[Numer,Denom]),
      frac_div({Numer,1},{Denom,1});
    Iter <  Nconvergents -> 
      io:format("~w / ~w + ~n",[Numer,Denom]),
      frac_div(
        {Numer,1},
        frac_add(
          {Denom,1}, 
          cont_denom_l(Iter+1, Nconvergents, {Numer, DenomList, Cycle+1})
        )
      )
  end.


%% @doc Compute a simple continuted fraction for N convergences and 
%% report the answer as a fraction.
cont_frac(Nconvergents, {Start,Denom}) ->
  frac_add(
    {Start,1}, 
    frac_div(
      {1,1}, 
      cont_denom(1, Nconvergents, {1,Denom})
    )
  ).

%% @doc Compute the continued fractioin recursively.
cont_denom(Iter, Nconvergents, {Numer, Denom}) ->
  if 
    Iter >= Nconvergents -> {Denom,1};
    Iter <  Nconvergents -> 
      frac_add( 
        {Denom,1}, 
        frac_div({Numer,1}, cont_denom(Iter+1, Nconvergents, {Numer, Denom})) 
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

