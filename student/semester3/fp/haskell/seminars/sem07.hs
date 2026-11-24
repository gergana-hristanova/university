--- Ex 1 & Ex 2 ---

fibonacci1 0 = 0
fibonacci1 1 = 1
fibonacci1 n = fibonacci1 (n - 1) + fibonacci1 (n - 2)

fibonacci2 n
    | n == 0 = 0
    | n == 1 = 1
    | n > 1  = fibonacci2 (n - 1) + fibonacci2(n - 2)

fibonacci3 0 = 0
fibonacci3 1 = 1
fibonacci3 n = backFib + backBackFib
    where backFib = fibonacci3 (n - 1)
          backBackFib = fibonacci3 (n - 2)

--- Ex 3 ---

fastPow x n
    | x == 1 || n == 0 = 1
    | mod n 2 == 0     = (fastPow x (div n 2))^2
    | otherwise        = x * (fastPow x (div n 2))^0x2

--- Ex 4 ---

complAdd (r1, i1) (r2, i2) = (r1 + r2, i1 + i2)

complSub (r1, i1) (r2, i2) = complAdd (r1, i1) (-r2, -i2)

--- Ex 5 ---

distance (x1, y1) (x2, y2) = sqrt((x1 - x2)^2 + (y1 - y2)^2)

--- Ex 6 ---

isPrime n 
    | n == 1 = False
    | otherwise = if length [ x | x <- [2 .. (n - 1)], mod n x == 0 ] == 0
        then True else False

--- Ex 6 ---

repeated _ 0 = id
repeated f 1 = f
repeated f n = f . (repeated f (n - 1))
