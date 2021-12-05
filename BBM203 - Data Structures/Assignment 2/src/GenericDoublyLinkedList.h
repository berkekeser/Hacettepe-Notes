//
// Created by Berke Keser on 2.12.2020.
//

#ifndef BBM201_ASSIGNMENT2_GENERICDOUBLYLINKEDLIST_H
#define BBM201_ASSIGNMENT2_GENERICDOUBLYLINKEDLIST_H

#include "iostream"
#include <string.h>
#include "LibrarySystem.h"


using namespace std;

template<class K>
struct Node2{
    K data;
    Node2<K> *next;
    Node2<K> *prev;
};

template<class K>
class GenericDoublyLinkedList {
public:
    Node2<K> *head;
    Node2<K> *tail;

    GenericDoublyLinkedList<K>() {
        head = NULL;
        tail = NULL;
    }

    void add(K data) {

        if(head == NULL)
        {
            head = new Node2<K>;
            head->data = data;
            head->next = head;
            tail = head;
            head->prev = tail;

        }
        else
        {
            Node2<K> *newNode = new Node2<K>;
            tail->next = newNode;
            newNode->data = data;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }

    void display() {
        Node2<K> *temp;
        temp = head;
        if(head == NULL)
        {
            cout << "empty list" << endl; // DELETE
            return;
        }
        else
        {
            while (temp != tail)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
            cout << tail->data << endl;
        }

    }

    bool checkIdExist(int id)
    {
        struct Node2<K> *temp = head;

        if(temp == NULL)
            return false;

        if(tail->data.id == id)
        {
            return true;
        }

        while (temp != tail)
        {
            if(temp->data.id == id)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    Node2<K>* getUser(int userId)
    {
        struct Node2<K> *temp = head;

        if(tail->data.id == userId)
        {
            return tail;
        }

        while(temp != tail)
        {
            if(temp->data.id == userId)
            {
                return temp;
            }
            temp = temp->next;

        }
    }


    int getUserIdFromMovieList(int movieId)
    {
//        cout << movieId << " ((((DENEME" << endl;
        struct Node2<K> *temp = head;
        int userId = -1;

        int counter = 1;
        // tail icin kontrol ekle

        if (head == NULL)
            return  -1;

        while (temp != tail) // iterate user
        {
            if(!temp->data.checkedOutList.isEmpty())
            {
                bool check = temp->data.checkedOutList.Check(movieId);
                if (check)
                    return temp->data.id;
            }
            temp = temp->next;
        }

        // for the last node
        if(!temp->data.checkedOutList.isEmpty())
        {
            bool check = temp->data.checkedOutList.Check(movieId);
            if (check)
                return temp->data.id;
        }

        return userId;
    }


    void displayCheckedMovies()
    {
        struct Node2<K> *temp = head;
        while (temp != tail)
        {
            if(!temp->data.checkedOutList.isEmpty())
            {
                temp->data.checkedOutList.displayUserCheckedOutList(temp->data.id);
            }
            temp = temp->next;
        }
        if(!temp->data.checkedOutList.isEmpty())
        {
            temp->data.checkedOutList.displayUserCheckedOutList(temp->data.id);
        }
    }


    void removeById(int id){
        struct Node2<K>* temp = head;
        struct Node2<K>* tempAhead = head->next;


        // if linked list empty
        if(head == NULL)
        {
            cout << "There's no user in linked list" << endl;
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
            head->prev = tail;
            tail->next = head; // keep circilar
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
            tail = temp;
            tail->prev = temp->prev;
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
                tempAhead->next->prev = temp;
                delete(tempAhead);
            }
            temp = temp->next;
            tempAhead = tempAhead->next;
        }
    }
};


#endif //BBM201_ASSIGNMENT2_GENERICDOUBLYLINKEDLIST_H
