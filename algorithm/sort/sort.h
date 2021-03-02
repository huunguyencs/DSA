#include <iostream>
using namespace std;

#ifndef SORT_H
#define SORT_H

template <typename T>
void bubbleSort(T *&, int);

template <typename T>
void quickSort(T *&, int);

template <typename T>
void heapSort(T *&, int);

template <typename T>
void straight_insertion_sort(T *&, int);

template <typename T>
void mergeSort(T *&, int);

template <typename T>
void straight_selection_sort(T *&, int);

template <typename T>
void swapArr(T &a, T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}


#endif