/**
* @file Prob2.c
* @brief this file contains code for problem1 of Lab-Assignment1
*
*@author Prateek Sachan
*
*@date 07/30/2019
 */
#include <stdio.h>
#include <stdlib.h>

int *deque;
int front = -1;
int rear = 0;
int capacity = 2;
/**
* Returns the size of deque
*@author Prateek Sachan
*
*@date 07/30/2019
 */
int dequeSize()
{
    if (front == -1)
        return 0;
    int size = rear - front + 1;
    if (size < 0)
        return capacity - 1 + size;
    return size;
}
/**
* Changes the size of deque and return new deque
*@author Prateek Sachan
*
*@date 07/30/2019
 */
int *resizeDeque(int newCapacity)
{
    int *newDeque = (int *)calloc(newCapacity, sizeof(int));
    int var;
    if (rear >= front)
    {
        var = 0;
        for (int i = front; i <= rear; i++)
            newDeque[var++] = deque[i];
    }
    else
    {
        var = 0;
        for (int i = front; i < capacity; i++)
            newDeque[var++] = deque[i];
        for (int i = 0; i <= rear; i++)
            newDeque[var++] = deque[i];
    }
    rear = var - 1;
    front = 0;
    capacity = newCapacity;
    return newDeque;
}
/**
* Inserts the data at front of deque
*@author Prateek Sachan
*
*@date 07/30/2019
 */
void insertFront(int data)
{
    if (front == rear + 1)
        deque = resizeDeque(2 * capacity);
    if (front == -1)
    {
        rear = 0;
        front = 0;
    }
    else if (front == 0)
        front = capacity - 1;
    else
        front--;
    deque[front] = data;
}
/**
* Inserts the data at rear of deque
*@author Prateek Sachan
*
*@date 07/30/2019
 */
void insertRear(int data)
{
    if (front == rear + 1)
        deque = resizeDeque(capacity * 2);
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == capacity - 1)
        rear = 0;
    else
        rear++;
    deque[rear] = data;
}
/**
* Print the contents of the deque
*@author Prateek Sachan
*
*@date 07/30/2019
 */
void printDeque()
{
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", deque[i]);
    }
    else
    {
        for (int i = front; i < capacity; i++)
            printf("%d ", deque[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", deque[i]);
    }
}
/**
* Deletes the data at front of deque
*@author Prateek Sachan
*
*@date 07/30/2019
 */
void deleteFront()
{
    if (front == -1)
        return;
    if (front == capacity - 1)
        front = 0;
    else
        front++;
    if (dequeSize() == capacity / 2)
        deque = resizeDeque(capacity / 2);
}
/**
* Deletes the data at rear of deque
*@author Prateek Sachan
*
*@date 07/30/2019
 */
void deleteRear()
{
    if (front == -1)
        return;
    if (rear == 0)
        rear = capacity - 1;
    else
        rear--;
    if (dequeSize() == capacity / 2)
        deque = resizeDeque(capacity / 2);
}

void printSize()
{
    printf("Deque Capacity = %d\n", capacity);
}

int main(int argc, char const *argv[])
{
    deque = (int *)calloc(capacity, sizeof(int));
    insertFront(1);
    printDeque();
    printSize();
    insertFront(3);
    printDeque();
    printSize();
    insertFront(9);
    printDeque();
    printSize();
    insertRear(5);
    printDeque();
    printSize();
    insertRear(8);
    printDeque();
    printSize();
    insertRear(8);
    printDeque();
    printSize();
    deleteRear();
    printDeque();
    printSize();
    deleteFront();
    printDeque();
    printSize();
    return 0;
}
