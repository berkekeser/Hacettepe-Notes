#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct Node* head; // global
void Insert(int data, int n); // insert
void Print(); // print all elements in the list
void Delete(int n); // delete node at position n


void Insert(int data, int n)
{
    Node *temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if(n == 1)
    {
        temp1-> next = head;
        head = temp1;
        return;
    }

    Node* temp2 = head;
    for(int i = 0; i < n - 2; i++) // n -2! temp2->next
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Print()
{
    Node* temp = head;
    cout << "List is:" << endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Delete(int n)
{
    struct Node* temp1 = head;
    if(n==1)
    {
        head = temp1 -> next; // head now points to second node
        delete(temp1);
        return;
    }
    int i;
    for(i=0; i<n-2;i++)
        temp1 = temp1->next; // temp1 point to (n-1)th Nodes
    struct Node* temp2 = temp1->next; // nth Node
    temp1->next = temp2->next; // (n+1)th Node
    delete(temp2);

}

void Insert2(int x)
{
    Node* temp = new Node();
    temp -> data = x;
    temp -> next = head;
    head = temp;
}

int main() {
    head = NULL;
    Insert2(2);
    Insert2(4);
    Insert2(6);
    Insert2(5);
    Print();
    int n;
    cout << "Enter a position \n";
    cin >> n;
    Delete(n);
    Print();
    return 0;

}
