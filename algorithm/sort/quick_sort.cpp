#include "sort.h"

template <typename T>
int partition(T *&arr, int l, int r);

template <typename T>
void recursiveQuickSort(T *&arr, int l, int r);

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
    quick_sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    return 0;
}

template <typename T>
int partition(T *&arr, int l, int r)
{
    int pivot = arr[r];
    int storeIndex = l;
    for (int i = l; i < r; i++)
    {
        if (arr[i] < pivot)
        {
            swap_arr(arr[i], arr[storeIndex]);
            storeIndex++;
        }

    }
    swap_arr(arr[storeIndex], arr[r]);
    return storeIndex;
    
}

template <typename T>
void recursiveQuickSort(T *&arr, int l, int r)
{
    if (l >= r)
        return;
    int pivot = partition(arr, l, r);
    recursiveQuickSort(arr, l, pivot - 1);
    recursiveQuickSort(arr, pivot + 1, r);
}

template <typename T>
void quick_sort(T *&arr, int size)
{
    recursiveQuickSort(arr, 0, size - 1);
}