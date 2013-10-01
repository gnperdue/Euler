-module(euler001).
-export([euler1/0]).

%% 1> c(euler001).
%% {ok,euler001}
%% 2> euler001:euler1().
%% 234168

euler1() ->
  lists:foldl( fun(X, Sum) -> X + Sum end, 0, 
    [X || X <- lists:seq(3,1000), (X rem 3 =:= 0) or (X rem 5 =:= 0)]).

