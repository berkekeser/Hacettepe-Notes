#ifndef ASSIGNMENT3_GENERICDOUBLYLINKEDLIST_H
#define ASSIGNMENT3_GENERICDOUBLYLINKEDLIST_H

using namespace std;

#include "iostream"
#include <string.h>
#include "vector"


template<class K>
struct DoubleNode{
    K data;
    DoubleNode  *next;
    DoubleNode *prev;
};

template<class K>
class GenericDoublyLinkedList {
public:
    GenericDoublyLinkedList();
    void add(K &newItem);
    void display();
    void deleteFromNthPosition(int n);
    void deleteByGivenIndeces(string indeces, GenericDoublyLinkedList<K> &transfer);
    DoubleNode<K>* getElementNthPosition(int n);
    bool checkSize();
    int _size;
    DoubleNode<K>  *_head;
    DoubleNode<K> *_tail;
};

template<class K>
GenericDoublyLinkedList<K>::GenericDoublyLinkedList() {
    _head = NULL;
    _tail = NULL;
    _size = 0;
}

template<typename K>
void GenericDoublyLinkedList<K>::add(K &newItem) {

    if(_head == NULL)
    {
        _head = new DoubleNode<K>;
        _head->data = newItem;
        _head->next = NULL;
        _tail = _head;
        _head->prev = NULL;
        _size++;
    }
    else
    {
        DoubleNode<K> *newNode = new DoubleNode<K>;
        _tail->next = newNode;
        newNode->data = newItem;
        newNode->prev = _tail;
        newNode->next = NULL;
        _tail = newNode;
        _size++;
    }
}

template<typename K>
void GenericDoublyLinkedList<K>::display() {
    DoubleNode<K> *temp;

    temp = _head;
    if(_head == NULL)
    {
        cout << "empty list" << endl; // DELETE
        return;
    }
    else
    {
        while (temp != _tail)
        {
            cout << temp->data << " K" <<endl;
            temp = temp->next;
        }
        cout << _tail->data << " T"<<endl;
    }
}

template<class K>

void GenericDoublyLinkedList<K>::deleteFromNthPosition(int n) {

    //if Nth item does not exist
    if(n > _size - 1)
        return;

    // if linked list empty
    if(_head == NULL)
        return;

    struct DoubleNode<K> *temp = _head;

    if(n == 0)
    {
        if(_head == _tail)
        {
            _tail = _tail->prev;
            delete(_head->next);
            _head->next = NULL;
            _size--;
        }

        else
        {
            temp = _head->next;
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete(temp);
            _size--;
        }
        return;
    }

    if(n == 1)
    {

        if(_head->next == _tail)
        {
            _tail = _tail->prev;
            delete(_head->next);
            _head->next = NULL;
            _size--;
        }
        else
        {
            temp = _head->next;
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete(temp);
            _size--;
        }
        return;
    }

    int counter = 0;

    while (counter < n)
    {
        temp = temp->next;
        counter++;
    }

    if(temp->next == _tail)
    {
        temp->prev->next = _tail;
        _tail->prev = temp->prev;
        delete(temp);
        _tail->next = NULL;
        _size--;
    }
    else if(temp == _tail)
    {
        _tail = _tail->prev;
        _tail->next = NULL;
        delete(temp);
        _size--;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete(temp);
        _size--;
    }
}

template<class K>
DoubleNode<K> *GenericDoublyLinkedList<K>::getElementNthPosition(int n) {

    //if Nth item does not exist
    if(n > _size - 1)
        return NULL;

    // if linked list empty
    if(_head == NULL)
        return NULL;

    struct DoubleNode<K> *temp = _head;

    if(n == 0)
    {
        return _head;
    }

    if(n == 1)
    {
        if(_head->next == _tail)
        {
            return _tail;
        }
        else
        {
            return _head->next;
        }
    }

    int counter = 0;
    while (counter < n)
    {
        temp = temp->next;
        counter++;
    }
    return temp;

}

template<class K>
bool GenericDoublyLinkedList<K>::checkSize() {
    return (_size > 1) ? true : false;
}


template<class K>
void GenericDoublyLinkedList<K>::deleteByGivenIndeces(string indeces, GenericDoublyLinkedList<K> &transfer) {

    /*This function is the most important function for transfer.
     * It takes indeces and address of transfer.
     * Tokenize indeces by comma and sort them smallest to largest.
     * It's iterate inside transfer doubly linked list and find corresponding indeces
     * Than it will add this corresponding linked list item to new doubly linked list
     * At the end of the operation it's delete transfer head from memory and assign
     * new linked list to transfer head.
     */

    DoubleNode<Package> *temp = transfer._head;

    vector <int> sortedIndeces;

    const char* c_string = indeces.c_str();

    char* token = strtok((char*)c_string, ",");

    while (token) {
        int num = atoi(token);
        sortedIndeces.push_back(num+1);
        // Get next token
        token = strtok(NULL, ",");
    }

    GenericDoublyLinkedList<Package> newDeletedList;

    int counter = 0;
    int flag = 0;
    while (temp->next != NULL)
    {
        flag = 0;
        for (int i = 0; i < sortedIndeces.size(); i++)
        {
            if(sortedIndeces[i]  == counter)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            newDeletedList.add(temp->data);
        }
        counter++;
        temp = temp->next;
    }

    // for last node
    flag = 0;
    for (int i = 0; i < sortedIndeces.size(); i++)
    {
        if(sortedIndeces[i]  == counter)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        newDeletedList.add(temp->data);
    }

    delete(temp);
    transfer = newDeletedList;

}

#endif //ASSIGNMENT3_GENERICDOUBLYLINKEDLIST_H
