#include <stdio.h>
#include <stdlib.h>

int *deque;
int front = -1;
int rear = 0;
int capacity = 4;

int dequeSize()
{
    if (front == -1)
        return 0;
    int size = rear - front + 1;
    if (size < 0)
        return capacity - 1 + size;
    return size;
}
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

int main(int argc, char const *argv[])
{
    deque = (int *)calloc(capacity, sizeof(int));
    insertFront(1);
    insertFront(3);
    insertFront(9);
    insertRear(5);
    insertRear(8);
    insertRear(8);
    deleteRear();
    deleteFront();

    printDeque();
    return 0;
}
