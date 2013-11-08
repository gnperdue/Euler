-module(euler089).
-export([euler/0]).

euler() ->
  lists:foldl(
    fun(X,Acc) ->
        length(X) - length(int_to_roman(parse_roman(X))) + Acc
    end,
    0,
    load_romans()
    ).

load_romans() ->
  readfile("roman.txt").
readfile(FileName) ->
  {ok, Binary} = file:read_file(FileName),
  string:tokens(erlang:binary_to_list(Binary), "\r\n").

int_to_roman(Num) ->
  int_to_roman(Num,lists:reverse(roman_list()),[]).
int_to_roman(0,_RomanList,Acc) -> Acc;
int_to_roman(Num,RomanList,Acc) ->
  [{Val,Chars}|Rest] = RomanList,
  if
    Num >= Val -> int_to_roman(Num - Val, RomanList, Acc ++ Chars);
    Num <  Val -> int_to_roman(Num, Rest, Acc)
  end.

parse_roman(Num) -> 
  if
    length(Num) == 1 -> roman_to_num(Num);
    length(Num) >  1 -> parse_roman(Num,0)
  end.
parse_roman([],Sum) -> Sum;
parse_roman([X1,X2|Rest],Sum) ->
  N1 = roman_to_num([X1]),
  N2 = roman_to_num([X2]),
  if
    N1 == N2 -> parse_roman(Rest,N1+N2+Sum);
    N1 >  N2 -> parse_roman([X2|Rest],N1+Sum);
    N1 <  N2 -> parse_roman(Rest,roman_to_num([X1,X2])+Sum)
  end;
parse_roman([X1],Sum) -> roman_to_num([X1]) + Sum.

roman_to_num(RomanList) ->
  lists:foldl(
    fun(X,Acc) -> 
        {N,L} = X,
        case (L == RomanList) of
          true -> N;
          false -> Acc
        end
    end,
    0,
    roman_list()
    ).

roman_list() -> 
  [{1,    "I"},
   {4,   "IV"},
   {5,    "V"},
   {9,   "IX"},
   {10,   "X"},
   {40,  "XL"},
   {50,   "L"},
   {90,  "XC"},
   {100,  "C"},
   {400, "CD"},
   {500,  "D"},
   {900, "CM"},
   {1000, "M"}].

