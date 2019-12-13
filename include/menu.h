#include <stdlib.h>
#include <stdio.h>
#include <heap.h>

#define CREATERANDOMARR     1
#define FILLARRMANU         2
#define POPNODE             3
#define SORTASHEAP          4
#define HEAPSORT            5

void menu(void)
{
    int choice = 0;
    int* arr;
    int len;
    scanf("%d", &choice);
    
    switch (choice)
    {
    case CREATERANDOMARR:
        
        break;
    case FILLARRMANU:
        /* code */
        break;
    default:
        break;
    }
    
    switch (choice)
    {
    case POPNODE:
        /* code */
        break;
    case SORTASHEAP:

        break;
    case HEAPSORT:
        heapSort(arr, len);
        break;
    
    default:
        break;
    }
}