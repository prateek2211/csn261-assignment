/**
 * @file MAT.c
 * @brief This file contains solution for problem 2 of assignmen 2
 * @author Prateek Sachan
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define WHITE 0
#define BLACK 1
#define GREY 2
typedef struct TreeNode *Node;
/**
 * Represents Single Node of a Tree
 */
struct TreeNode
{
    int blockNo;
    int color;
    Node firstChild;
    Node secondChild;
    Node thirdChild;
    Node fourthChild;
};

int blockNumber = 1;
int maxSquare[8][8];
/**
 * Size of array given as input
 */
int inputSize;
/**
 * Root node of the quad tree
 */
Node root;
/**
 * Generates maximal square array for given array
 * @param arr Given Array
 * @param size Size of given array
 */
void genMaxSquare(int size, int arr[size][size], int startX, int startY, int endX, int endY, Node *tree)
{
    if (!(*tree))
        (*tree) = (Node)malloc(sizeof(struct TreeNode));
    (*tree)->color = GREY;
    bool allEqual = true;
    int first = arr[startY][startX];
    for (int i = startY; i <= endY; i++)
        for (int j = startX; j <= endX; j++)
            if (arr[i][j] != first)
                allEqual = false;
    if (allEqual)
    {
        for (int i = startY; i <= endY; i++)
            for (int j = startX; j <= endX; j++)
                maxSquare[i][j] = blockNumber;
        (*tree)->blockNo = blockNumber;
        blockNumber++;
        if (first == 0)
            (*tree)->color = WHITE;
        else
            (*tree)->color = BLACK;
    }
    else
    {
        genMaxSquare(size, arr, startX, startY, startX + (endX - startX) / 2, startY + (endY - startY) / 2, &((*tree)->firstChild));
        genMaxSquare(size, arr, startX + (endX - startX) / 2 + 1, startY, endX, startY + (endY - startY) / 2, &((*tree)->secondChild));
        genMaxSquare(size, arr, startX, startY + (endY - startY) / 2 + 1, startX + (endX - startX) / 2, endY, &((*tree)->thirdChild));
        genMaxSquare(size, arr, startX + (endX - startX) / 2 + 1, startY + (endY - startY) / 2 + 1, endX, endY, &((*tree)->fourthChild));
    }
}
/**
 * Reads file and stores values in given array
 * @param arr Given Array
 * @param size Size of given array
 */
void readFile(int size, int arr[size][size])
{
    FILE *file = fopen("/home/prateek/Documents/csn261-assignment/Lab Assignment-2/Prob2/L2_P2_inputsample.txt", "r");
    char buff[1024];
    int i = 0;
    while (fgets(buff, sizeof(buff), file))
    {
        int j = 0;
        for (char *tok = strtok(buff, " "); tok; tok = strtok(NULL, " \n"))
        {
            arr[i + size - inputSize][j + size - inputSize] = atoi(strdup(tok));
            j++;
        }
        i++;
    }
}
/**
 * Traverses the tree in postorder fashion
 * @param level Level of current node
 * @root Current Node
 */
void treeTraversal(Node root, int level)
{
    if (!root)
        return;
    treeTraversal(root->firstChild, level + 1);
    treeTraversal(root->secondChild, level + 1);
    treeTraversal(root->thirdChild, level + 1);
    treeTraversal(root->fourthChild, level + 1);
    if (root->color != GREY)
        printf("( %d, %d, %d )\n", root->blockNo, root->color, level);
}
/**
 * Gets the size of array in input file
 */
int getInputSize()
{
    int length = 0;
    FILE *file = fopen("/home/prateek/Documents/csn261-assignment/Lab Assignment-2/Prob2/L2_P2_inputsample.txt", "r");
    char buff[1024];
    fgets(buff, sizeof(buff), file);
    for (char *tok = strtok(buff, " "); tok; tok = strtok(NULL, " \n"))
        length++;
    fclose(file);
    return length;
}

/**
 * Gives next power of 2 greater than n
 */
int nextPowerOf2(int n)
{
    int pow = 1;
    if (n && !(n & (n - 1)))
        return n;
    while (pow < n)
        pow <<= 1;
    return pow;
}
/**
 * Prints Maximal Square Array
 */
void printMaximalSquare(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", maxSquare[i][j]);
        }
        printf("\n");
    }
}
int main(int argc, char const *argv[])
{
    inputSize = getInputSize();
    const int size = nextPowerOf2(inputSize);
    int arr[size][size];
    memset(arr, 0, size * size * sizeof(int));
    readFile(size, arr);
    genMaxSquare(size, arr, 0, 0, size - 1, size - 1, &root);
    printMaximalSquare(size);
    treeTraversal(root, 0);
    return 0;
}
