#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* GetNewNode(int x);
void InsertAtHead(int x);

struct Node* head; // global variable -pointer to head node


void InsertAtHead(int x)
{
    struct Node* newNode = GetNewNode(x); // this newNode is a local variable.
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

struct Node* GetNewNode(int x)
{
    struct Node* newNode = new Node();
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void Print()
{
    struct Node* temp = head;
    cout << "Forward: ";
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void ReversePrint()
{
    struct Node* temp = head;
    if(temp == NULL) // empty list, exit
        return;
    // Going to last node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    // Traversing backward using prev pointer
    cout << "Reverse: ";
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}



int main() {
    head = NULL; // empty list
    InsertAtHead(2); Print(); ReversePrint();
    InsertAtHead(4); Print(); ReversePrint();
    InsertAtHead(6); Print(); ReversePrint();
    return 0;
}
