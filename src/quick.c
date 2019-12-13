#include <quick.h>

void quickSort(window* wind, int* arr, int low, int high, int max)
{
    if (low < high)
    {
        int pivot = partition(wind, arr, low, high);
        displayArr(wind, arr, LENGTH, max);
        quickSort(wind, arr, low, pivot - 1, max);
        quickSort(wind, arr, pivot + 1, high, max);
    }
}

int partition(window* wind, int* arr, int low, int high)
{
    int pivot = arr[high];
    int index = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            index++;
            swap(&arr[index], &arr[j]);
        }
    }
    swap(&arr[index + 1], &arr[high]);
    return (index + 1);
}

void swap(int* valf, int* vals)
{
    int t = *valf;
    *valf = *vals;
    *vals = t;
}