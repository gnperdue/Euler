import System.IO

-- here we always have pairs of digits with spaces in between
spaceBreaker :: String -> [Int]
spaceBreaker "" = []
spaceBreaker (' ':xs) = spaceBreaker xs
spaceBreaker (x:y:xs) = (read [x,y] :: Int) : spaceBreaker xs

main = do 
  contents <- readFile "numbers.txt"
  let rows = map spaceBreaker $ lines contents
  mapM_ print rows
  -- putStr contents

