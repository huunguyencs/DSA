// Definition
// - A stack of elements of type T is a finite sequence of elements of T,
// in which all insertions and deletions are restricted to one end, called
// the top.
// - Stack is a Last In - First Out (LIFO) data structure.
// (LIFO: The last item put on the stack is the first item that can be taken off.)


#include "list.h"


template <class ItemType>
class Stack : public List<ItemType>{
public:
    Stack(Node<ItemType> *top = nullptr) : List<ItemType>(top){}
    ~Stack() {}
    bool push(ItemType data){
        if(this->isFull()){
            cout<<"Stack is full.\n";
            return false;
        }
        Node<ItemType> *top = this->head;
        this->head = new Node<ItemType>(data, top);
        this->count++;
        return true;
    }
    ItemType pop(){
        if(this->isEmpty()){
            cout<<"Stack is empty.\n";
            return (ItemType)NULL;
        }
        Node<ItemType> *top = this->head;
        this->head = top->getNext();
        ItemType dat = top->getData();
        this->count--;
        return dat;
    }
    Node<ItemType>* getTopStack(){
        return List<ItemType>::getHead();
    }
};

// int main(int argc, char const *argv[])
// {
//     Stack<int> *stack = new Stack<int>();
//     stack->push(7);
//     stack->push(9);
//     stack->push(10);
//     stack->print();
//     stack->pop();
//     stack->print();
//     stack->push(5);
//     stack->print();
//     return 0;
// }
