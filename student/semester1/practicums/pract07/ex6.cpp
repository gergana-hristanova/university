// #include <iostream>

// const int MAX_SIZE = 8;

// int binaryToDecimal(int bin)
// {
//     int dec = 0;
//     int mult = 1;
//     while (bin)
//     {
//         dec += mult * (bin % 10);
//         bin /= 10;
//         mult *= 2;
//     }

//     return dec;
// }

// char getSymbolFromIndex(int n)
// {
//     if (0 <= n && n <= 9)
//         return n + '0';
//     else if (10 <= n)
//         return n - 10 + 'A';
//     else
//         return -1;
// }

// void convertToBinary(int negativeBinary, char result[]) {

//     int counter = MAX_SIZE - 1;
//     while(negativeBinary) {

//         result[counter] = getSymbolFromIndex(negativeBinary % 2);
//         negativeBinary /= 2;
//         counter--;
//     }
// }

// int negativeBinary(int bin, char result[])
// {
//     convertToBinary(bin, result);

//     for(int i = 0; i < MAX_SIZE; i++) {

//         result[i] = !result[i];
//     }

// }

// int main()
// {
//     int input = 0b00001010;
//     char result[MAX_SIZE];

//     negativeBinary(input, result);

//     for(int i = 0; i < MAX_SIZE; i++) {

//         std::cout << result[i] << " ";
//     }
// }

