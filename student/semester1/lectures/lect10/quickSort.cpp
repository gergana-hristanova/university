#include <iostream>

// Split the elements in arr so those smaller than pivot go left, the others go right.
void split(int arr[], size_t size, int pivot)
{
    unsigned current = 0; // all right of current are < pivot
    unsigned search = current + 1; //next pivot candidate

    while (current < size)
    {
        if (current <= pivot)
        {
            ++current;
        }
        else
        {
            if (arr[search] <= pivot)
                std::swap(arr[current], arr[search]);
        }
    }
}

void quickSort(int arr[], size_t size)
{
    if (size <= 1) return;


}

void printArr(const int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int arr[] = { 2, 3, 6, 8, 1, 9 };



    printArr(arr, 6);
}