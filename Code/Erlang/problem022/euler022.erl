-module(euler022).
-export([
  readfile/1
  ,strip_quote_chars/1
  ,name_score/1
  ,compute_name_sum/1
  ,euler/0
  ]).

euler() ->
  NameList = lists:sort(
      strip_quote_chars(readfile("names.txt"))
      ),
  {Score,_MaxIndex} = compute_name_sum(NameList),
  Score.

compute_name_sum(NameList) ->
  lists:foldl(
    fun(X,Acc) -> 
        {Score,Index} = Acc,
        {name_score(X)*Index + Score,Index+1}
    end, 
    {0,1}, 
    NameList
    ).

name_score(Name) ->
  lists:foldl(fun(X,Acc) -> (X-64) + Acc end, 0, Name). 

readfile(FileName) ->
  {ok, Binary} = file:read_file(FileName),
  string:tokens(erlang:binary_to_list(Binary), ",").

strip_quote_chars(List) ->
  strip_quote_chars(List,[]).
strip_quote_chars([],Acc) -> Acc;
strip_quote_chars(List,Acc) ->
  [Head|Tail] = List,
  [_Q1|Name1] = Head,
  [_Q2|Name2] = lists:reverse(Name1),
  strip_quote_chars(Tail,[lists:reverse(Name2)|Acc]).
