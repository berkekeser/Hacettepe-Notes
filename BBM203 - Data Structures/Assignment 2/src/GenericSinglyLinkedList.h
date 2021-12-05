#ifndef BBM201_ASSIGNMENT2_GENERICSINGLYLINKEDLIST_H
#define BBM201_ASSIGNMENT2_GENERICSINGLYLINKEDLIST_H

#include "iostream"
#include "LibrarySystem.h"
#include <string.h>

using namespace std;

template<class T>
struct Node{
    T data;
    Node<T> *next;
};

template<class T>
class GenericSinglyLinkedList {
public:
    Node<T> *head;
    Node<T> *tail;

    GenericSinglyLinkedList<T>() {
        head = NULL;
        tail = NULL;
    }

    void add(T data) {

        if(head == NULL)
        {
            head = new Node<T>;
            head->data = data;
            head->next = NULL;
            tail = head;
        }
        else
        {
            Node<T> *newNode = new Node<T>;
            newNode->data = data;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
        }

        tail->next = head; // for making circular singly linked list
    }

    bool checkIdExist(int id)
    {
        struct Node<T> *temp = head;

        if(temp == NULL)
            return false;

        if(tail->data.id == id)
        {
            return true;
        }

        while (temp->next != head)
        {
            if(temp->data.id == id)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }


    void removeById(int id){
        struct Node<T>* temp = head;
        struct Node<T>* tempAhead = head->next;

        // if linked list empty
        if(head == NULL)
        {
            cout << "There's no element in linked list" << endl;
            return;
        }

        //If only there's 1 element in linked list
        if(tail == head)
        {
            head = NULL;
            tail = NULL;
            delete(temp);
            return;
        }

        // first element will be delete
        if(head->data.id == id)
        {
            head = tempAhead;
            delete(temp);
            tail->next = head; // keep circular
            return;
        }

        //If searhing id at the end of the linked list
        if(tail->data.id == id)
        {
            while (tempAhead->next != head)
            {
                temp = temp->next;
                tempAhead = tempAhead->next;
            }
            temp->next = NULL;
            tail = temp;
            tail->next = head; // connecting circular linked listed again
            delete(tempAhead);
            return;
        }

        //If searching id between head and tail node
        while(tempAhead->next != head)
        {
            if(tempAhead->data.id == id)
            {
                temp->next = tempAhead->next;
                delete(tempAhead);
            }
            temp = temp->next;
            tempAhead = tempAhead->next;
        }
    }

    Node<T>* returnMovie(int movieId)
    {
        Node<T> *temp;

            temp = head;
        while (temp->next != head)
        {
            if (temp->data.id == movieId)
            {
                return temp;
            }
            temp = temp->next;
        }

        //check for last node
        if (temp->data.id == movieId)
        {
            return temp;
        }
        return NULL;
    }

    bool Check(int movieId)
    {
        Node<T> *temp;
        temp = head;
        while (temp->next != head)
        {
            if (temp->data.id == movieId)
            {
                return true;
            }
            temp = temp->next;
        }
        if (tail->data.id == movieId)
        {
            return true;
        }
        return false;
    }

    void displayShowMovie(int movieId)
    {
        Node<T> *temp;
        if(head == NULL)
        {
            cout << "empty list" << endl;
            return;
        }
        else
        {
            temp = head;
        }
        while (temp->next != head)
        {
            if(temp->data.id == movieId)
                cout << temp->data << " Not checked out "<< endl;
            temp = temp->next;
        }
        if(temp->data.id == movieId)
            cout << temp->data << " Not checked out"<< endl;
    }

    bool isEmpty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }


    void display() {
        Node<T> *temp;

        if(head == NULL)
        {
            cout << "empty list" << endl;
            return;
        }
        else
        {
            temp = head;
        }
        while (temp->next != head)
        {
            cout << temp->data << " Not checked out "<< endl;
            temp = temp->next;
        }
        cout << temp->data << " Not checked out"<< endl;
    };

    void displayUserCheckedOutList(int userId)
    {
        Node<T> *temp;

        if(head == NULL)
        {
            cout << "empty list" << endl; // DELETE
            return;
        }
        else
        {
            temp = head;
        }
        while (temp->next != head)
        {
            cout << temp->data << " Checked out by User " << userId << endl;
            temp = temp->next;
        }
        cout << temp->data << " Checked out by User " << userId << endl;
    }


    void displayShowUser(int userId)
    {
        Node<T> *temp;

        if(head == NULL)
        {
            return;
        }
        else
        {
            temp = head;
        }
        cout << "Movie id - Movie name - Year" << endl;
        while (temp->next != head)
        {
            cout << temp->data << " " << endl;
            temp = temp->next;
        }
        cout << temp->data << " " << endl;
    }
};


#endif //BBM201_ASSIGNMENT2_GENERICSINGLYLINKEDLIST_H
