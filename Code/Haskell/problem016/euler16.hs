
main = do print $ euler16 (2^1000)

euler16 n = sum $ digitList n

digitList :: (Integral a) => a -> [a]
digitList 0 = []
digitList n = (digitList lead) ++ (trail:[])
  where trail = n `mod` 10
        lead  = (n - trail) `div` 10

