#include <stdlib.h>
#include <stdio.h>
#include <visual.h>

typedef struct heap heap;

struct heap{
    int* arr;
    int len;
};

heap* createStackFromArray(int* arr, int length);

void printArr(int* arr, int len);

void sortStackFromBottom(heap* st, int i);

int* createSortedArrayFromStack(heap* st);

int popRootFromStack(heap* st);

int* heapSort(int* arr, int len);

void heapSortInArray(window* wind, int* arr, int len);

void createStackInArray(window* wind, heap* st);

void sortArrayInArray(window* wind, heap* st);