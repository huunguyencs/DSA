// Definition:
// - A queue of elements of type T is a finite sequence of elements of T,
// in which data can only be inserted at one end called the rear, and
// deleted from the other end called the front.
// - Queue is a First In - First Out (FIFO) data structure.
// (FIFO: The first item stored in the queue is the first item that can be
// taken out.)

#include "list.h"

template <class ItemType>
class Queue : public List<ItemType>{
    Node<ItemType> *tail;
public:
    Queue(Node<ItemType>* head = nullptr) : List<ItemType>(head){
        this->tail = head;
    }
    ~Queue() {}
    ItemType dequeue(){
        if(this->isEmpty()){
            cout<<"Queue is empty.\n";
            return (ItemType)NULL;
        }
        Node<ItemType>* head = this->head;
        this->head = head->getNext();
        this->count--;
        return head->getData();
    }
    bool enqueue(ItemType data){
        if(this->isFull()){
            cout<<"Queue is full.\n";
            return false;
        }
        if(this->isEmpty()){
            this->head = new Node<ItemType>(data);
            this->tail = this->head;
        }
        else{
            Node<ItemType> *tail = new Node<ItemType>(data);
            this->tail->setNext(tail);
            this->tail = tail;
        }
        this->count++;
        return true;

    }
    Node<ItemType> *getQueueFront(){
        return List<ItemType>::getHead();
    }
    Node<ItemType> * getQueueRear(){
        return this->tail;
    }
};

// int main(int argc, char const *argv[])
// {
//     Queue<int> * queue = new Queue<int>();
//     queue->enqueue(7);
//     queue->enqueue(8);
//     queue->enqueue(12);
//     queue->print();
//     queue->dequeue();
//     queue->print();
//     return 0;
// }

