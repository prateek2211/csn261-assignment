#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
typedef struct StudentNode *Node;
struct StudentNode
{
    long long int rollNo;
    char *name;
    char *dateOfBirth;
    char *address;
    long long int phoneNo;
    Node next;
    Node prev;
};
Node modify(Node head, long long int rollNo, char *name, char *dateOfBirth, char *address, long long int phoneNo)
{
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
    return head;
}
void insertAfter(Node prev, Node newNode)
{
    if (!prev)
        return;
    newNode->next = prev->next;
    newNode->prev = prev;
    newNode->next->prev = newNode;
    prev->next = newNode;
}

void printAll(Node head)
{
    if (head == NULL)
        return;
    Node p = head;
    do
    {
        printf("Name = %s, D.O.B = %s, Address = %s\n", p->name, p->dateOfBirth, p->address);
        p = p->next;
    } while (p != head);
}

Node deleteNode(Node head, long long int rollNo)
{
    if (head == NULL)
        return NULL;
    Node p = head;
    if (p->rollNo == rollNo)
    {
        head = head->next;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
        return head;
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
        return head;
    }
    return head;
}
int main(int argc, char const *argv[])
{
    FILE *file = fopen("/home/prateek/Downloads/StudentData.csv", "r");
    char buffer[1024];
    fgets(buffer, 1024, file);
    const char *token;
    int x = 3;
    for (token = strtok(buffer, ","); token && *token; token = strtok(NULL, ",\n"))
    {
        printf("%s", token);
        if (!--x)
            printf("%s\n", token);
    }
    Node head = (Node)malloc(sizeof(struct StudentNode));
    head->name = "Prateek Sachan";
    head->next = head;
    head->rollNo = 786;
    head->prev = head;
    Node newNode = (Node)malloc(sizeof(struct StudentNode));
    newNode->name = "Roman Reigns";
    insertAfter(head->prev, newNode);
    newNode = (Node)malloc(sizeof(struct StudentNode));
    newNode->name = "Brock Lesnar";
    newNode->rollNo = 420;
    insertAfter(head->prev, newNode);
    newNode = (Node)malloc(sizeof(struct StudentNode));
    newNode->name = "Seth ROllins";
    insertAfter(head->prev, newNode);
    newNode = (Node)malloc(sizeof(struct StudentNode));
    newNode->name = "Ronda Reigns";
    insertAfter(head->prev, newNode);
    newNode = (Node)malloc(sizeof(struct StudentNode));
    newNode->name = "Charlotte Flair";
    insertAfter(head->prev, newNode);
    newNode = (Node)malloc(sizeof(struct StudentNode));
    newNode->name = "Mandy Rose";
    insertAfter(head->prev, newNode);
    newNode = (Node)malloc(sizeof(struct StudentNode));
    newNode->name = "Goldberg";
    insertAfter(head->prev, newNode);
    modify(head, 45620, "Chutiya Lesnar", NULL, NULL, 93333);
    head = deleteNode(head, 420);
    printAll(head);
    return 0;
}