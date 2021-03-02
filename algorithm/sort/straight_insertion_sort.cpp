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
    straight_insertion_sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

template <typename T>
void straight_insertion_sort(T *&arr, int size)
{
    if (size > 1)
    {
        int current = 1;
        while (current < size)
        {
            T tmp = arr[current];
            int walker = current - 1;
            while (walker >= 0 && tmp < arr[walker])
            {
                arr[walker + 1] = arr[walker];
                walker--;
            }
            arr[walker + 1] = tmp;
            current++;
        }
    }
}