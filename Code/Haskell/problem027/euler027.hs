
main = print euler27

euler27 = let (a,b) = snd $ largestNumberOfPrimes 1000 1000
              in a*b

largestNumberOfPrimes :: Integer -> Integer -> (Int, (Integer, Integer))
largestNumberOfPrimes x y = let ls = tupleList x y
                                in maximum $ zip (map nquadprime ls) ls

nquadprime :: (Integer, Integer) -> Int
nquadprime (a,b) = let q = quadFormPrime a b
                     in length $ takeWhile (==True) $ map q [0..]

quadFormPrime :: Integer -> Integer -> Integer -> Bool
quadFormPrime a b n = let p = quadForm a b n
                          in isPrime p

quadForm :: Integer -> Integer -> Integer -> Integer
quadForm a b n = n*n + a*n + b

isPrime :: Integer -> Bool
isPrime n = n `elem` primes

tupleList :: Integer -> Integer -> [(Integer,Integer)]
tupleList x y = [ (a,b) | a <- [(-x)..x], b <-[(-y)..y], abs b `elem` primes ]

primes :: [Integer]
primes = listOfPrimes 10000

listOfPrimes :: Integer -> [Integer]
listOfPrimes n = seive [] [2..n]

seive :: [Integer] -> [Integer] -> [Integer]
seive acl [] = reverse acl
seive acl (p:rest) = seive (p:acl) (filter ((/= 0) . (`mod` p)) rest)

