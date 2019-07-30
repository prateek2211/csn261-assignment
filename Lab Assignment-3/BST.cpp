#include "tree.h"
#include <iostream>
void BST::traverseInorder(Node *node)
{
    if (node == nullptr)
        return;
    traverseInorder(node->left);
    std::cout << node->data << " ";
    traverseInorder(node->right);
}
void BST::inorderTraversal()
{
    traverseInorder(root);
}
void BST::insert(int data)
{
    insert(data, &root);
}
void BST::insert(int data, Node **node)
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
        std::cout << "Element already exists\n";
}
BST::BST()
{
    root = NULL;
}
int BST::balanceFactor(Node *node)
{
    if (node == nullptr)
        return 0;
    int result = height(node->left) - height(node->right);
    return result;
}
int BST::height(Node *node)
{
    if (node == nullptr)
        return 0;
    return std::max(height(node->left), height(node->right)) + 1;
}