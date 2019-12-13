#include <heap.h>
#include <time.h>
#include <quick.h>
#include <limits.h>

int main(int argc, char* argv[])
{
    printf("%d", INT_MAX);
    srand(time(NULL));
    int* arr = malloc(sizeof(int) * LENGTH);
    for (int i = 0; i < LENGTH; i++)
    {
        arr[i] = rand() % RANGE + 1;
    }
    int max = getmax(arr, LENGTH);
    window* wind = initWindow();
    quickSort(wind, arr, 0, LENGTH - 1, max);
    displayArr(wind, arr, LENGTH, max);
    waitEvent(wind);
    int* newarr = malloc(sizeof(int) * LENGTH);
    for (int i = 0; i < LENGTH; i++)
    {
        newarr[i] = rand() % RANGE + 1;
    }
    window* newwind = initWindow();
    heapSortInArray(newwind, newarr, LENGTH);
    waitEvent(newwind);
    SDL_Quit();
    return 0;
}
    