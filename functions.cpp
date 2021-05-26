#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "functions.hpp"
using namespace std;

//main file
fstream myfile;

//user input variables
string user_name;
string user_author;
int user_stock;
int line_delete;


//Check for Error regarding opening files
void error() {

    if(myfile.fail()) {

        cerr << "Error Opening File";
        exit(1);

    }

}


//Introduction
void intro() {

    int option;

    cout << "\n";

    cout << "[1] ADD BOOK \n";
    cout << "[2] SHOW BOOKS (NAME, AUTHOR, QUANTITY) \n";
    cout << "[3] DELETE BOOK \n";
    cout << "[4] EXIT \n";
    cout << "Enter the option:  ";
    cin >> option;

    switch (option) {

        case 1:
            add_book_details();
            add_book_to_datafile();
            cout << "\n";
            intro();
            break;
        case 2:
            show_book();
            intro();
            break;
        case 3:
            cout << "\n";
            delete_line_in_datafile();
            cout << "\n";
            cout << "Line Deleted";
            intro();
            break;
        case 4:
            cout << "\n";
            cout << "Terminated\n";
            break;
        default:
            cout << "Invalid Choice\n";
            break;


    }
}



//user input for adding book
void add_book_details() {
    cout << "\n";

    cout << "What is the name of the book (no spaces): ";
    cin >> user_name;

    cout << "Who wrote the book (no spaces): ";
    cin >> user_author;

    cout << "What is the book's quantity: ";
    cin >> user_stock; 

}

//adding book to book_data.txt
void add_book_to_datafile() {

    myfile.open("book_data.txt", ios::app); //to append multiple lines rather than replacing lines
    myfile << user_name << "," << user_author << "," << user_stock << endl;
    myfile.close();

}

//showing the list of all the books
void show_book() {

    myfile.open("book_data.txt", ios::in);

    //line variable
    string line;

    
    cout << "\n";
    
    // itterating through everything in the book_data.txt file
    while (getline(myfile, line)) {
        cout << line << endl;
    }

    myfile.close();

    

}


//deleting book from book_data.txt

void delete_line_in_datafile() {

    show_book();
    cout << "\n";

    string line, name;
    cout << "Please Enter the name of book you want to delete (one line): ";
    cin >> name;
    ifstream myfile;
    myfile.open("book_data.txt");
    ofstream temp;
    temp.open("temp.txt");

    while (getline(myfile, line)) {

        if (line.substr(0, name.size()) != name) {

            temp << line << endl;   

        }
    

    }

    cout << "The record with the name " << name << " has been deleted if it exsisted" << endl;
    myfile.close();
    temp.close();
    remove("book_data.txt");
    rename("temp.txt", "book_data.txt");

    system("pause");

}