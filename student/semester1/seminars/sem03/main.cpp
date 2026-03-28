#include <iostream>

int main()
{
    // --- Ex 1 ---
    
    // int n = -1;
    // std::cin >> n;

    // int sum = 0;
    // while (n != 0)
    // {
    //     sum += n;

    //     std::cin >> n;
    // }

    // --- Ex 2 ---

    // int a, b;
    // std::cin >> a >> b;

    // int min = (a < b) ? a : b;

    // while (min > 0)
    // {
    //     if (a % min == 0 && b % min == 0)
    //     {
    //         std::cout << min << " ";
    //     }

    //     min--;
    // }

    // --- Ex 3 ---

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

    // --- Ex 4 ---

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

    // --- Ex 5 ---

    // int n;
    // std::cin >> n;

    // bool isPowerOf2 = false;
    // for (int i = 2; i <= n && !isPowerOf2; i *= 2)
    // {
    //     if (i == n)
    //     {
    //         isPowerOf2 = true;
    //     }
    // }

    // std::cout << isPowerOf2;

    // --- Ex 6 ---

    // int a, b, c, d, e;
    // std::cin >> a >> b >> c >> d >> e;

    // for (int x = -100; x <= 100; x++)
    // {
    //     int polinome = a * x * x * x * x
    //                  + b * x * x * x
    //                  + c * x * x
    //                  + d * x
    //                  + e;
        
    //     if (polinome >= 0)
    //     {
    //         std::cout << x << " ";
    //     }
    // }

    // --- Ex 17 ---
    
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