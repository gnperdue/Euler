

-- alg from : http://projecteuler.net/thread=2;page=2 by kaptenkred
fib :: (Num a, Ord a) => a -> a
fib n = l 1 1 n where
  l a b c = if c<2 then a else l (a+b) a (c-1)

numberOfDigits :: Integer -> Int
numberOfDigits n = length $ show n

fiblength :: Integer -> Int
fiblength n = numberOfDigits $ fib n

inffiblen :: [Int]
inffiblen = map fiblength [1..]

almostans :: Int
almostans = length $ takeWhile(<1000) inffiblen

main = do
    print (2 + almostans)

