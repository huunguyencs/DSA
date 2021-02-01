// Definition
// - A linked list is an ordered collection of data in which
// each element contains the location of the next element.
// - The elements in a linked list are call nodes. A node in a
// linked list is a structure that has at least two fields:
// the data and the address of the next node.

#include "list.h"

template <class ItemType>
class LinkedList : public List<ItemType> {
public:
    LinkedList(Node<ItemType>* head = nullptr) : List<ItemType>(head) {}
    ~LinkedList() {}
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
