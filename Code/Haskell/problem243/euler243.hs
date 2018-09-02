module Main where

import Data.Ratio
import Data.List (nub)

main = print $ euler243 testVal

testVal :: Ratio Int
testVal = 15499 % 94744

euler243 :: Ratio Int -> Int
euler243 tv = let l = map (testResil tv) [3..]
                  x = last $ takeWhile (not . snd) l
                  in fst x + 1

testResil :: Ratio Int -> Int -> (Int,Bool)
testResil t d = (d,resiliance d < t)

resiliance :: Int -> Ratio Int
resiliance d = let l = map (%d) [1..(d-1)]
                   x = length $ filter (\x -> denominator x /= d) l
                   r = (d-1) - x
                   in r % (d-1)

evalFrac :: Ratio Int -> Double
evalFrac f = let n = fromIntegral $ numerator f
                 d = fromIntegral $ denominator f
                 in n/d

realResil :: Int -> Double
realResil = evalFrac . resiliance

numDigs :: Int -> Int
numDigs = length . show

uniqueDigs :: Int -> Int
uniqueDigs = length . nub . show

candidates :: [Int]
candidates = filter (\x -> numDigs x == uniqueDigs x) primesPlus

primesPlus :: [Int]
primesPlus = map (+1) primes

primes :: [Int]
primes = listOfPrimes 1000000

listOfPrimes :: Int -> [Int]
listOfPrimes n = seive [] [2..n]

seive :: [Int] -> [Int] -> [Int]
seive acl [] = reverse acl
seive acl (p:rest) = seive (p:acl) (filter ((/= 0) . (`mod` p)) rest)

