#ifndef ASSIGNMENT3_STACK_H
#define ASSIGNMENT3_STACK_H

/*Function templates are special functions that can operate
with generic types. This allows us to create a function
template whose functionality can be adapted to more than
one type or class without repeating the entire code for each type.*/

/*To use this function template we use the following format for the function call:

function_name <type> (parameters);

*/

using namespace std;

#include <iostream>
#include <string.h>

template <typename T>
class Stack {
public:
    Stack();
    ~Stack();
    bool isEmpty() const;
    int size() const;

    //Push: Place item on top of the stack
    void push(const T& newItem);
    //Top: Take a look at the topmost item without removing it
    void getTop(T& stackTop) const;
    //Pop: Remove item from the top of the stack
    void pop();
    void print();

private:
    struct ListNode {
        T item;
        ListNode* next;
    };
    ListNode* _head;
    int _size;
    void printReverse(ListNode* head);
};

struct StackException : public exception
{
    std::string error;
    StackException(string stack) : error(stack) {};
    ~StackException() throw () {};
    const char* what() const throw() { return error.c_str(); }
};

template<typename T>
Stack<T>::Stack() {
    _head = NULL;
    _size = 0;
}

template<typename T>
Stack<T>::~Stack() {

}

template<typename T>
void Stack<T>::push(const T &newItem) {
    // if stack is empty
    if (_head == NULL)
    {
        _head = new ListNode;
        _head->item = newItem;
        _head->next = NULL;
    }
    else
    {
        ListNode *temp = _head;

        ListNode *newNode = new ListNode;

        newNode->item = newItem;
        newNode->next = NULL;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    _size ++;
}

template<typename T>
bool Stack<T>::isEmpty() const {

    try{
        if( _head == NULL)
        {
            throw StackException("Stack is empty.");
        }
    }catch(StackException& caught){
        cout<<"Error caught "<< caught.what() << endl;
        return true;
    }

    return false;
}

template<typename T>
int Stack<T>::size() const {
    return _size;
}

template<typename T>
void Stack<T>::getTop(T &stackTop) const {
    ListNode *temp = _head;

    if(isEmpty())
    {
        return; // throw stack error
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    // assign last node item
    stackTop = temp->item;
}

template<typename T>
void Stack<T>::pop() {

    // Error handling done in isEmpty function.
    if (isEmpty())
        return;

    ListNode *temp = _head;
    // if stack has 1 elements

    if (_head->next == NULL)
    {
        delete(temp);
        _head = NULL;
        _size --;
        return;
    }

    ListNode *tempAhead = _head->next;

    // if stack has 2 elements
    if(tempAhead->next == NULL)
    {
        temp->next = NULL;
        delete(tempAhead);
        _size --;
        return;
    }

    // if stack has more than 2 elements
    while(tempAhead->next != NULL)
    {
        tempAhead = tempAhead->next;
        temp = temp->next;
    }

    temp->next = NULL;
    delete(tempAhead);
    _size --;
}

template<typename T>
void Stack<T>::print() {
    // if stack is empty
    if(_head == NULL)
        return;

    printReverse(_head);
}

template<typename T>
void Stack<T>::printReverse(Stack::ListNode *head) {
    // Recursion print function for displaying stack in reverse order.

    // Base case
    if (head == NULL)
        return;

    // call with next node
    printReverse(head->next);

    // At the end print
    cout << head->item << endl;
}

#endif //ASSIGNMENT3_STACK_H
