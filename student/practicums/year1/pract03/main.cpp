#include <iostream>
#include <cmath>

int main()
{
    // --- Ex 1 ---

    // int n1, n2;
    // std::cin >> n1 >> n2;

    // int max = (n1 > n2) ? n1 : n2;
    // int lcmCandidate = max;
    // while (lcmCandidate % n1 != 0 || lcmCandidate % n2 != 0)
    // {
    //     lcmCandidate += max;
    // }

    // std::cout << lcmCandidate;

    // --- Ex 2 ---

    // int n1, n2;
    // std::cin >> n1 >> n2;

    // Variant #1 (Original and overkill)

    // if (n2 > n1)
    // {
    //     int temp = n1;
    //     n1 = n2;
    //     n2 = temp;
    // }

    // int GCD = 0;
    // for (int a = n1, b = n2, c = a; b != 0; a = b, b = c % b)
    // {
    //     GCD = b;
    // }

    // std::cout << GCD;

    // Variant #2 (Angel's)

    // while (n2 != 0)
    // {
    //     int mod = n1 % n2;
    //     n1 = n2;
    //     n2 = mod;
    // }

    // std::cout << n1;

    // --- Ex 2.5 ---

    // int n1, n2;
    // std::cin >> n1 >> n2;

    // int min = (n1 < n2) ? n1 : n2;
    // for (int i = min; i >= 1; i--)
    // {
    //     if (n1 % i == 0 && n2 % i == 0)
    //     {
    //         std::cout << i << " ";
    //     }
    // }

    // --- Ex 3 ---

    // int n;
    // std::cin >> n;

    // bool isPrime = true;
    // double sqrtN = sqrt(n);
    // for (int i = 2; i <= sqrtN; i++)
    // {
    //     if (n % i == 0)
    //     {
    //         isPrime = false;
    //         break;
    //     }
    // }

    // std::cout << isPrime;

    // --- Ex 3.5 ---

    // int intervalStart, intervalEnd;
    // std::cin >> intervalStart >> intervalEnd;

    // for (int i = intervalStart; i <= intervalEnd; i++)
    // {
        
    //     bool isPrime = true;
    //     double sqrtN = sqrt(i);
    //     for (int j = 2; j <= sqrtN; j++)
    //     {
    //         if (i % j == 0)
    //         {
    //             isPrime = false;
    //             break;
    //         }
    //     }

    //     if (isPrime)
    //     {
    //         std::cout << i << std::endl;
    //     }
    // }

    // --- Ex 4 ---

	// int n;
	// std::cin >> n;

	// int commonDigit = -1;
	// int commonDigitAppearances = 0;
	// for (int digit = 0; digit <= 9; digit++)
	// {
	// 	int nCopy = n;
	// 	int digitAppearances = 0;
	// 	while (nCopy != 0)
	// 	{
	// 		int lastDigit = nCopy % 10;

	// 		if (lastDigit == digit)
    //         {
    //             digitAppearances++;
    //         }
				
	// 		nCopy /= 10;
	// 	}

	// 	if (digitAppearances > commonDigitAppearances)
	// 	{
	// 		commonDigit = digit;
	// 		commonDigitAppearances = digitAppearances;
	// 	}
	// }

	// std::cout << commonDigit;

    // --- Ex 5 ---

    // int n = -1;
    // std::cin >> n;

    // int sum = 0;
    // while (n != 0)
    // {
    //     sum += n;

    //     std::cin >> n;
    // }

    // std::cout << sum;

    // --- Ex 6 ---

    // int n;
    // std::cin >> n;

    // int digitsCount = 0;
    // int nCopy = n;
    // while (nCopy != 0)
    // {
    //     digitsCount++;
    //     nCopy /= 10;
    // }

    // if (digitsCount == 1)
    // {
    //     std::cout << 0;
    // }
    // else
    // {
    //     int mid1 = digitsCount / 2;
    //     int mid2 = digitsCount / 2;
    //     if (digitsCount % 2 == 0)
    //     {
    //         mid2++;
    //     }

    //     //using divisor in a loop since pow() hasn't been learned yet
    //     int divisor = 1;
    //     for (int i = 1; i < digitsCount; i++)
    //     {
    //         divisor *= 10;
    //     }

    //     for (int i = 0; i < digitsCount; i++)
    //     {
    //         int digit = n / divisor;
            
    //         if (i != mid1 - 1 && i != mid2 - 1)
    //         {
    //             std::cout << digit;
    //         }

    //         n %= divisor;
    //         divisor /= 10;
    //     }
    // }

    // --- Ex 7 ---

    // int n;
    // std::cin >> n;

    // bool isPowerOf2 = false;
    // for (int i = 2; i <= n; i *= 2)
    // {
    //     if (i == n)
    //     {
    //         isPowerOf2 = true;
    //         break;
    //     }
    // }

    // std::cout << isPowerOf2;

    // --- Ex 8 ---

    //a * x^4 - b * x^3 + c x^2 - d * x + e?

    // int a, b, c, d, e;
    // std::cin >> a >> b >> c >> d >> e;

    // for (int x = -100; x <= 100; x++)
    // {
    //     //not sure if that's the polinome
    //     int polinome = a * x * x * x * x
    //                  - b * x * x * x
    //                  + c * x * x
    //                  - d * x
    //                  + e;
        
    //     if (polinome == 0)
    //     {
    //         std::cout << x << " ";
    //     }
    // }

    // --- Ex 9 ---

    // int n;
    // std::cin >> n;

    // int max = -1;
    // int scndMax = -1;
    // for (int i = 0; i < n; i ++)
    // {
    //     int currentNum;
    //     std::cin >> currentNum;

    //     max = (currentNum > max) ? currentNum : max;
    //     scndMax = (currentNum > scndMax && currentNum < max) ? currentNum : scndMax;
    // }

    // std::cout << max << " " << scndMax;
}