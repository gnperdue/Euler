import System.IO

main = do
  withFile "nums.txt" ReadMode (\handle -> do
    contents <- hGetContents handle
    print $ sum (map read $ lines contents :: [Integer])
    )
