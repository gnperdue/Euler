-module(euler006).
-export([euler6/1]).

% 1> c(euler006).
% {ok,euler006}
% 2> euler006:euler6(10). 
% 2640
% 3> euler006:euler6(100).
% 25164150

euler6(Max) ->
  square_sum(Max) - sum_squares(Max).

sum_squares(Max) ->
  lists:foldl( fun(X, Sum) -> X + Sum end, 0, 
    [X*X || X <- lists:seq(1,Max)]).

square_sum(Max) -> 
  Value = sumnums(Max),
  Value * Value.

sumnums(Max) -> 
  lists:foldl( fun(X, Sum) -> X + Sum end, 0, lists:seq(1,Max) ).
