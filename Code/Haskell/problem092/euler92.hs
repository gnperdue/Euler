import Data.List (foldl')

main = print $ euler092 10000000

euler092 :: Integral a => a -> a
euler092 n = ncount 89 (digitSquareEndSequence n)

ncount :: (Integral a) => a -> [a] -> a
ncount n xs = foldl' (\acc x -> if x==n then acc + 1 else acc) 0 xs

digitSquareEndSequence :: (Integral a) => a -> [a]
digitSquareEndSequence n = map digitSquareEndPoint [1..n]

digitSquareEndPoint :: Integral a => a -> a
digitSquareEndPoint n  = sequenceval
  where digSqSm     = digitSquareSum n
        sequenceval = if (digSqSm == 89) || (digSqSm == 1)
                      then digSqSm
                      else digitSquareEndPoint digSqSm

digitSquareSum :: Integral a => a -> a
digitSquareSum n = sum $ map (^2) $ digitList n

digitList :: (Integral a) => a -> [a]
digitList 0 = []
digitList n = (digitList lead) ++ (trail:[])
  where trail = n `mod` 10
        lead  = (n - trail) `div` 10

