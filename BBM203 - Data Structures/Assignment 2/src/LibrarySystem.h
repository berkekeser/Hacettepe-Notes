
#ifndef BBM201_ASSIGNMENT2_LIBRARYSYSTEM_H
#define BBM201_ASSIGNMENT2_LIBRARYSYSTEM_H

#include <iostream>
#include <fstream>
#include <string.h>
#include "GenericSinglyLinkedList.h"
#include "GenericDoublyLinkedList.h"

using namespace std;

class Movie {
public:
    int id;
    string title;
    int year;
    Movie();
    Movie(int _id, string _title , int _year);
    friend ostream &operator<<(ostream &stream, Movie ob);
};

class User
{
public:
    int id;
    string fullName;
    GenericSinglyLinkedList<Movie> checkedOutList;
    User();
    User(int id, string fullName);
    friend ostream &operator<<(ostream &stream, User ob);
    ~User();

};

class LibrarySystem {
public:
    GenericSinglyLinkedList<Movie> movieLinkedList;
    GenericDoublyLinkedList<User> userLinkedList;
    int addUserFlag = 1;
    int addMovieFlag = 1;
    int checkoutFlag = 1;
    int showMovieFlag = 1;
    int returnMovieFlag = 1;
    int deleteMovieFlag = 1;
    int showUserFlag = 1;
    int deleteUserFlag = 1;
    LibrarySystem();
    ~LibrarySystem(); // destructor.

    void addMovie(const int movieId, const string movieTitle, const int year);
    void deleteMovie(const int movieId);

    void addUser(const int userId, const string userName);
    void deleteUser(const int userId);

    void checkoutMovie(const int movieId, const int userId);
    void returnMovie(const int movieId);

    void showAllMovies();
    void showMovie(const int movieId);
    void showUser(const int userId);
};

#endif //BBM201_ASSIGNMENT2_LIBRARYSYSTEM_H
