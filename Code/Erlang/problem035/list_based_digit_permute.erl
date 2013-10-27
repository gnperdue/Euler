-module(list_based_digit_permute).
-export([
    make_rotations/1
    ,make_cyclic_permutation/1
    ,permute_digits/1
  ]
).

%% @doc Make one cyclic permutation of N by moving the last digit to the head
%% using a list-based approach (this is probably inefficient).
permute_digits(N) ->
  trunc( revert_list_to_number( make_cyclic_permutation( make_digit_list(N) ) ) ).

make_rotations(0) -> [];
make_rotations(N) when N < 0 -> make_rotations(-N);
make_rotations(N) ->
  make_digit_list(N).

make_digit_list(N) ->
  make_digit_list(N,[]).
make_digit_list(0,List) -> List;
make_digit_list(N,List) ->
  X = N rem 10, Y = (N - X) div 10,
  make_digit_list(Y,[X | List]).

make_cyclic_permutation([]) -> [];
make_cyclic_permutation(List) -> 
  Length = length(List),
  {Lead,[H|_T]} = lists:split(Length-1,List),
  [H|Lead].

revert_list_to_number(List) ->
  revert_list_to_number(List,0).
revert_list_to_number([],N) -> N;
revert_list_to_number(List,N) ->
  Power = math:pow(10,length(List)-1),
  [H|T] = List,
  revert_list_to_number(T,N+Power*H).

