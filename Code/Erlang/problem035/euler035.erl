-module(euler035).
-export([
    permute/1
    ,ndigits/1
    ,list_of_cyclic_perms/1
  ]
).

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

ndigits(N) ->
  highest_power(N) + 1.

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


