qsortc [] = []
qsortc (x : xs) = qsortc smaller ++[x]++ qsortc larger
	where
		smaller = [a | a <- xs, a <= x]
		larger = [b | b <- xs, b > x]

qsortd1 [] = []
qsortd1 (x : xs) = qsortd1 larger ++[x]++ qsortd1 smaller
	where
		smaller = [a | a <- xs, a <= x]
		larger = [b | b <- xs, b > x]

qsortd2 [] = []
qsortd2 (x : xs) = qsortd2 smaller ++[x]++ qsortd2 larger
	where
		smaller = [a | a <- xs, a > x]
		larger = [b | b <- xs, b <= x]

fatorial n = product [1..n]

add x y = x + y

add' x y = x + y 

sqr x	= x * x


