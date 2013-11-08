-module(euler004).
-export([euler/0]).

euler() ->
  hd( 
    lists:reverse(
      [ X*Y || 
        X <- lists:seq(900,999), 
        Y <- lists:seq(900,999), 
        is_palindromic_number(X*Y) ]
      )
    ).

is_palindromic_number(N) ->
  ListN = integer_to_list(N),
  ListN == lists:reverse(ListN).

