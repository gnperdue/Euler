
theNumber :: Integer
theNumber = 600851475143

startingPoint n = floor $ sqrt $ fromIntegral n 

beginAt = startingPoint theNumber

isPrime :: Integer -> Bool
isPrime n = calcIsPrime n (n - 1)

calcIsPrime :: Integer -> Integer -> Bool
calcIsPrime n 1 = True
calcIsPrime n m = case n `rem` m == 0 of
                    True -> False
                    False -> calcIsPrime n (m-1)

euler n test 
 | test <= 1 = 0
 | n `rem` test == 0 && isPrime n = n
 | otherwise = euler n (test - 1)

main = print $ euler theNumber beginAt
