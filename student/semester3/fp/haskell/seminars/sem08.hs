import Prelude hiding(length, reverse, all, any, minimum, maximum, append, replicate)

--- Ex 1 ---

reverse lst = foldr (\ el res -> res ++ [el]) [] lst

length lst = foldr (\ el len -> len + 1) 0 lst 

all p lst = foldr (\ el res -> (p el) && res) True lst

any p lst = foldr (\ el res -> (p el) || res) False lst

minimum lst = foldr min (head lst) (tail lst)

maximum lst = foldr max (head lst) (tail lst)

append lst1 lst2 = foldr (\ el res -> el : res) lst2 lst1

replicate lst = foldr (\ el res -> el : res) [] lst

--- Ex 2 ---

divisors n = [x | x <- [1 .. n], mod n x == 0]
count_divisors n = length (divisors n)
sum_divisors n = sum (divisors n)

isPrime n = 0 == length [x | x <- [2 .. floor (sqrt (fromIntegral n))], mod n x == 0] && n /= 0 && n /= 1

descartes lst1 lst2 = [(x , y) | x <- lst1, y <- lst2]

--- Ex 3 ---

primes = [x | x <- [1..], isPrime x]
-- primes = filter isPrime [1..]

--- Ex 4 ---

-- primesErat 0 = []
-- primesErat 1 = []
-- primesErat n = 

--- Ex 5 ---

pairs = [(x, y) | x <- [1..], y <- [1..x]]