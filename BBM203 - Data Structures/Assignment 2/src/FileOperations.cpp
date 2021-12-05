//
// Created by Berke Keser on 1.12.2020.
//

#include "FileOperations.h"
#include "string.h"
using namespace std;


void FileOperations::style_tokenizer(string inp, char* delim, LibrarySystem &library2) {

    const char *c_string = inp.c_str();

    char *token = strtok((char *) c_string, delim);

    while(token)
    {

        if (strcmp(token, "addUser") == 0 || strcmp(token, "addUser\r") == 0)
        {
            token = strtok(NULL, delim);
            int userId = atoi(token);

            token = strtok(NULL, delim);
            string userFullName = token;
            library2.addUser(userId, userFullName);
        }

        if(strcmp(token, "addMovie") == 0)
        {

            token = strtok(NULL, delim);
            int movieId = atoi(token);

            token = strtok(NULL, delim);
            string movieTitle = token;

            token = strtok(NULL, delim);
            int movieYear = atoi(token);

            library2.addMovie(movieId, movieTitle, movieYear);
        }

        if (strcmp(token, "showAllMovie") == 0 || strcmp(token, "showAllMovie\r") == 0)
        {
            library2.showAllMovies();
        }

        if(strcmp(token, "deleteMovie") == 0)
        {
            token = strtok(NULL, delim);
            int deleteMovieId = atoi(token);
            library2.deleteMovie(deleteMovieId);
        }

        if(strcmp(token, "checkoutMovie") == 0)
        {
            token = strtok(NULL, delim);
            int movieId = atoi(token);
            token = strtok(NULL, delim);
            int userId = atoi(token);
            library2.checkoutMovie(movieId, userId);
        }

        if(strcmp(token, "returnMovie") == 0)
        {
            token = strtok(NULL, delim);
            int movieId = atoi(token);
            library2.returnMovie(movieId);
        }

        if(strcmp(token, "showMovie") == 0)
        {
            token = strtok(NULL, delim);
            int movieId = atoi(token);
            library2.showMovie(movieId);
        }

        if(strcmp(token, "showUser") == 0)
        {
            token = strtok(NULL, delim);
            int userId = atoi(token);
            library2.showUser(userId);
        }

        if(strcmp(token, "deleteUser") == 0)
        {
            token = strtok(NULL, delim);
            int userId = atoi(token);
            library2.deleteUser(userId);
        }

        token = strtok(NULL, delim);
    }
}

void FileOperations::readCommandsFile(string name, LibrarySystem library) {

    ifstream commandsFile;
    commandsFile.open(name);
    if(!commandsFile)
    {
        cout << name << " file does not exist" << endl;
        exit(1); // if file does not exist terminate
    }

    string line;

    while(getline(commandsFile, line))
    {
        style_tokenizer(line, (char*) "\t", library);
    }

    commandsFile.close();
}
