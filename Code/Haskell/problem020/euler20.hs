-- *Main> sum $ digitList $ product [1..100]
-- 648

digitList :: (Integral a) => a -> [a]
digitList 0 = []
digitList n = (digitList lead) ++ (trail:[])
  where trail = n `mod` 10
        lead  = (n - trail) `div` 10

