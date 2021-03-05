// Definition: AVL Tree is:
// - A Binary Search Tree,
// - in which the heights of the left and right subtrees of the root
// differ by at most 1, and
// - the left and right subtrees are again AVL trees.
// Discovered by G.M.Adel'son-Vel'skii and E.M.Landis in 1962
// -> AVL Tree is a Binary Search Tree that is balanced tree.

#include <iostream>
using namespace std;


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
    int getBalance();
    void setBalance(int b);
    ItemType getData();
    void setData(ItemType data);
    NodeAVL<ItemType>* getLeft();
    NodeAVL<ItemType>* getRight();
    void setLeft(NodeAVL<ItemType> *left);
    void setRight(NodeAVL<ItemType> *right);
    NodeAVL<ItemType>* &refLeft();
    NodeAVL<ItemType>* &refRight();
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
    AVLTree(NodeAVL<ItemType>* root = nullptr)
    {
        this->root = root;
    }
    bool insert(ItemType data);
    bool remove(ItemType data);
};
