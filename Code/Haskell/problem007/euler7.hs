main = do
   print $ head $ answer

answer :: [Integer]
answer = reverse $ take(10001) infPrimes

infPrimes :: [Integer]
infPrimes = [x | x<-[2..], (isPrime x == True)]

isPrime :: Integral a => a -> Bool
isPrime n = calcIsPrime n (n-1)

calcIsPrime :: (Integral a) => a -> a -> Bool
calcIsPrime n 1 = True
calcIsPrime n m = if ( (n `mod` m) == 0 ) 
                  then False
                  else calcIsPrime n (m-1)



