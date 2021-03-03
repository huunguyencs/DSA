#include "sort.h"

template <typename T>
void recursiveMergeSort(T *&, int, int);

template <typename T>
void merge(T *&, int, int, int);

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
    merge_sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

template <typename T>
void merge(T *&arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    // Get the left array
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    // Get the right array
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    // Merge two list
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Get the remaining elements of left array
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Get the remaining elements of right array
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void recursiveMergeSort(T *&arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int middle = l + (r - l) / 2;
    recursiveMergeSort(arr, l, middle);
    recursiveMergeSort(arr, middle + 1, r);
    merge(arr, l, middle, r);
    
}

template <typename T>
void merge_sort(T *&arr, int size)
{
    recursiveMergeSort(arr, 0, size - 1);
}



