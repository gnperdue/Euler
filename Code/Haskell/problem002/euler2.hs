-- *Main> sum $ takeWhile(<4000000) (filter even inffibo)
-- 4613732
-- *Main> takeWhile(<40000) (filter even inffibo)
-- [2,8,34,144,610,2584,10946]
-- *Main> takeWhile(<50000) (filter even inffibo)
-- [2,8,34,144,610,2584,10946,46368]
-- *Main> takeWhile(<50000) (inffibo)
-- [1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368]

fibo :: (Eq a, Num a) => a -> a
fibo 0 = 1
fibo 1 = 1
fibo n = fibo (n-1) + fibo (n-2)

inffibo = map fibo [1..]

listOfFibos :: Int -> [[Integer]]
listOfFibos 0 = [] : []
listOfFibos 1 = take 1 inffibo : []
listOfFibos n = take n inffibo : listOfFibos (n-1)

fiboMax :: Int -> Integer
fiboMax n = last $ head $ listOfFibos n
