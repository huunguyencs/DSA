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
    bubbleSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

template <typename T>
void bubbleSort(T *&arr, int size)
{
    int current = 0;
    bool flag = false;
    while((current < size) && (flag == false)){
        int walker = size - 1;
        flag = true;
        while(walker > current){
            if (arr[walker] < arr[walker - 1])
            {
                flag = false;
                swapArr(arr[walker], arr[walker - 1]);
            }
            walker = walker - 1;
        }
        current = current + 1;        
    }    
}