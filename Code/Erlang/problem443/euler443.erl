-module(euler443).
-compile([export_all]).

show_g(N) ->
  Glist = g_list(N),
  lists:foreach(fun(Item) -> io:format("~p~n",[Item]) end, Glist).

g_list(N) ->
  g_list(4,N,[{4,13}]).
g_list(I,N,Acc) when I == N -> Acc;
g_list(I,N,Acc) ->
  J = I + 1,
  G = g(J),
  g_list(J, N, [{J,G}|Acc]).

g(N) when N > 4 ->
  g(4, 13, N).
g(PrevI, Val, N) when PrevI == N -> Val;
g(PrevI, Val, N) ->
  NewI   = PrevI + 1,
  NewVal = Val + dijkstra_gcd({Val, NewI}),
  g(NewI, NewVal, N).

slow_g(4) -> 13;
slow_g(N) when N > 4 -> 
  G = slow_g(N-1),
  G + dijkstra_gcd({N, G}).

%% @doc Compute the greatest common denominator of two numbers.
dijkstra_gcd({M,N}) ->
  if
    M == N -> M;
    M > N  -> dijkstra_gcd({M-N,N});
    M < N  -> dijkstra_gcd({M,N-M})
  end.

