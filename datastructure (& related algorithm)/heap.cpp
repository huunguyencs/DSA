#include <iostream>
using namespace std;

const int MAX_HEAP_SIZE = 10000;

template <typename T>
class Heap{
    T* heap;
    int size;
public:
    Heap(){
        this->heap = new T();
        size = 0;
    }
    Heap(T* array, int size){
        this->heap = array;
        this->size = size;
        buildHeap();
    }
    void reheapUp(int);
    void reheapDown(int);
    void buildHeap();
    bool insert(T);
    bool remove(T&);
    void print(){
        for (int i = 0; i < size; i++)
        {
            cout<<heap[i]<<" ";
        }
        cout<<endl;
    }

};

template <typename T>
void swap_arr(T &a, T&b){
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void Heap<T>::reheapUp(int position){
    if(position > 0){
        int parent = (position - 1) / 2;
        if(this->heap[position] > this->heap[parent]){
            swap_arr(this->heap[position],this->heap[parent]);
            reheapUp(parent);
        }
    }
}

template <typename T>
void Heap<T>::reheapDown(int position){
    int lastPosition = this->size - 1;
    int leftChild = position*2 + 1;
    int rightChild = position*2 + 2;
    int largeChild;
    if(leftChild <= lastPosition){
        if((rightChild <= lastPosition) && (heap[rightChild] > heap[leftChild]))
            largeChild = rightChild;
        else
            largeChild = leftChild;
        if(this->heap[largeChild] > this->heap[position]){
            swap_arr(this->heap[largeChild],this->heap[position]);
            reheapDown(largeChild);
        }
    }
}

template <typename T>
void Heap<T>::buildHeap(){
    int walker = this->size/2-1;
    while(walker >= 0){
        reheapDown(walker);
        walker--;
    }
}

template <typename T>
bool Heap<T>::insert(T data){
    if(size - 1 >= MAX_HEAP_SIZE)
        return false;
    heap[this->size] = data;
    reheapUp(this->size);
    this->size++;
    return true;
}

template <typename T>
bool Heap<T>::remove(T& dataOut){
    if (this->size - 1 <= 0)
        return false;
    dataOut = heap[0];
    heap[0] = heap[size - 1];
    size--;
    reheapDown(size - 1);
    return true;
}


int main(int argc, char const *argv[])
{
    int *x = new int[10]{1,7,8,9,4,6,5,10,0,-1};
    Heap<int>* h = new Heap<int>(x,10);
    h->print();

    return 0;
}
