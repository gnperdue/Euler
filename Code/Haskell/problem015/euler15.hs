-- Lattice paths
-- There are 6 paths from (0,0) to (2,2). This is equal to \binomial{4}{2}.
-- How many paths to (20,20)?

main = print $ latticPaths 20

latticPaths :: Integral a => a -> a
latticPaths n = binomial (n + n) n 

binomial :: (Integral a) => a -> a -> a
binomial n m = factorial n `div` (factorial m * factorial (n-m))

factorial :: (Integral a) => a -> a
factorial 0 = 1
factorial 1 = 1
factorial n = n * factorial (n - 1)

