-- ghc --make -fwarn-incomplete-patterns -fwarn-name-shadowing euler1.hs 

main = do
  print $ euler1

euler1 = sum [x | x <- [3..1000], x `mod` 3 == 0 || x `mod` 5 == 0]

