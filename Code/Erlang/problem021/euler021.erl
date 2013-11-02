-module(euler021).
-export([
  get_divisors/1
  ,get_d/1
  ,euler/0
  ]
       ).

euler() ->
  MasterList = lists:seq(2,10000),
  euler(MasterList,[]).
euler([], AnswerList) -> lists:sum( AnswerList );
euler([H|List], AnswerList) -> 
  Test = get_d(H),
  case (get_d(Test) == H) and (Test /= H) of
    true -> euler( lists:delete(Test,List), [H,Test|AnswerList] );
    false -> euler( List, AnswerList )
  end.

%% @doc d(n) gives the sum of the divisors.
get_d(N) -> lists:sum( get_divisors(N) ).

%% @doc N is not included in the list of divisors.
get_divisors(N) when is_integer(N), N >= 1 ->
  Min = 2,
  Max = N,
  Divisors = [1],
  get_divisors(Min, Max, Divisors, N).
get_divisors(Min, Max, Divisors, _N) when Min >= Max -> Divisors;
get_divisors(Min, Max, Divisors, N) ->
  Remd = N rem Min,
  Divs = N div Min,
  if 
    Remd == 0 -> 
      case Min == Divs of
        true  -> get_divisors(Min+1, Divs, [Min | Divisors], N);
        false -> get_divisors(Min+1, Divs, [Min, Divs | Divisors], N)
      end;
    Remd /= 0 -> get_divisors(Min+1, Max, Divisors, N)
  end.

