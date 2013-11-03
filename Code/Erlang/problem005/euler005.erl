-module(euler005).
-export([
  is_evenly_divisible_by_all/2
  ,euler/0
  ]).

euler() -> 
  euler(20, 20).
euler(Target, MaxDiv) ->
  case (is_evenly_divisible_by_all(Target,MaxDiv)) of
    true  -> Target;
    false -> euler(Target + 1, MaxDiv)
  end. 
  
is_evenly_divisible_by_all(Target,MaxDiv) ->
  {_, Answer} = lists:foldl(
      fun(X,Acc) -> 
          {Targ, Cumul} = Acc,
          case Cumul of
            true -> 
              case (Targ rem X == 0) of
                true  -> {Targ, true};
                false -> {Targ, false}
              end;
            false -> {Targ,false}
          end
      end,
      {Target,true},
      lists:seq(1,MaxDiv)
      ),
  Answer.
