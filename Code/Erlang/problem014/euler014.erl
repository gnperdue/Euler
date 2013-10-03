-module(euler014).
-export([collatzl/1,longest_collatz1/1,longest_collatz2/1,longest_collatz3/1]).

%% longest_collatz1 and longest_collatz2 do the same thing...

longest_collatz1(Max) ->
  lists:foldl( 
    fun(X, Longest) -> 
        if X > Longest ->
            X;
          X =< Longest ->
            Longest
        end
    end, 
    0, 
    [collatzl(N) || N <- lists:seq(1,Max)]).


longest_collatz2(Max) -> 
  lists:foldl( 
    fun(X, Longest) ->
        L = collatzl(X), 
        if L > Longest ->
            L;
          L =< Longest ->
            Longest
        end
    end,
    0, 
    lists:seq(1,Max) 
  ).

longest_collatz3(Max) -> 
  lists:foldl( 
    fun(X, {N,Longest}) ->
        L = collatzl(X), 
        if L > Longest ->
            {X,L};
          L =< Longest ->
            {N,Longest}
        end
    end,
    {0,0}, 
    lists:seq(1,Max) 
  ).

collatzl(Start) ->
  collatzl(Start,1).

collatzl(Number,Length) when Number =:= 1 -> 
  Length;
collatzl(Number,Length) when Number rem 2 =:= 0 -> 
  collatzl( Number div 2, Length+1 );
collatzl(Number,Length) -> 
  collatzl( 3*Number + 1, Length+1 ).

