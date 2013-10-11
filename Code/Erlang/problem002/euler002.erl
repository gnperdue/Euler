-module(euler002).
-export([euler2/1,fibo/1]).

fibo(0) -> 1;
fibo(1) -> 1;
fibo(N) -> fibo(N-1) + fibo(N-2).

euler2(Max) ->
  euler2(Max,0,0).
euler2(Max,N,Acc) ->
  Fibonum = fibo(N),
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





