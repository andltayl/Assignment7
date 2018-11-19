/*****************************************************************************
 * File: list_db.cpp
 * Name: Joshua T. Guerin and Xiangdong An
 * Purpose: Demonstrate using a linked list of structs.
 *****************************************************************************/


#include <iostream>
#include <list>
#include "Library.h"

using namespace std;

int main() {

	Library books;

	books.read_from_file("books.txt");
	books.print();
	books.write_to_file("test_output.txt");
	books.find_book("to");






	/*
	/* A simple linked list-based book DB 
	list<book> books;

	book temp;
	/* Create a temporary book 
	temp.title = "Pi Adventure";
	temp.author = "Darren Aronofsky";

	/*Add the book to our list 
	books.push_back(temp);


	/* Create a second temporary book 
	temp.title = "Star Wars";
	temp.author = "George Lucas";


	/* Add the book to a list 
	books.push_back(temp);



	list<book>::iterator it;

	/* Iterate over the list and print the contents (2 books) 
	cout << "List of 2 items" << endl;
	for (it = books.begin(); it != books.end(); it++) {
		cout << "List item: " << it->author << " - " << it->title << endl;
	}
	cout << endl << endl;


	/* Create a third book 
	temp.title = "Primer";
	temp.author = "Carruth";


	/* Insert the third book in alphabetical order (will between Aronofsky and Lucas) 
	it = books.begin();
	//Book iterator to the correct location.
	it++;


	/* Insert the book using list.insert() 
	books.insert(it, temp);


	cout << "List of 3 items:" << endl;
	/* Iterate over the list and print the contents (3 books) 
	for (it = books.begin(); it != books.end(); it++) {
		cout << "List item: " << it->author << " - " << it->title << endl;
	}
	*/


	return 0;
}
