#include <iostream>
#include "tree.h"
using namespace std;
RBtree::node *RBtree::newNode(node *parent, int data)
{
    node *temp = new node;
    temp->parent = parent;
    temp->color = 'r';
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

RBtree::node *RBtree::insertBST(node *n, int data)
{
    if (n == NULL)
        return root = newNode(NULL, data);
    else if (n->right == NULL && n->data < data)
        return n->right = newNode(n, data);
    else if (n->left == NULL && n->data > data)
        return n->left = newNode(n, data);

    if (n->data > data)
        insertBST(n->left, data);
    else
        insertBST(n->right, data);
}
void RBtree::insert(int data)
{
    node *t = insertBST(root, data);
    fixInsert(t);
}
void RBtree::fixInsert(node *t)
{
    if (t == root)
    {
        t->parent = NULL;
        t->color = 'b';
        return;
    }
    if (t->parent->color == 'r')
    {
        node *gp = t->parent->parent;
        node *uncle = (gp->right == t->parent) ? gp->left : gp->right;
        if (uncle != NULL && uncle->color == 'r')
        {
            t->parent->color = 'b';
            uncle->color = 'b';
            gp->color = 'r';
            fixInsert(gp);
        }
        else
        {
            node *par = t->parent;
            // L cases
            if (par->parent->left == par)
            {
                // LR case
                if (t->parent->left != t)
                {
                    t = t->parent;
                    rotateLeft(t);
                }
                // LL case
                t->parent->color = 'b';
                gp->color = 'r';
                rotateRight(gp);
            }
            // R cases
            else
            {
                // RL case
                if (t->parent->left == t)
                {
                    t = t->parent;
                    rotateRight(t);
                }
                // RR case
                t->parent->color = 'b';
                gp->color = 'r';
                rotateLeft(gp);
            }
        }
    }
}

void RBtree::rotateLeft(node *p)
{
    if (p->right == NULL)
        return;
    else
    {
        node *temp = p->right;
        if (temp->left != NULL)
        {
            p->right = temp->left;
            temp->left->parent = p;
        }
        else
            p->right = NULL;
        if (p->parent != NULL)
            temp->parent = p->parent;
        if (p->parent == NULL)
            root = temp;
        else
        {
            if (p == p->parent->left)
                p->parent->left = temp;
            else
                p->parent->right = temp;
        }
        temp->left = p;
        p->parent = temp;
    }
}
void RBtree::rotateRight(node *p)
{
    if (p->left == NULL)
        return;
    else
    {
        node *temp = p->left;
        if (temp->right != NULL)
        {
            p->left = temp->right;
            temp->right->parent = p;
        }
        else
            p->left = NULL;
        if (p->parent != NULL)
            temp->parent = p->parent;
        if (p->parent == NULL)
            root = temp;
        else
        {
            if (p == p->parent->left)
                p->parent->left = temp;
            else
                p->parent->right = temp;
        }
        temp->right = p;
        p->parent = temp;
    }
}
void RBtree::inorderTraversal()
{
    traverseInorder(root);
}
void RBtree::traverseInorder(node *node)
{
    if (node == nullptr)
        return;
    traverseInorder(node->left);
    std::cout << node->data << " ";
    traverseInorder(node->right);
}