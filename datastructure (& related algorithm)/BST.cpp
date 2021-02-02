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
    Node<ItemType>* getParent(Node<ItemType>*, ItemType);
    bool insert(Node<ItemType>*, ItemType);
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
        return insert(this->root, data);
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
    if(subroot == nullptr) return nullptr;
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
Node<ItemType>* BinarySearchTree<ItemType>::getParent(Node<ItemType>* subroot, ItemType data){
    if(subroot == nullptr) return nullptr;
    if(subroot->getLeft()->getData() == data || subroot->getRight()->getData() == data){
        return subroot;
    }
    ItemType rootData = subroot->getData();
    if(rootData > data){
        return getParent(subroot->getLeft(), data);
    }
    if(rootData < data){
        return getParent(subroot->getRight(), data);
    }
}

template <typename ItemType>
bool BinarySearchTree<ItemType>::insert(Node<ItemType>* subroot, ItemType data){
    return false;
}

template <typename ItemType>
bool BinarySearchTree<ItemType>::remove(Node<ItemType>* subroot, ItemType data){
    return false;
}