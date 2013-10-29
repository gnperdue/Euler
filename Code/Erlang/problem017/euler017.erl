-module(euler017).
-export([
    euler/1
    ,number_to_word/1
    ,number_to_letter_count/1
  ]
).

euler(N) when N > 0, N =< 1000, is_integer(N) -> 
  length( 
    lists:flatmap( 
      fun(X) -> number_to_word(X) end,
      lists:seq(1,N)
    )
  ).

number_to_letter_count(N) when N > 0, N =< 1000, is_integer(N) ->
  length( number_to_word(N) ).

number_to_word(N) when N > 0, N =< 1000, is_integer(N) ->
  if 
    N < 10 -> one_to_nine_to_word(N);
    N >= 10, N <  20 -> teens_to_word(N);
    N >= 20, N =< 99 -> 
      Remdr  = (N rem 10),
      Decade = N - Remdr,
      decade_to_word(Decade) ++ one_to_nine_to_word(Remdr);
    N >= 100, N < 1000 -> 
      Basic = N rem 100,
      Century = (N - Basic) div 100,
      if
        Basic == 0 -> Ender = "";
        Basic /= 0 -> Ender = "and" ++ number_to_word(Basic)
      end,
      one_to_nine_to_word(Century) ++ "hundred" ++ Ender;
    N == 1000 -> "onethousand"
  end.

one_to_nine_to_word(N) when N >= 0, N =< 9, is_integer(N) ->
  case N of
    0 -> "";
    1 -> "one";
    2 -> "two";
    3 -> "three";
    4 -> "four";
    5 -> "five";
    6 -> "six";
    7 -> "seven";
    8 -> "eight";
    9 -> "nine"
  end.

teens_to_word(N) when N >= 10, N =< 19, is_integer(N) ->
  case N of
    10 -> "ten";
    11 -> "eleven";
    12 -> "twelve";
    13 -> "thirteen";
    14 -> "fourteen";
    15 -> "fifteen";
    16 -> "sixteen";
    17 -> "seventeen";
    18 -> "eighteen";
    19 -> "nineteen"
  end.

decade_to_word(N) when N >= 20, N =< 90, is_integer(N) ->
  case N of
    20 -> "twenty";
    30 -> "thirty";
    40 -> "forty";
    50 -> "fifty";
    60 -> "sixty";
    70 -> "seventy";
    80 -> "eighty";
    90 -> "ninety"
  end.

