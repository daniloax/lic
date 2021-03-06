abs :: Int -> Int
abs n = if n >= 0 then n else -n

abs' n 	| n >= 0 = n
			| otherwise = -n

signum :: Int -> Int
signum n = 	if (n < 0)
					then -1 
				else if n == 0
					then 0
				else 1
				
signum' n	| n < 0 = -1
				| n == 0 = 0
				| otherwise = 1

not :: Bool -> Bool
not False = True
not True = False

mdc a 0 = a
mdc a b = mdc b (a `mod` b)

splitAt :: Int -> [a] -> ([a],[a])
splitAt n xs = (take n xs, drop n xs)

removeAt :: Int -> [a] -> [a]
removeAt x xs = (take (x - 1) xs) ++ (drop x xs)

rev :: Fractional a => a -> a
rev n = 1 / n
