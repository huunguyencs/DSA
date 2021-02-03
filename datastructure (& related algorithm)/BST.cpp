// Definition: A binary search tree (BST) is a binary tree with the
// following properties:
// 1. All items in the left subtree are less than the root.
// 2. All items in the right subtree are greater than or equal to the
// root.
// 3. Each subtree is itself a binary search tree.

#include "binary_tree.h"

template <typename ItemType>
class BinarySearchTree : public BinaryTree<ItemType> {
    Node<ItemType>* smallest(Node<ItemType>*);
    Node<ItemType>* largest(Node<ItemType>*);
    Node<ItemType>* search(Node<ItemType>*, ItemType);
    void insert(Node<ItemType>*, ItemType);
    bool remove(Node<ItemType>*, ItemType);
public:
    Node<ItemType>* smallest(){
        if(this->isEmpty()) return nullptr;
        return smallest(this->root);
    }
    Node<ItemType>* largest(){
        if(this->isEmpty()) return nullptr;
        return largest(this->root);
    }
    Node<ItemType>* search(ItemType data){
        return search(this->root, data);
    }
    bool insert(ItemType data){
        try {
            insert(this->root, data);
            return true;
        }
        catch(const char* msg){
            cout<<"Can not insert.\n";
            cerr<<msg<<endl;
            return false;
        }
    }
    bool remove(ItemType data){
        if(this->isEmpty()) return false;
        return remove(this->root, data);
    }
};

template <typename ItemType>
Node<ItemType>* BinarySearchTree<ItemType>::smallest(Node<ItemType>* subroot){
    if(subroot->getLeft() == nullptr){
        return subroot->getData();
    }
    return smallest(subroot->getLeft());
}

template <typename ItemType>
Node<ItemType>* BinarySearchTree<ItemType>::largest(Node<ItemType>* subroot){
    if(subroot->getRight() == nullptr){
        return subroot->getData();
    }
    return largest(subroot->getRight());
}

template <typename ItemType>
Node<ItemType>* BinarySearchTree<ItemType>::search(Node<ItemType>* subroot, ItemType data){
    if(subroot == nullptr){
        cout<<data<<" is not exist.\n";
        return nullptr;
    }
    ItemType rootData = subroot->getData();
    if(rootData > data){
        return search(subroot->getLeft(),data);
    }
    if(rootData < data){
        return search(subroot->getRight(), data);
    }
    return subroot;
}

template <typename ItemType>
void BinarySearchTree<ItemType>::insert(Node<ItemType>* subroot, ItemType data){
    if (subroot == nullptr) {
        subroot = new Node<ItemType>(data);
    }
    ItemType rootData = subroot->getData();
    if(rootData > data){
        insert(subroot->getLeft(), data);
    }
    if(rootData < data){
        insert(subroot->getRight(), data);
    }
}

template <typename ItemType>
bool BinarySearchTree<ItemType>::remove(Node<ItemType>* subroot, ItemType data){
    if(subroot == nullptr) return false;
    ItemType rootData = subroot->getData();
    if(rootData > data){
        return remove(subroot->getLeft(), data);
    }
    else if(rootData < data){
        return remove(subroot->getRight(), data);
    }
    else{
        if(subroot->getLeft() == nullptr){
            Node<ItemType>* delPtr = subroot;
            subroot = subroot->getRight();
            delete delPtr;
            return true;
        }
        else if(subroot->getRight() == nullptr){
            Node<ItemType>* delPtr = subroot;
            subroot = subroot->getLeft();
            delete delPtr;
            return true;
        }
        else{
            Node<ItemType>* delPtr = subroot->getLeft();
            while(delPtr->getRight()!=nullptr){
                delPtr = delPtr->getRight();
            }
            subroot->setData(delPtr->getData());
            return remove(subroot->getLeft(),delPtr->getData());
        }
    }
}

template <typename T>
void print(Node<T>* t){
    cout<<t->getData()<<" ";
}

int main(int argc, char const *argv[])
{
    BinarySearchTree<int>* bst = new BinarySearchTree<int>();
    bst->insert(5);
    bst->insert(7);
    bst->insert(8);
    bst->insert(3);
    bst->infix(bst->getRoot(),print<int>);
    return 0;
}
