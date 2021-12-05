#ifndef ASSIGNMENT3_QUEUE_H
#define ASSIGNMENT3_QUEUE_H


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


template<typename T>
class Queue {
public:
    Queue();
    ~Queue();
    bool isEmpty() const;
    int size() const;
    //Enqueue: Items are added to the back of the queue
    void enqueue(const T& newItem);
    //Dequeue: Items are removed from the front of the queue
    void dequeue();
    //Get Front: Take a look at the first item
    void getFront(T& queueTop) const;
    void print();

private:
    struct QueueNode {
        T item;
        QueueNode *next;
    };
    int _size;
    /* to avoid the traversal to the last node,
     an additional pointer to the last node is defined*/
    QueueNode *_lastNode;
    QueueNode *_head;
};


struct QueueException : public exception
{
    std::string error;
    QueueException(string queue) : error(queue) {};
    ~QueueException() throw () {};
    const char* what() const throw() { return error.c_str(); }
};

template<typename T>
Queue<T>::Queue() {
    _head = NULL;
    _size = 0;
}


template<typename T>
Queue<T>::~Queue() {

}

template<typename T>
void Queue<T>::enqueue(const T &newItem) {
    //if queue is empty
    if(_head == NULL)
    {
        _head = new QueueNode;
        _head->item = newItem;
        _head->next = NULL;
        _lastNode = _head;
    }
    else
    {
        QueueNode *temp = _head;
        QueueNode *newNode = new QueueNode;
        newNode->item = newItem;
        newNode->next = NULL;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        _lastNode = newNode;
    }
    _size++;
}

template<typename T>
bool Queue<T>::isEmpty() const {
    try{
        if( _head == NULL)
        {
            throw QueueException("Queue is empty.");
        }
    }catch(QueueException& caught){
        cout<<"Error caught "<< caught.what() << endl;
        return true;
    }

    return false;
}

template<typename T>
int Queue<T>::size() const {
    return _size;
}

template<typename T>
void Queue<T>::getFront(T &queueTop) const {
    // error handling done in QueueException struct.
    if(isEmpty())
        return; // throw exception
    queueTop = _head->item;
}

template<typename T>
void Queue<T>::dequeue() {
    //if queue is empty
    if(isEmpty())
        return; // throw exception

    QueueNode *temp = _head;
    //if queue has 1 element
    if (_head->next == NULL)
    {
        delete(temp);
        _head = NULL;
        _size --;
        return;
    }

    QueueNode *tempAhead = _head->next;

    //if queue has more than one element
    delete(temp);
    _head = tempAhead;
    _size --;
}

template<typename T>
void Queue<T>::print() {

    if(_head == NULL)
        return;

    QueueNode *temp = _head;
    while (temp->next != NULL)
    {
        cout << temp->item << endl;
        temp = temp->next;
    }
    cout << temp->item << endl;
}

#endif //ASSIGNMENT3_QUEUE_H
