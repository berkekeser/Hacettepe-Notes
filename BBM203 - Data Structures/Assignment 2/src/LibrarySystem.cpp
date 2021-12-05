//
// Created by Berke Keser on 1.12.2020.
//

#include "LibrarySystem.h"
#include <iostream>
#include "GenericDoublyLinkedList.h"
#include "GenericSinglyLinkedList.h"
#include <string.h>

using namespace std;


LibrarySystem::LibrarySystem() {
    cout << "===Movie Library System===" << endl;
}


void LibrarySystem::addMovie(const int movieId, const string movieTitle, const int year) {

    // Flags are controlling print method test label in output
    addUserFlag = 1;
    checkoutFlag = 1;
    showMovieFlag = 1;
    returnMovieFlag = 1;
    deleteMovieFlag = 1;
    showUserFlag = 1;

    if(addMovieFlag)
    {
        cout << endl;
        cout << "===addMovie() method test===" << endl;
        addMovieFlag = 0;
    }

    bool movieExist = movieLinkedList.checkIdExist(movieId);

    if (movieExist)
        cout << "Movie " << movieId << " already exists" << endl;
    else
    {
        Movie tempMovie(movieId, movieTitle, year);
        movieLinkedList.add(tempMovie);
        cout << "Movie " << movieId << " has been added"<< endl;
    }

}

void LibrarySystem::deleteMovie(const int movieId) {

    // Flags are controlling print method test label in output
    addUserFlag = 1;
    addMovieFlag = 1;
    checkoutFlag = 1;
    showMovieFlag = 1;
    returnMovieFlag = 1;
    showUserFlag = 1;

    bool movieExist = movieLinkedList.checkIdExist(movieId);
    int userId = userLinkedList.getUserIdFromMovieList(movieId);

    //delete movie from library
    if(deleteMovieFlag)
    {
        cout << endl;
        cout << "===deleteMovie() method test===" << endl;
        deleteMovieFlag = 0;
    }

    // delete movie from user
    if (movieExist)
    {
        movieLinkedList.removeById(movieId);
        cout << "Movie " << movieId << " has not been checked out" << endl;
        cout << "Movie " << movieId << " has been deleted" << endl;
    }
    else
    {
        if (userId != -1) // for checking user exist or not
        {
            Node2<User> *matchedUser = userLinkedList.getUser(userId);
            matchedUser->data.checkedOutList.removeById(movieId);
            cout << "Movie " << movieId << " has been checked out" << endl;
            cout << "Movie " << movieId << " has been deleted" << endl;
            return;
        }
        else{
            cout << "Movie " << movieId << " does not exist" << endl;
        }
    }

}

void LibrarySystem::addUser(const int userId, const string userName) {
    // Flags are controlling print method test label in output
    addMovieFlag = 1;
    checkoutFlag = 1;
    showMovieFlag = 1;
    returnMovieFlag = 1;
    deleteMovieFlag = 1;
    showUserFlag = 1;

    if (addUserFlag)
    {
        cout << endl;
        cout << "===addUser() method test===" << endl;
        addUserFlag = 0;
    }

    bool exist = userLinkedList.checkIdExist(userId);
    if(exist)
        cout << "User " << userId << " already exists" << endl;
    else
    {
        User tempUser(userId, userName);
        userLinkedList.add(tempUser);
        cout << "User " << userId << " has been added" << endl;
    }
}

void LibrarySystem::deleteUser(const int userId) {
    // Flags are controlling print method test label in output
    addUserFlag = 1;
    addMovieFlag = 1;
    checkoutFlag = 1;
    showMovieFlag = 1;
    returnMovieFlag = 1;
    deleteMovieFlag = 1;
    showUserFlag = 1;

    if (deleteUserFlag)
    {
        cout << endl;
        cout << "===deleteUser() method test===" << endl;
        deleteUserFlag = 0;
    }

    bool userExist = userLinkedList.checkIdExist(userId);

    if(!userExist)
    {
        cout << "User " << userId << " does not exist" << endl;
        return;
    }

    userLinkedList.removeById(userId);
    cout << "User " << userId << " has been deleted" << endl;

}

void LibrarySystem::checkoutMovie(const int movieId, const int userId) {
    // Flags are controlling print method test label in output
    addUserFlag = 1;
    addMovieFlag = 1;
    showMovieFlag = 1;
    returnMovieFlag = 1;
    deleteMovieFlag = 1;
    showUserFlag = 1;


    if (checkoutFlag)
    {
        cout << endl;
        cout << "===checkoutMovie() method test===" << endl;
        checkoutFlag = 0;
    }

    bool movieExist = movieLinkedList.checkIdExist(movieId);
    bool userExist = userLinkedList.checkIdExist(userId);

    if(!userExist)
    {
        cout << "User " << userId << " does not exist for checkout" << endl;
        return;
    }

    if(!movieExist)
    {
        cout << "Movie " << movieId << " does not exist for checkout" << endl;
        return;
    }

    Node<Movie> *matchedMovie = movieLinkedList.returnMovie(movieId);
    Node2<User> *matchedUser = userLinkedList.getUser(userId);
    matchedUser->data.checkedOutList.add(matchedMovie->data);

    // Delete Movie From MovieList
    movieLinkedList.removeById(movieId);
    cout << "Movie " << movieId << " has been checked out by User " << userId << endl;

}

void LibrarySystem::returnMovie(const int movieId) {
    // Flags are controlling print method test label in output
    addUserFlag = 1;
    addMovieFlag = 1;
    checkoutFlag = 1;
    showMovieFlag = 1;
    deleteMovieFlag = 1;
    showUserFlag = 1;

    if(returnMovieFlag)
    {
        cout << endl;
        cout << "===returnMovie() method test===" << endl;
        returnMovieFlag = 0;
    }

    int userId = userLinkedList.getUserIdFromMovieList(movieId);
    bool check = movieLinkedList.checkIdExist(movieId);

    if (check)
    {
        cout << "Movie " << movieId <<" has not been checked out" << endl;
        return;
    }

    if (userId == -1)
        cout << "Movie " << movieId <<" not exist in the library" << endl;
    else
    {
        Node2<User> *matchedUser = userLinkedList.getUser(userId);
        Node<Movie> *matchedMovie = matchedUser->data.checkedOutList.returnMovie(movieId);
        movieLinkedList.add(matchedMovie->data);
        matchedUser->data.checkedOutList.removeById(movieId);
        cout << "Movie " << movieId <<" has been returned" << endl;
    }

}

void LibrarySystem::showAllMovies() {
    cout << endl;
    cout << "===showAllMovie() method test===" << endl;
    cout << "Movie id - Movie name - Year - Status" << endl;
    movieLinkedList.display();
    userLinkedList.displayCheckedMovies();

}

void LibrarySystem::showMovie(const int movieId) {
    // Flags are controlling print method test label in output
    addUserFlag = 1;
    addMovieFlag = 1;
    checkoutFlag = 1;
    returnMovieFlag = 1;
    deleteMovieFlag = 1;
    showUserFlag = 1;

    if (showMovieFlag == 1)
    {
        cout << endl;
        cout << "===showMovie() method test===" << endl;
        showMovieFlag = 0;
    }

    bool movieExist = movieLinkedList.checkIdExist(movieId);
    int userId = userLinkedList.getUserIdFromMovieList(movieId);

    if (!movieExist)
    {
        if(userId == -1)
        {
            cout << "Movie with the id " << movieId << " does not exist" << endl;
            return;
        }
    }

    if(userId != -1)
    {
        Node2<User> *matchedUser = userLinkedList.getUser(userId);
        matchedUser->data.checkedOutList.displayUserCheckedOutList(userId);
    }

    movieLinkedList.displayShowMovie(movieId);
}

void LibrarySystem::showUser(const int userId) {

    // Flags are controlling print method test label in output
    addUserFlag = 1;
    addMovieFlag = 1;
    checkoutFlag = 1;
    showMovieFlag = 1;
    returnMovieFlag = 1;
    deleteMovieFlag = 1;

    if(showUserFlag == 1)
    {
        cout << endl;
        cout << "===showUser() method test===" << endl;
        showUserFlag = 0;
    }

    bool exist = userLinkedList.checkIdExist(userId);

    if(exist)
    {
        Node2<User> *matchedUser = userLinkedList.getUser(userId);
        cout << "User id: " << userId << " User name: " << matchedUser->data.fullName << endl;
        cout << "User "<< userId << " checked out the following Movies:" << endl;
        matchedUser->data.checkedOutList.displayShowUser(userId);
    }
    else{
        cout << "User " << userId << " does not exist" << endl;
    }
}

LibrarySystem::~LibrarySystem() {

}

Movie::Movie(int _id, string _title, int _year)
{
    id= _id;
    title = _title;
    year = _year;
}

Movie::Movie() {

}


User::User(int _id, string _fullName) {
    id = _id;
    fullName = _fullName;
}

User::User() {

}

ostream &operator<<(ostream &stream, Movie ob) {
    stream << ob.id << " " << ob.title << " " << ob.year;

    return stream;
}

ostream &operator<<(ostream &stream, User ob) {
    stream << ob.id << " " << ob.fullName;

    return stream;
}

User::~User() {

};