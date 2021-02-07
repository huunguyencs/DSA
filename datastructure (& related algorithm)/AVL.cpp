// Definition: AVL Tree is:
// - A Binary Search Tree,
// - in which the heights of the left and right subtrees of the root
// differ by at most 1, and
// - the left and right subtrees are again AVL trees.
// Discovered by G.M.Adel'son-Vel'skii and E.M.Landis in 1962
// -> AVL Tree is a Binary Search Tree that is balanced tree.

#include "AVL.h"

template <typename ItemType>
NodeAVL<ItemType> *AVLTree<ItemType>::rotateRight(NodeAVL<ItemType> *&subroot)
{
    NodeAVL<ItemType> *tmpPtr = subroot->getLeft();
    subroot->setLeft(tmpPtr->getRight());
    tmpPtr->setRight(subroot);
    return tmpPtr;
}

template <typename ItemType>
NodeAVL<ItemType> *AVLTree<ItemType>::rotateLeft(NodeAVL<ItemType> *&subroot)
{
    NodeAVL<ItemType> *tmpPtr = subroot->getRight();
    subroot->setRight(tmpPtr->getLeft());
    tmpPtr->setLeft(subroot);
    return tmpPtr;
}

template <typename ItemType>
NodeAVL<ItemType> *AVLTree<ItemType>::insertAVL(NodeAVL<ItemType> *&subroot, ItemType data, bool &taller)
{
    if (subroot == nullptr)
    {
        subroot = new NodeAVL<ItemType>(data);
        taller = true;
        return subroot;
    }
    if (data < subroot->getData())
    {
        subroot->setLeft(insertAVL(subroot->refLeft(), data, taller));
        if (taller)
        {
            if (subroot->getBalance() == LH)
            {
                subroot = leftBalance(subroot, taller);
            }
            else if (subroot->getBalance() == EH)
            {
                subroot->setBalance(LH);
            }
            else
            {
                subroot->setBalance(EH);
                taller = false;
            }
        }
    }
    else
    {
        subroot->setRight(insertAVL(subroot->refRight(), data, taller));
        if (taller)
        {
            if (subroot->getBalance() == LH)
            {
                subroot->setBalance(EH);
                taller = false;
            }
            else if (subroot->getBalance() == EH)
            {
                subroot->setBalance(RH);
            }
            else
            {
                subroot = rightBalance(subroot, taller);
            }
        }
    }
    return subroot;
}

template <typename ItemType>
NodeAVL<ItemType> *AVLTree<ItemType>::leftBalance(NodeAVL<ItemType> *&subroot, bool &taller)
{
    NodeAVL<ItemType> *leftTree = subroot->getLeft();
    if (leftTree->getBalance() == LH)
    {
        subroot = rotateRight(subroot);
        subroot->setBalance(EH);
        leftTree->setBalance(EH);
        taller = false;
    }
    else
    {
        NodeAVL<ItemType> *rightTree = leftTree->getRight();
        if (rightTree->getBalance() == LH)
        {
            subroot->setBalance(RH);
            leftTree->setBalance(EH);
        }
        else if (rightTree->getBalance() == EH)
        {
            leftTree->setBalance(EH);
        }
        else
        {
            subroot->setBalance(EH);
            leftTree->setBalance(LH);
        }
        rightTree->setBalance(EH);
        subroot->setLeft(rotateLeft(leftTree));
        subroot = rotateRight(subroot);
        taller = false;
    }
    return subroot;
}

template <typename ItemType>
NodeAVL<ItemType> *AVLTree<ItemType>::removeAVL(NodeAVL<ItemType> *&subroot, ItemType data, bool &shorter, bool &success)
{
    if (subroot == nullptr)
    {
        shorter = false;
        success = false;
        return nullptr;
    }
    if (data < subroot->getData())
    {
        subroot->setLeft(removeAVL(subroot->refLeft(), data, shorter, success));
        if (shorter)
        {
            subroot = removeRightBalance(subroot, shorter);
        }
    }
    else if (data > subroot->getData())
    {
        subroot->setRight(removeAVL(subroot->refRight(), data, shorter, success));
        if (shorter)
        {
            subroot = removeLeftBalance(subroot, shorter);
        }
    }
    else
    {
        NodeAVL<ItemType> *delNode = subroot;
        if (subroot->getRight() == nullptr)
        {
            NodeAVL<ItemType> *newRoot = subroot->getLeft();
            success = true;
            shorter = true;
            delete delNode;
            return newRoot;
        }
        else if (subroot->getLeft() == nullptr)
        {
            NodeAVL<ItemType> *newRoot = subroot->getRight();
            success = true;
            shorter = true;
            delete delNode;
            return newRoot;
        }
        else
        {
            NodeAVL<ItemType> *exchPtr = subroot->getLeft();
            while (exchPtr->getRight() != nullptr)
            {
                exchPtr = exchPtr->getRight();
            }
            subroot->setData(exchPtr->getData());
            subroot->setLeft(remove(subroot->refLeft(), exchPtr->getData(), shorter, success));
            if (shorter)
            {
                subroot = removeRightBalance(subroot, shorter);
            }
        }
    }
    return subroot;
}

template <typename ItemType>
NodeAVL<ItemType> *AVLTree<ItemType>::rightBalance(NodeAVL<ItemType> *&subroot, bool &taller)
{
    NodeAVL<ItemType> *rightTree = subroot->getRight();
    if (rightTree->getBalance() == RH)
    {
        subroot = rotateLeft(subroot);
        subroot->setBalance(EH);
        rightTree->setBalance(EH);
        taller = false;
    }
    else
    {
        NodeAVL<ItemType> *leftTree = rightTree->getLeft();
        if (leftTree->getBalance() == RH)
        {
            subroot->setBalance(LH);
            rightTree->setBalance(EH);
        }
        else if (leftTree->getBalance() == EH)
        {
            rightTree->setBalance(EH);
        }
        else
        {
            subroot->setBalance(EH);
            rightTree->setBalance(RH);
        }
        leftTree->setBalance(EH);
        subroot->setRight(rotateRight(rightTree));
        subroot = rotateLeft(subroot);
        taller = false;
    }
    return subroot;
}

template <typename ItemType>
NodeAVL<ItemType> *AVLTree<ItemType>::removeRightBalance(NodeAVL<ItemType> *&subroot, bool &shorter)
{
    if (subroot->getBalance() == LH)
    {
        subroot->setBalance(EH);
    }
    else if (subroot->getBalance(EH))
    {
        subroot->setBalance(RH);
        shorter = false;
    }
    else
    {
        NodeAVL<ItemType> *rightTree = subroot->getRight();
        if (rightTree->getBalance() == LH)
        {
            NodeAVL<ItemType> *leftTree = rightTree->getLeft();
            if (leftTree->getBalance() == LH)
            {
                rightTree->setBalance(RH);
                subroot->setBalance(EH);
            }
            else if (leftTree->getBalance() == EH)
            {
                subroot->setBalance(LH);
                rightTree->setBalance(EH);
            }
            else
            {
                subroot->setBalance(LH);
                rightTree->setBalance(EH);
            }
            leftTree->setBalance(EH);
            subroot->getRight(rotateRight(rightTree));
        }
        else
        {
            if (rightTree->getBalance() != EH)
            {
                subroot->setBalance(EH);
                rightTree->setBalance(EH);
            }
            else
            {
                subroot->setBalance(RH);
                rightTree->setBalance(LH);
                shorter = false;
            }
            subroot = rotateLeft(subroot);
        }
    }
    return subroot;
}

template <typename ItemType>
NodeAVL<ItemType> *AVLTree<ItemType>::removeLeftBalance(NodeAVL<ItemType> *&subroot, bool &shorter)
{
    if (subroot->getBalance() == RH)
    {
        subroot->setBalance(EH);
    }
    else if (subroot->getBalance(EH))
    {
        subroot->setBalance(LH);
        shorter = false;
    }
    else
    {
        NodeAVL<ItemType> *leftTree = subroot->getLeft();
        if (leftTree->getBalance() == RH)
        {
            NodeAVL<ItemType> rightTree = leftTree->getRight();
            if (rightTree->getBalance() == RH)
            {
                leftTree->setBalance(LH);
                subroot->setBalance(EH);
            }
            else if (rightTree->getBalance() == EH)
            {
                subroot->setBalance(RH);
                leftTree->setBalance(EH);
            }
            else
            {
                subroot->setBalance(RH);
                leftTree->setBalance(EH);
            }
            rightTree->setBalance(EH);
            subroot->setLeft(rotateLeft(leftTree));
        }
        else
        {
            if (leftTree->getBalance() != EH)
            {
                subroot->setBalance(EH);
                leftTree->setBalance(EH);
            }
            else
            {
                subroot->setBalance(LH);
                leftTree->setBalance(RH);
                shorter = false;
            }
            subroot = rotateRight(subroot);
        }
    }
    return subroot;
}

int main(int argc, char const *argv[])
{
    AVLTree<int> *tree = new AVLTree<int>();
    tree->insert(5);
    tree->insert(7);
    tree->insert(3);
    tree->insert(8);
    tree->insert(2);
    return 0;
}
