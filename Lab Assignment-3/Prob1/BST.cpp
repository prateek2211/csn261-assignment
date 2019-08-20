#include "tree.h"
#include <iostream>
#include <vector>
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
void printArray(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        std::cout << arr[i] << "->";
    }
    std::cout << arr[len - 1] << std::endl;
}
void BST::allPath(Node *node, int path[], int pathLen)
{
    if (node == NULL)
        return;

    path[pathLen] = node->data;
    pathLen++;

    if (node->left == NULL && node->right == NULL)
    {
        printArray(path, pathLen);
    }
    else
    {
        allPath(node->left, path, pathLen);
        allPath(node->right, path, pathLen);
    }
}
void BST::printLeafRoot(Node *node)
{
    int path[1000];
    allPath(node, path, 0);
}
void BST::printAllHelper(Node *root)
{
    if (root == NULL)
        return;
    printLeafRoot(root);
    printAllHelper(root->left);
    printAllHelper(root->right);
}
void BST::printAll()
{
    printAllHelper(root);
}
void BST::levelIndentationHelper(Node *node, int h)
{
    if (node == NULL)
        return;
    int diff = std::abs(height(node->left) - height(node->right));
    if (node->left == NULL && node->right == NULL)
    {
        for (int i = 0; i < h; i++)
            std::cout << "\t";
        std::cout << node->data << "\n";
    }
    else
    {
        for (int i = 0; i < h; i++)
            std::cout << "\t";
        std::cout << node->data << "[" << diff << "]\n";
    }
    levelIndentationHelper(node->left, h + 1);
    levelIndentationHelper(node->right, h + 1);
}
void BST::levelIndentation()
{
    levelIndentationHelper(root, 0);
}