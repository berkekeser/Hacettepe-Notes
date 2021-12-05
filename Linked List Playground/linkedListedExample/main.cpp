#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct Node* head; //global variable, can be accessed anywhere


// Inserting a node at beginning
void Insert(int x)
{
    Node* temp = new Node();
    temp -> data = x;
    temp -> next = head;
    head = temp;
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

int main() {
    head = NULL; // empty list
    cout << "How many numbers?" << endl;
    int n,i,x;
    cin >> n;
    for (int i = 0; i <n; ++i) {
        cout << "Enter the number" << endl;
        cin >> x;
        Insert(x);
        Print();
    }
    return 0;
}
