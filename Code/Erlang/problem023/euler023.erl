-module(euler023).
-export([
  euler/0,
  list_of_nums_without_abundant_sums/1,
  have_at_least_one_abundant_sum/1,
  is_abundant_num/1,
  get_divisors/1,
  print_list/1,
  list_of_abundance_of_nums/1
  ]).

euler() ->
  lists:sum( list_of_nums_without_abundant_sums(28123) ).

print_list([]) -> [];
print_list([H|T]) -> 
  io:format("~p~n", [H]),
  [H|print_list(T)].

list_of_nums_without_abundant_sums(MaxCheck) ->
  [ X || X <- lists:seq(1,MaxCheck), 
         have_at_least_one_abundant_sum(X) == false ]. 

list_of_abundance_of_nums(MaxCheck) ->
  [ get_abundance_of_num(X) || X <- lists:seq(1,MaxCheck) ].

have_at_least_one_abundant_sum(N) ->
  look_for_abundant_pair( get_list_of_sums(N) ).
look_for_abundant_pair([]) -> false;
look_for_abundant_pair([Head|Rest]) ->
  case is_abundant_pair(Head) of
    true  -> true;
    false -> look_for_abundant_pair(Rest)
  end.

get_list_of_sums(N) when N <  2 -> [];
get_list_of_sums(N) ->
  get_list_of_sums(1, N-1, []).
get_list_of_sums(Min,Max,AccList) when Min > Max -> AccList;
get_list_of_sums(Min,Max,AccList) ->
  get_list_of_sums(Min+1,Max-1,[{Min,Max}|AccList]).

is_abundant_pair({N1,N2}) ->
  case is_abundant_num(N1) of
    true  -> is_abundant_num(N2);
    false -> false
  end.

get_abundance_of_num(N1) ->
  case is_abundant_num(N1) of
    true  -> N1;
    false -> 0.0
  end.

is_perfect_num(N) -> get_d(N) == N.
is_deficient_num(N) -> get_d(N) < N.
is_abundant_num(N) -> get_d(N) > N.

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

