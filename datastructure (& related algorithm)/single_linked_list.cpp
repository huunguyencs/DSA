// Definition
// - A linked list is an ordered collection of data in which
// each element contains the location of the next element.
// - The elements in a linked list are call nodes. A node in a
// linked list is a structure that has at least two fields:
// the data and the address of the next node.

#include <iostream>

using namespace std;

const int MAX_SIZE_LIST = 100;


template <class ItemType>
class Node{
    ItemType data;
    Node<ItemType> *next;

public:
    Node(ItemType data){
        this->data = data;
        this->next = nullptr;
    }

    Node(ItemType data, Node<ItemType>* next){
        this->data = data;
        this->next = next;
    }
    ~Node(){

    }
    ItemType getData(){
        return this->data;
    }
    void setData(ItemType data){
        this->data = data;
    }
    Node<ItemType>* getNext(){
        return this->next;
    }
    void setNext(Node<ItemType> *next){
        this->next = next;
    }
};

template <class ItemType>
class LinkedList{
    Node<ItemType> *head;
    int count;
public:
    LinkedList(){
        this->head = nullptr;
        this->count = 0;
    }
    LinkedList(Node<ItemType>* head){
        this->head = head;
        this->count = 1;
    }
    ~LinkedList(){

    }
    bool insert(ItemType data, int pos = -1){
        pos = pos==-1?this->count:pos;
        if(this->isFull()){
            cout<<"List is full."<<endl;
            return false;
        }
        if(this->isEmpty() || pos == 0){
            Node<ItemType> *head = this->head;
            this->head = new Node<ItemType>(data,head);
        }
        else{
            int i = 0;
            Node<ItemType>* temp = this->head;
            while(i < this->count - 1 && i < pos - 1){
                temp = temp->getNext();
                i++;
            }
            Node<ItemType> *curr = new Node<ItemType>(data,temp->getNext());
            temp->setNext(curr);
        }
        this->count++;
        return true;

    }
    bool remove(ItemType data){
        if(this->isEmpty()){
            cout<<"List is empty."<<endl;
            return false;
        }
        
        if(this->head->getData() == data) {
            Node<ItemType> *head = this->head;
            this->head = head->getNext();
            this->count--;
            delete head;
            return true;
        }
        Node<ItemType> *curr = this->head;
        Node<ItemType> *pre = curr;
        while(curr->getData() != data && curr->getNext() != nullptr){
            pre = curr;
            curr = curr->getNext();
        }
        if(curr->getData() == data){
            pre->setNext(curr->getNext());
            delete curr;
            this->count--;
            return true;
        }
        cout<<"Not found "<<data<<endl;
        return false;
    }
    bool reverse(){
        Node<ItemType> *pre = nullptr;
        Node<ItemType> *curr = this->head;
        Node<ItemType> *next = nullptr;
        while(curr!=nullptr){
            next = curr->getNext();
            curr->setNext(pre);
            pre = curr;
            curr = next;
        }
        this->head = pre;
        return true;
    }
    Node<ItemType>* search(ItemType data){
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
    void print(){
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
    int getSize(){
        return this->count;
    }
    Node<ItemType> getHead(){
        return this->head;
    }
    bool isEmpty(){
        return this->count == 0;
    }
    bool isFull(){
        return this->count >= MAX_SIZE_LIST;
    }
};

// int main(int argc, char const *argv[])
// {
//     LinkedList<int> *list = new LinkedList<int>();
//     Node<int>* t;
//     list->insert(5);
//     list->insert(7);
//     list->print();
//     list->insert(9);
//     list->insert(10);
//     list->print();
//     list->insert(10,10);
//     t = list->search(5);
//     cout<< t->getData()<<endl;
//     list->reverse();
//     list->print();
//     return 0;
// }
