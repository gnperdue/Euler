
euler10 :: Integer -> Integer
euler10 n = sum $ seive [] [2..n]

seive :: [Integer] -> [Integer] -> [Integer]
seive acl [] = reverse acl
seive acl (p:rest) = seive (p:acl) (filter ((/= 0) . (`mod` p)) rest)

main = print $ euler10 2000000
