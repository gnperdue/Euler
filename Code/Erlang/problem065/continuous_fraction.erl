-module(continuous_fraction).
-export([
    simple_cont_fract_conv/4
  ]
).

simple_cont_fract_conv(
  Niters,
  Start, 
  Numer, 
  Denom) ->
  Start + Numer / cont_denom(1, Niters, Numer, Denom).

cont_denom(Iter, Niters, Numer, Denom) ->
  io:format("Iter = ~w, Niters = ~w, Numer = ~w, Denom = ~w~n",
    [Iter,Niters,Numer,Denom]),
  if 
    Iter >= Niters -> Denom;
    Iter <  Niters -> Denom + Numer / cont_denom(Iter+1, Niters, Numer, Denom)
  end.


