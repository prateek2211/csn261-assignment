/**
* @file Prob1.c
* @brief this file contains code for problem1 of Lab-Assignment1
*
*@author Prateek Sachan
*
*@date 07/30/2019
 */
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
typedef struct StudentNode *Node;
/**
 * Node represnting data corresponding to a student
 */
struct StudentNode
{
    int rollNo;
    char *name;
    char *dateOfBirth;
    char *address;
    long long int phoneNo;
    Node next;
    Node prev;
};
Node head = NULL;
/**
 * Queque to store unused roll numbers
 */
int queuqe[MAX];
int rear = 0;
int front = -1;
/**
* Check if Queque is empty or not
*@author Prateek Sachan
*
*@date 07/30/2019
 */
bool quequeEmpty()
{
    return front == -1;
}
/**
* Add data to rear of queque
*@author Prateek Sachan
*
*@date 07/30/2019
 */
void enqueue(int data)
{
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1)))
    {
        printf("\nQueue is Full");
        return;
    }

    else if (quequeEmpty())
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear++;
    queuqe[rear] = data;
}
/**
* Returns data from front of queque
*@author Prateek Sachan
*
*@date 07/30/2019
 */
int dequeque()
{
    if (quequeEmpty())
        return -1;
    int data = queuqe[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX - 1)
        front = 0;
    else
        front++;
    return data;
}
/**
* Modifies data in a node having a roll number
*@author Prateek Sachan
*
*@date 07/30/2019
 */
void modify(int rollNo, char *name, char *dateOfBirth, char *address, long long int phoneNo)
{
    if (head == NULL)
        return;
    Node p = head;
    do
    {
        p = p->next;
    } while (p != head && p->rollNo != rollNo && p);
    if (p->rollNo == rollNo)
    {
        p->name = name;
        p->dateOfBirth = dateOfBirth;
        p->address = address;
        p->phoneNo = phoneNo;
    }
}
/**
* Inserts a new node after a previous node
*@author Prateek Sachan
*
*@date 07/30/2019
 */
void insertAfter(Node prev, Node newNode)
{
    if (!head)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }
    newNode->next = prev->next;
    newNode->prev = prev;
    newNode->next->prev = newNode;
    prev->next = newNode;
}

/**
* prints the data of all nodes
*@author Prateek Sachan
*
*@date 07/30/2019
 */
void printAll()
{
    if (head == NULL)
        return;
    Node p = head;
    do
    {
        printf("Roll No. =%d, Name = %s, D.O.B = %s, Address = %s, Phone No. = %lld\n", p->rollNo, p->name, p->dateOfBirth, p->address, p->phoneNo);
        p = p->next;
    } while (p != head);
}

/**
* Deletes the node having a roll number
*@author Prateek Sachan
*
*@date 07/30/2019
 */
void deleteNode(int rollNo)
{
    if (head == NULL)
        return;
    Node p = head;
    if (p->rollNo == rollNo)
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        head = head->next;
        free(p);
        enqueue(rollNo);
        return;
    }
    do
    {
        p = p->next;
    } while (p != head && p->rollNo != rollNo);
    if (p->rollNo == rollNo)
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
        enqueue(rollNo);
    }
}
/**
* Checks if string a is lexicographically greater than b
*@author Prateek Sachan
*
*@date 07/30/2019
 */
bool aGb(char *a, char *b)
{
    int minLength = (strlen(a) < strlen(b)) ? strlen(a) : strlen(b);
    for (int i = 0; i < minLength; i++)
    {
        if (a[i] > b[i])
            return true;
        else if (a[i] < b[i])
            return false;
    }
    if (strlen(a) > strlen(b))
        return true;
    return false;
}

/**
* Creates an empty node
*@author Prateek Sachan
*@param
*@date 07/30/2019
 */
Node createNode()
{
    Node node = (Node)malloc(sizeof(struct StudentNode));
    node->next = NULL;
    node->prev = NULL;
    return node;
}
/**
* Sorts the linked by name
*@author Prateek Sachan
*@param
*@date 07/30/2019
 */
void sortByName()
{
    if (!head && !head->next)
        return;
    Node p = head;
    do
    {
        Node q = p->next;
        do
        {
            if (aGb(p->name, q->name))
            {
                Node temp = createNode();
                temp->name = strdup(p->name);
                temp->address = strdup(p->address);
                temp->dateOfBirth = strdup(p->dateOfBirth);
                temp->phoneNo = p->phoneNo;
                temp->rollNo = p->rollNo;
                p->name = strdup(q->name);
                p->address = strdup(q->address);
                p->dateOfBirth = strdup(q->dateOfBirth);
                p->phoneNo = q->phoneNo;
                p->rollNo = q->rollNo;
                q->name = strdup(temp->name);
                q->address = strdup(temp->address);
                q->dateOfBirth = strdup(temp->dateOfBirth);
                q->phoneNo = temp->phoneNo;
                q->rollNo = temp->rollNo;
            }
            q = q->next;
        } while (q != head);
        p = p->next;
    } while (p->next != head);
}

/**
* Insert a node at position of last roll no of queque
*@author Prateek Sachan
*@param node head node of linked list
*@date 07/30/2019
 */
void insertFromQueue(Node node)
{
    int roll = dequeque();
    node->rollNo = roll;
    Node p = head;
    while (p->rollNo < roll)
        p = p->next;
    insertAfter(p->prev, node);
}
int lastRollNo = 101;
/**
* Inserts records from the csv file
*@author Prateek Sachan
*@param file input file to extract data from
*@date 07/30/2019
 */
void insertFileData(FILE *file)
{
    char buffer[1024];
    fgets(buffer, 1024, file);
    Node node = createNode();
    char *arr[5];
    int x = 0;
    for (char *token = strtok(buffer, ";"); token; token = strtok(NULL, ";\n"))
        arr[x++] = strdup(token);
    node->name = arr[1];
    node->dateOfBirth = arr[2];
    node->address = arr[3];
    node->phoneNo = strtol(arr[4], NULL, 0);
    if (quequeEmpty())
    {
        node->rollNo = lastRollNo++;
        if (head)
            insertAfter(head->prev, node);
        else
            insertAfter(NULL, node);
    }
    else
        insertFromQueue(node);
}
int main(int argc, char const *argv[])
{
    FILE *file = fopen("/home/prateek/Downloads/StudentData.csv", "r");
    char buffer[1024];
    fgets(buffer, 1024, file);
    deleteNode(108);
    insertFileData(file);
    insertFileData(file);
    insertFileData(file);
    insertFileData(file);
    deleteNode(102);
    deleteNode(101);
    insertFileData(file);
    insertFileData(file);
    insertFileData(file);
    printf("\nAfter initial insertion \n");
    printAll(head);
    sortByName();
    printf("\nAfter sorting \n");
    printAll(head);
    modify(103, "Prateek Sachan", "22/11/2000", "G-48, Ravindra Bhawan IIT Roorkee", 51208027);
    printf("\nAfter modification of data \n");
    printAll(head);
    fclose(file);
    return 0;
}