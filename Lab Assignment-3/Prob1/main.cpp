#include <iostream>
#include "tree.h"
using namespace std;
int main(int argc, char const *argv[])
{
    BST bst;
    AvlTree avl;
    RBtree rb;
    cout << "1. To insert a node in the BST and in the red-black tree\n2. To create AVL tree from the inorder traversal of the BST\n3. To print the inorder traversal of the BST/AVL/red-black tree\n4. To display all the paths in the BST/AVL tree/red-black tree \n5. To print the BST/AVL tree/red-black Tree in the terminal using level-wise indentation (print color for red-black tree) \n6. Exit\n";
    bool quit = false;
    while (!quit)
    {
        int option;
        cout << "Enter menu options\n";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter the value\n";
            int val;
            cin >> val;
            bst.insert(val);
            rb.insert(val);
            break;

        case 2:
            avl.BSTtoAVLV2(bst);
            cout << "Created avl tree" << endl;
            break;
        case 3:
            cout << "Select type of tree:\n1.BST\n2.AVL\n3.RB\n";
            int tree;
            cin >> tree;
            switch (tree)
            {
            case 1:
                bst.inorderTraversal();
                break;
            case 2:
                avl.inorderTraversal();
                break;
            case 3:
                rb.inorderTraversal();
                break;
            default:
                cout << endl;
                break;
            }
            break;
        case 5:
            cout << "Select type of tree:\n1.BST\n2.AVL\n3.RB\n";
            cin >> tree;
            switch (tree)
            {
            case 1:
                bst.levelIndentation();
                break;
            case 2:
                avl.levelIndentation();
                break;
            case 3:
                rb.levelIndentation();
                break;
            default:
                cout << endl;
                break;
            }
            break;
        case 4:
            cout << "Select type of tree:\n1.BST\n2.AVL\n3.RB\n";
            cin >> tree;
            switch (tree)
            {
            case 1:
                bst.printAll();
                break;
            case 2:
                avl.printAll();
                break;
            case 3:
                rb.printAll();
                break;
            default:
                cout << endl;
                break;
            }
            break;
        case 6:
            quit = true;
            break;
        default:
            break;
        }
    }
    return 0;
}
