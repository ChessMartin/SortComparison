#include <heap.h>

heap* createStackFromArray(int* arr, int length)
{
    heap* st = malloc(sizeof(heap)); 
    st->arr = malloc(sizeof(int) * length);
    st->len = length;
    int i = 0;
    while (i < length)
    {
        st->arr[i] = arr[i];
        sortStackFromBottom(st, i);
        i++;
    }
    return st;  
}

void printArr(int* arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);  
    }
    printf("\n");
}

void sortStackFromBottom(heap* st, int i)
{
    int prev;
    if (i % 2 == 0)
    {
        prev = (i - 2)/2;
    }
    else
    {
        prev = (i - 1)/2;
    }
    if(st->arr[i] > st->arr[prev] && prev >= 0)
    {
        int t = st->arr[i];
        st->arr[i] = st->arr[prev];
        st->arr[prev] = t;
        if (i % 2 == 0)
        {
            prev = (i - 2)/2;
        }
        else
        {
            prev = (i - 1)/2;
        }
        sortStackFromBottom(st, prev);
    }
}

void sortStackFromTop(heap* st, int i)
{
    int right = i * 2 + 2;
    int left = i * 2 + 1;
    if (right < st->len && st->arr[right] > st->arr[i] && st->arr[right] > st->arr[left])
    {
        int t = st->arr[i];
        st->arr[i] = st->arr[right];
        st->arr[right] = t;
        sortStackFromTop(st, right);
    }
    else if (left < st->len && st->arr[left] > st->arr[i])
    {
        int t = st->arr[i];
        st->arr[i] = st->arr[left];
        st->arr[left] = t;
        sortStackFromTop(st, left);   
    }
}

int* createSortedArrayFromStack(heap* st)
{
    int* arr = malloc(sizeof(int) * (st->len));
    int length = st->len;
    for (int i = 0; i < length; i++)
    {
        arr[i] = popRootFromStack(st);
        sortStackFromTop(st, 0);
    }
    return arr;
    
}

int popRootFromStack(heap* st)
{
    int root = st->arr[0];
    st->arr[0] = st->arr[st->len - 1];
    st->len -= 1;
    return root;
}

int* heapSort(int* arr, int len)
{
    heap* st = createStackFromArray(arr, len);
    int* sortedArr = createSortedArrayFromStack(st);
    return sortedArr;
}

void heapSortInArray(window* wind, int* arr, int len)
{
    heap* st = malloc(sizeof(heap));
    st->arr = arr;
    st->len = len;
    createStackInArray(wind, st);
    sortArrayInArray(wind, st);
}

void createStackInArray(window* wind, heap* st)
{
    float max = getmax(st->arr, st->len);
    for (int i = 0; i < st->len; i++)
    {
        sortStackFromBottom(st, i);
        displayArr(wind, st->arr, st->len, max);
    }
}

void sortArrayInArray(window* wind, heap* st)
{
    int len = st->len;
    float max = getmax(st->arr, st->len);
    for (int i = 0; i < len - 1; i++)
    {
        int t = st->arr[0];
        st->arr[0] = st->arr[len - 1 - i];
        st->arr[len - 1 - i] = t;
        st->len--;
        sortStackFromTop(st, 0);
        displayArr(wind, st->arr, len, max);
    }
}