-- 00: Quicksort crescente (menor || igual)
qsort00 [] = []
qsort00 (x : xs) = qsort01 smaller ++[x]++ qsort01 larger
	where
		smaller = [a| a <- xs, a <= x]
		larger = [b| b <- xs, b > x]
		
-- 01: Quicksort crescente (menor)
qsort01 [] = []
qsort01 (x : xs) = qsort01 smaller ++[x]++ qsort01 larger
	where
		smaller = [a| a <- xs, a < x]
		larger = [b| b <- xs, b > x]

-- 01: Produto dos elementos de uma lista
produto [] = 1
produto (x:xs) = x * produto(xs)

-- 02: Quicksort decrescente (menor || igual)
qsort02 [] = []
qsort02 (x : xs) = qsort02 larger ++[x]++ qsort02 smaller
	where
		smaller = [a | a <- xs, a <= x]
		larger = [b | b <- xs, b > x]

-- 03: Quicksort decrescente (menor)
qsort03 [] = []
qsort03 (x : xs) = qsort03 larger ++[x]++ qsort03 smaller
	where
		smaller = [a | a <- xs, a < x]
		larger = [b | b <- xs, b > x]
-- Resultado: Valores repetidos nao sao incluidos no resultado

{- 04:
	a.	[Char]
	b. (Char,Char,Char)
	c. [(Bool,Char)]
	d. Tipos não correspondentes
	e. [[a] -> [a]] -}
	
-- 05:
--	a.
second :: [[a]] -> [a]
second [] = []
second (x:xs) = head (tail a)
	
