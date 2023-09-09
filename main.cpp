

#include <iostream>
#include <cstdlib>
#include <ctime>

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void print(int* arr, int len)
{
    for (int i = 0; i < len; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void init(int* arr, int len)
{
    for (int i = 0; i < len; ++i)
    {
        arr[i] = rand() % 100 + 1;
    }
}
void bubblesort(int* arr, int len)
{
    for (int i = len - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
            print(arr, len);
        }
    }
}
void insertionsort(int* arr, int len)
{
    for (int i = 1; i < len; ++i)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            --j;
            print(arr, len);
        }
    }
}
int min(int a, int b) 
{
    return (a < b) ? a : b;
}
void Merge(int* arr, int iEnd1, int iEnd2)
{
    int i = 0;
    int j = iEnd1;
    int k = 0;
    int* ipTemp = new int[iEnd2];
    while (i < iEnd1 && j < iEnd2)
    {
        if (arr[i] < arr[j]) 
        {
            ipTemp[k] = arr[i];
            ++i;
        }
        else 
        {
            ipTemp[k] = arr[j];
            ++j;
        }
        ++k;
    }
    while (i < iEnd1) 
    {
        ipTemp[k] = arr[i];
        ++i;
        ++k;
    }  
    while (j < iEnd2)
    {
        ipTemp[k] = arr[j];
        ++j;
        ++k;
    }
    for (int iIndex = 0; iIndex < iEnd2; ++iIndex) {
        arr[iIndex] = ipTemp[iIndex];
    }
    delete[] ipTemp;
}
void MergeSort(int* arr, int len)
{
    for (int i = 1; i < len; i *= 2)
    {
        for(int j = 0; j < len - i; j += 2*i)
        {
            Merge(&arr[j], i, min( 2*i, len - j));
        }
    }
}
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int size = 4;
    int* array = new int[size];
    init(array, size);
    print(array, size);
    MergeSort(array, size);
    print(array, size);
    delete[] array;
}
