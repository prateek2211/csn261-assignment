#include <iostream>
#include "tree.h"
using namespace std;
int main(int argc, char const *argv[])
{
    cout << "1. To insert a node in the BST and in the red-black tree\n2. To create AVL tree from the inorder traversal of the BST\n3. To print the inorder traversal of the BST/AVL/red-black tree\n4. To display all the paths in the BST/AVL tree/red-black tree \n5. To print the BST/AVL tree/red-black Tree in the terminal using level-wise indentation (print color for red-black tree) \n6. Exit";
    AvlTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);
    avl.inorderTraversal();
    return 0;
}