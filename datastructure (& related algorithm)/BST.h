#include "binary_tree.h"

template <typename ItemType>
class BinarySearchTree : public BinaryTree<ItemType> {
    Node<ItemType>* smallest(Node<ItemType>*);
    Node<ItemType>* largest(Node<ItemType>*);
    Node<ItemType>* search(Node<ItemType>*, ItemType);
    void insertBST(ItemType);
    bool remove(Node<ItemType>* &, ItemType);
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
            Node<ItemType>* &rRoot = this->root;
            insertBST(data);
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