// Definition: A binary tree is either empty, or it consists of a node
// called root together with two binary trees called the left and the
// right subtree of the root.

#include <iostream>

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

using namespace std;

template <typename ItemType>
class Node{
    ItemType data;
    Node<ItemType>* left;
    Node<ItemType>* right;
public:
    Node(ItemType data, Node<ItemType>* left = nullptr, Node<ItemType>* right = nullptr){
        this->data = data;
        this->left = left;
        this->right = right;
    }
    ~Node() {}
    void setData(ItemType data){
        this->data = data;
    }
    ItemType getData(){
        return this->data;
    }
    void setLeft(Node<ItemType>* left){
        this->left = left;
    }
    void setRight(Node<ItemType>* right){
        this->right = right;
    }
    Node<ItemType>* getLeft(){
        return this->left;
    }
    Node<ItemType>* getRight(){
        return this->right;
    }
};

template <typename ItemType>
class BinaryTree{
protected:
    Node<ItemType>* root;
public:
    BinaryTree(Node<ItemType>* root = nullptr){
        this->root = root;
    }
    ~BinaryTree() {}
    void infix(Node<ItemType>* root, void(*func)(Node<ItemType>*)){
        if(root == nullptr){
            return;
        }
        infix(root->getLeft(), func);
        func(root);
        infix(root->getRight(), func);
    }
    void prefix(Node<ItemType>* root, void(*func)(Node<ItemType>*)){
        if(root == nullptr){
            return;
        }
        func(root);
        prefix(root->getLeft(), func);
        prefix(root->getRight(), func);
    }
    void postfix(Node<ItemType>* root, void(*func)(Node<ItemType>*)){
        if(root == nullptr){
            return;
        }
        postfix(root->getLeft(), func);
        postfix(root->getRight(), func);
        func(root);
    }
    bool isEmpty(){
        return this->root == nullptr;
    }
    Node<ItemType>* getRoot(){
        return this->root;
    }
};

#endif

// template <typename T>
// void print(Node<T>* t){
//     cout<<t->getData()<<" ";
// }

// int main(int argc, char const *argv[])
// {

//     Node<int>* a1 = new Node<int>(11);
//     Node<int>* a2 = new Node<int>(15);
//     Node<int>* a3 = new Node<int>(6,a1,a2);
//     Node<int>* a4 = new Node<int>(19);
//     Node<int>* a5 = new Node<int>(17,a3,a4);
//     BinaryTree<int>* tree = new BinaryTree<int>(a5);
//     tree->postfix(tree->getRoot(), print<int>);
//     return 0;
// }
