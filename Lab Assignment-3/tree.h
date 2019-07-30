class Node
{
private:
    int data;
    Node *left;
    Node *right;
    friend class BST;
    friend class AvlTree;
};
class BST
{
private:
    Node *root;
    void insert(int, Node **);

public:
    void traverseInorder(Node *root);
    BST();
    int balanceFactor(Node *);
    int height(Node *);
    void insert(int);
    void inorderTraversal();
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
    void inorderTraversal();
    void insert(int);
};
class RedBlackTree
{
private:
    Node *root;
    void insert(int, Node *);

public:
    void insert(int);
    void inorderTraversal();
};
