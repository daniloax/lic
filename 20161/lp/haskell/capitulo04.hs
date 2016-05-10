splitAt :: Int -> [a] -> ([a],[a])
splitAt n xs = (take n xs, drop n xs)

removeAt :: Int -> [a] -> [a]
removeAt x xs = (take (x - 1) xs) ++ (drop x xs)

rev :: Fractional a => a -> a
rev n = 1 / n
