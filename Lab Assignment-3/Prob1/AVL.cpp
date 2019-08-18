#include "tree.h"
#include <vector>
#include <iostream>

void AvlTree::insert(int data)
{
    insert(data, &root);
}
void AvlTree::rotateLeft(Node **node)
{
    Node *y = (*node)->right;
    Node *T2 = y->left;
    y->left = *node;
    (*node)->right = T2;
    (*node) = y;
}
void AvlTree::rotateRight(Node **node)
{
    Node *x = (*node)->left;
    Node *T2 = x->right;
    x->right = *node;
    (*node)->left = T2;
    (*node) = x;
}
void AvlTree::insert(int data, Node **node)
{
    if ((*node) == nullptr)
    {
        (*node) = new Node();
        (*node)->data = data;
        (*node)->left = NULL;
        (*node)->right = NULL;
        return;
    }
    if ((*node)->data > data)
        insert(data, &(*node)->left);
    else if ((*node)->data < data)
        insert(data, &(*node)->right);
    else
    {
        std::cout << "Data already present";
        return;
    }
    //RL rotation
    if (balanceFactor(*node) < -1 && (*node)->right->data > data)
    {
        rotateRight(&(*node)->right);
        rotateLeft(node);
    }
    // RR rotation
    else if (balanceFactor(*node) < -1 && (*node)->right->data < data)
        rotateLeft(node);
    // LR rotation
    else if (balanceFactor(*node) > 1 && (*node)->left->data < data)
    {
        rotateLeft(&(*node)->left);
        rotateRight(node);
    }
    // LL rotation
    else if (balanceFactor(*node) > 1 && (*node)->left->data > data)
        rotateRight(node);
}
AvlTree::AvlTree()
{
    root = NULL;
}
void AvlTree::inorderTraversal()
{
    traverseInorder(root);
}
void bstToArr(std::vector<int> &arr, Node *node)
{
    if (!node)
        return;
    bstToArr(arr, node->left);
    arr.push_back(node->data);
    bstToArr(arr, node->right);
}
Node *arrToAvl(std::vector<int> &arr, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (end + start) / 2;
    if (start == end)
        mid = start;
    Node *root = new Node();
    root->left = NULL;
    root->right = NULL;
    root->data = arr[mid];
    root->left = arrToAvl(arr, start, mid - 1);
    root->right = arrToAvl(arr, mid + 1, end);
    return root;
}
void AvlTree::BSTtoAVL(BST bst)
{
    std::vector<int> arr;
    bstToArr(arr, bst.root);
    root = arrToAvl(arr, 0, arr.size() - 1);
    std::cout << root->data;
}
