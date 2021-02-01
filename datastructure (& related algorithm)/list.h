# include "node.h"

#ifndef LIST_H
#define LIST_H

const int MAX_SIZE = 1000;

template <typename ItemType>
class List {
protected:
    Node<ItemType> *head;
    uint32_t count;    
public:
    List(Node<ItemType>* head = nullptr);
    ~List() {}
    bool isEmpty();
    bool isFull();
    void print();
    Node<ItemType> *getHead();
    uint32_t getSize();
    Node<ItemType> *search(ItemType);
    
};

template <typename ItemType>
List<ItemType>::List(Node<ItemType>* head){
    this->head = head;
    this->count = head == nullptr?0:1;
}

template <typename ItemType>
bool List<ItemType>::isEmpty(){
    return this->count == 0;
}

template <typename ItemType>
bool List<ItemType>::isFull(){
    return this->count >= MAX_SIZE;
}

template <typename ItemType>
void List<ItemType>::print(){
    Node<ItemType> *run = this->head;
    cout<<"------------------------------------\nSize: "<<this->count<<"\nList: ";
    bool flag = true;
    while(run != nullptr){
        if(flag) flag = false;
        else cout<<"->";
        cout<<run->getData();
        run = run->getNext();
    }
    cout<<"\n------------------------------------\n";
}

template <typename ItemType>
Node<ItemType> *List<ItemType>::getHead(){
    return this->head;
}

template <typename ItemType>
uint32_t List<ItemType>::getSize(){
    return this->count;
}

template <typename ItemType>
Node<ItemType> *List<ItemType>::search(ItemType data){
    Node<ItemType> *run = this->head;
    while(run != nullptr && run->getData() != data){
        run = run->getNext();
    }
    if(run->getData() == data){
        return run;
    }
    cout<<"Not found "<<data<<endl;
    return nullptr;
}

#endif