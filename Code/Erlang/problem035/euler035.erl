-module(euler035).
-export([
  permute/1
  ,ndigits/1
  ,list_of_cyclic_perms/1
  ,is_prime/1
  ,is_perm_prime/1
  ,is_perm_prime_fmap/1
  ,euler/1
  ]
       ).

euler(N) ->
  List = [Value || Value <- lists:seq(3,N), Value rem 2 /= 0],
  length( lists:filtermap(fun(X) -> is_perm_prime(X) end, List) ) + 1.

%% @doc Is a number "cyclic-permutation-wise prime"?
is_perm_prime(N) -> 
  [H|T] = list_of_cyclic_perms(N),
  case is_prime(H) of
    true -> is_perm_prime_list(T);
    false -> false
  end.
is_perm_prime_list([]) -> true;
is_perm_prime_list(List) ->
  [H|T] = List,
  case is_prime(H) of
    true -> is_perm_prime_list(T);
    false -> false
  end.

%% @doc Is a number "cyclic-permutation-wise prime"?
is_perm_prime_fmap(N) ->
  List = list_of_cyclic_perms(N),
  length(List) == length( lists:filtermap(fun(X) -> is_prime(X) end, List) ).

%% @doc Inefficient prime number finder.
is_prime(N) when N =< 0 -> error;
is_prime(1) -> true;
is_prime(2) -> true;
is_prime(3) -> true;
is_prime(N) ->
  is_prime(N, N-1).
is_prime(_N, M) when M =< 1 -> true;
is_prime(N, M) ->
  X = N rem M,
  if
    X == 0 -> false;
    X /= 0 -> is_prime(N, M-1)
  end. 

%% @doc Make a list of all the cyclic permutations of a number.
list_of_cyclic_perms(N) ->
  Ndig = ndigits(N),
  List = [N],
  list_of_cyclic_perms(N,List,1,Ndig).
list_of_cyclic_perms(_N, List, Iter, MaxIter) when Iter >= MaxIter -> 
  List;
list_of_cyclic_perms(N, List, Iter, MaxIter) ->
  NewN = permute(N),
  NewList = [NewN | List],
  list_of_cyclic_perms(NewN, NewList, Iter+1, MaxIter).

%% @doc How many digits are in the number?
ndigits(N) ->
  highest_power(N) + 1.

%% @doc Make one cyclic permutation by moving the front digit to the end.
permute(N) ->
  H = math:pow(10,highest_power(N)),
  X = N rem 10, Y = (N - X) div 10,
  trunc(X*H + Y).

%% @doc 10^{what} is the highest power?
highest_power(N) ->
  highest_power(N,0).
highest_power(0,Acc) -> Acc;
highest_power(N,Acc) -> 
  Ones = N rem 10, Tens = (N - Ones) div 10,
  if
    Tens == 0 -> highest_power(0,Acc);
    Tens /= 0 -> highest_power(Tens,Acc+1)
  end.


