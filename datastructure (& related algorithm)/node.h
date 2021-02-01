#include <iostream>
using namespace std;

#ifndef NODE_H
#define NODE_H

template <typename ItemType>
class Node{
    ItemType data;
    Node<ItemType> * next;
public:
    Node(ItemType, Node<ItemType>* next = nullptr);
    ~Node();
    ItemType getData();
    void setData(ItemType);
    Node<ItemType> *getNext();
    void setNext(Node<ItemType>*);
};

template <typename ItemType>
Node<ItemType>::Node(ItemType data, Node<ItemType> *next){
    this->data = data;
    this->next = next;
}

template <typename ItemType>
void Node<ItemType>::setData(ItemType data){
    this->data = data;
}

template <typename ItemType>
ItemType Node<ItemType>::getData(){
    return this->data;
}

template <typename ItemType>
Node<ItemType> *Node<ItemType>::getNext(){
    return this->next;
}

template <typename ItemType>
void Node<ItemType>::setNext(Node<ItemType> *next){
    this->next = next;
}

#endif