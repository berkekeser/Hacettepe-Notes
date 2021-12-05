#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

struct Node* head;
struct Node* tail;

void createDCLL(int number)
{
    struct Node *newnode;
    head = NULL;
    newnode = new Node();
    newnode->data = number;
    if(head == NULL)
    {
        head = tail = newnode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
        tail = newnode;
    }
}

void Display()
{
    struct Node* temp;
    temp = head;
    if(head == NULL)
    {
        cout << "There's no data in the DCLL" << endl;
    }
    else
    {
        while(temp!= tail) // can be use do while instead of this
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
}

int main() {
    createDCLL(5);
    createDCLL(12);
    createDCLL(13);
    Display();


    return 0;
}
