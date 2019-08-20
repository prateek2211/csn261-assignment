#ifndef TREE_INCLUDE
#define TREE_INCLUDE
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
class BST
{
private:
    void insert(int, Node **);

public:
    Node *root;
    void allPath(Node *, int path[], int pathLen);
    void printLeafRoot(Node *node);
    void printAllHelper(Node *root);
    void printAll();
    void traverseInorder(Node *root);
    BST();
    void levelIndentationHelper(Node *, int);
    void levelIndentation();
    int balanceFactor(Node *);
    int height(Node *);
    void insert(int);
    void inorderTraversal();
    friend class AvlTree;
};
class AvlTree : public BST
{
private:
    Node *root;
    void rotateRight(Node **);
    void rotateLeft(Node **);
    void insert(int, Node **);

public:
    AvlTree();
    void printAll();
    void BSTtoAVL(BST);
    void levelIndentation();
    void inorderTraversal();
    void insert(int);
};

class RBtree
{
    struct node
    {
        int data;
        node *parent;
        char color;
        node *left;
        node *right;
    };
    node *root;

public:
    RBtree()
    {
        root = nullptr;
    }
    node *newNode(node *, int);
    void insert(int);
    void fixInsert(node *);
    void rotateLeft(node *);
    void allPath(node *, int path[], int pathLen);
    void printLeafRoot(node *node);
    void printAllHelper(node *root);
    void printArray(int arr[], int len);
    void printAll();
    node *insertBST(node *root, int data);
    void rotateRight(node *);
    void traverseInorder(node *root);
    int height(node *node);
    void levelIndentationHelper(node *, int);
    void levelIndentation();
    void inorderTraversal();
};
#endif