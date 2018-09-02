import Data.List (foldl')

main = do print $ collatzMax 1000

collatz :: (Integral a) => a -> [a]
collatz n = if n <= 1
            then [1]
            else if even n 
                 then n : collatz (n `div` 2)
                 else n : collatz (3 * n + 1)

collatzPair :: Integral a => a -> (a, Int)
collatzPair n = (n, length $ collatz n )

collatzMax n = foldl' (\acc x -> if snd (c x) > snd acc then (c x) else acc) (0,0) [1..n]
          where c = collatzPair 


