-module(euler014).
-export([collatzl/1]).

collatzl(Start) ->
  collatzl(Start,1).

collatzl(Number,Length) when Number =:= 1 -> 
  io:format("One Clause: Number = ~w, Length = ~w.~n",[Number,Length]),
  Length;
collatzl(Number,Length) when Number rem 2 =:= 0 -> 
  io:format("Even Clause: Number = ~w, Length = ~w.~n",[Number,Length]),
  collatzl( Number div 2, Length+1 );
collatzl(Number,Length) -> 
  io:format("General Clause: Number = ~w, Length = ~w.~n",[Number,Length]),
  collatzl( 3*Number + 1, Length+1 ).

