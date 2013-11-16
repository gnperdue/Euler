main = print $ euler10 2000000

euler10 :: Integer -> Integer
euler10 n = sum $ listOfPrimesLessThan n

listOfPrimesLessThan :: (Integral a) => a -> [a]
listOfPrimesLessThan n = takeWhile(<=n) [x | x<-2:[3,5..], isPrime x]

isPrime :: Integral a => a -> Bool
isPrime n = (n > 1) && calcIsPrime n (n-1)

calcIsPrime :: (Integral a) => a -> a -> Bool
calcIsPrime n 1 = True
calcIsPrime n m = (n `mod` m) /= 0 && calcIsPrime n (m-1)

