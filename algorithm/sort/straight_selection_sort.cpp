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
    straight_selection_sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

template <typename T>
void straight_selection_sort(T *&arr, int size)
{
    int current = 0;
    while (current < size - 1)
    {
        int smallest = current;
        int walker = current + 1;
        while (walker < size)
        {
            if (arr[walker] < arr[smallest])
                smallest = walker;
            walker = walker + 1;
        }
        swapArr(arr[current], arr[smallest]);
        current++;
    }
}