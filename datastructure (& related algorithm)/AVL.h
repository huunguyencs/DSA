#include <iostream>
using namespace std;

#ifndef AST_H
#define AST_H

int const LH = -1;
int const EH = 0;
int const RH = 1;

template <typename ItemType>
class NodeAVL
{
    ItemType data;
    NodeAVL<ItemType> *left;
    NodeAVL<ItemType> *right;
    int balance;
public:
    NodeAVL(ItemType data, NodeAVL<ItemType> *left = nullptr, NodeAVL<ItemType> *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
        this->balance = EH;
    }
    int getBalance()
    {
        return this->balance;
    }
    void setBalance(int b)
    {
        this->balance = b;
    }
    ItemType getData(){
        return this->data;
    }
    void setData(ItemType data){
        this->data = data;
    }
    NodeAVL<ItemType>* getLeft(){
        return this->left;
    }
    NodeAVL<ItemType>* getRight(){
        return this->right;
    }
    void setLeft(NodeAVL<ItemType> *left){
        this->left = left;
    }
    void setRight(NodeAVL<ItemType> *right){
        this->right = right;
    }
    NodeAVL<ItemType>* &refLeft(){
        return this->left;
    }
    NodeAVL<ItemType>* &refRight(){
        return this->right;
    }
};

template <typename ItemType>
class AVLTree
{
    NodeAVL<ItemType> *root;
    NodeAVL<ItemType> *rotateRight(NodeAVL<ItemType> *&);
    NodeAVL<ItemType> *rotateLeft(NodeAVL<ItemType> *&);
    NodeAVL<ItemType> *insertAVL(NodeAVL<ItemType> *&, ItemType, bool &);
    NodeAVL<ItemType> *leftBalance(NodeAVL<ItemType> *&, bool &);
    NodeAVL<ItemType> *rightBalance(NodeAVL<ItemType> *&, bool &);
    NodeAVL<ItemType> *removeAVL(NodeAVL<ItemType> *&, ItemType, bool &, bool &);
    NodeAVL<ItemType> *removeRightBalance(NodeAVL<ItemType> *&, bool &);
    NodeAVL<ItemType> *removeLeftBalance(NodeAVL<ItemType> *&, bool &);

public:
    AVLTree(NodeAVL<ItemType>* root = nullptr){
        this->root = root;
    }
    bool insert(ItemType data)
    {
        try
        {
            bool taller = true;
            this->insertAVL(this->root, data, taller);
            return true;
        }
        catch (const char *msg)
        {
            cerr << msg << endl;
            return false;
        }
    }
    bool remove(ItemType data)
    {
        try
        {
            bool success = false;
            bool shorter = true;
            this->removeAVL(this->root, data, shorter, success);
            return success;
        }
        catch (const char *msg)
        {
            cerr << msg << endl;
            return false;
        }
    }
};

#endif