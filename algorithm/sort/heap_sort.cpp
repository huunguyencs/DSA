#include "sort.h"

int main(int argc, char const *argv[])
{
    int size;
    cout << "Input size of array: ";
    cin >> size;
    int *arr = new int(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    heap_sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

template <typename T>
void reheap_down(T *&arr, int position, int lastPosition)
{
    int leftChild = position * 2 + 1;
    int rightChild = position * 2 + 2;
    int largeChild;
    if (leftChild <= lastPosition)
    {
        if ((rightChild <= lastPosition) && (arr[rightChild] > arr[leftChild]))
            largeChild = rightChild;
        else
            largeChild = leftChild;
        if (arr[largeChild] > arr[position])
        {
            swap_arr(arr[largeChild], arr[position]);
            reheap_down(arr, largeChild, lastPosition);
        }
    }
}


template <typename T>
void heap_sort(T *&arr, int size)
{
    int position = int(size / 2) - 1;
    while (position >= 0)
    {
        reheap_down(arr, position, size - 1);
        position--;
    }   
    int last = size - 1;
    while (last > 0)
    {
        swap_arr(arr[0], arr[last]);
        reheap_down(arr, 0, last - 1);
        last--;
 
    }
}

