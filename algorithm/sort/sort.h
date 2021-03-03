#include <iostream>
using namespace std;

#ifndef SORT_H
#define SORT_H

template <typename T>
void bubble_sort(T *&, int);

template <typename T>
void quick_sort(T *&, int);

template <typename T>
void heap_sort(T *&, int);

template <typename T>
void straight_insertion_sort(T *&, int);

template <typename T>
void merge_sort(T *&, int);

template <typename T>
void straight_selection_sort(T *&, int);

template <typename T>
void swap_arr(T &a, T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}


#endif