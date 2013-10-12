-module(euler002).
-export([euler2/1,fibo/1,tail_fibo/1]).

%% @doc Input is the target index.
fibo(0) -> 1;
fibo(1) -> 1;
fibo(N) -> fibo(N-1) + fibo(N-2).

%% @doc Input is the target index.
tail_fibo(N) when N >= 0 ->
  if
    N == 0 -> 1;
    N == 1 -> 1;
    N >  1 -> tail_fibo(N,2,1,2) 
  end.
%% @doc Inputs are: target index, counter, last two Fibonnaci numbers.
tail_fibo(N,I,_,C) when I >= N -> C;
tail_fibo(N,I,B,C) -> tail_fibo(N,I+1,C,B+C).

euler2(Max) ->
  euler2(Max,0,0).
euler2(Max,N,Acc) ->
  Fibonum = tail_fibo(N),
  Remainder = Fibonum rem 2,
  if 
    Remainder == 0 -> Sum = Acc + Fibonum;
    Remainder /= 0 -> Sum = Acc
  end,
  Result = if 
    Fibonum < Max -> euler2(Max,N+1,Sum);
    Fibonum > Max -> Acc
  end,
  Result.





