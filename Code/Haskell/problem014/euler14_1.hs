
main = do print $ (findMaxIndex . collatzSizes) 1000000

-- collatz :: (Fractional a, Integral a) => a -> [a]
collatz :: (Integral a) => a -> [a]
collatz n = if n <= 1
            then [1]
            else if even n 
                 then n : collatz (n `div` 2)
                 else n : collatz (3 * n + 1)

findMaxIndex xs = filter ((==maximum xs) . (xs !!)) [0..n]
    where n = (length xs) - 1

collatzSizes n = map length $ map collatz [0..n]

-- Gabriels-MacBookPro-2010:Haskell$ time ./euler14
-- Stack space overflow: current size 8388608 bytes.
-- Use `+RTS -Ksize -RTS' to increase it.
--
-- real  0m0.611s
-- user  0m0.479s
-- sys 0m0.120s

