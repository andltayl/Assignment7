/*
 * Author: Anderson Taylor & Trey Howell
 * Date: 11/19/18
 * File: main.cpp
 * Description: Main driver for the Library class implementation.
 */
#include <iostream>
#include <list>
#include "Library.h"

using namespace std;

int main() {

  Library library;
  string ifilename;
  string ofilename;
  string name;
  string Btitle;
  string first_name, last_name;
  int c = 0;

  while (c != 8) {
    cout << endl;
    cout << "Please select an option to perform" << endl;
    cout << "1. Insert a book sorted by title" << endl;
    cout << "2. Read from a file and insert to a list" << endl;
    cout << "3. Print out all books in the list" << endl;
    cout << "4. Find and print a book by keyword in title" << endl;
    cout << "5. Print out all books written by an author" << endl;
    cout << "6. Remove a certain book by title or author name" << endl;
    cout << "7. Write to a file" << endl;
    cout << "8. Exit" << endl;
    cin >> c;
    cout << endl;

    if (c == 1) {
      book temp;
      cout << "Enter a book title: " << endl;
      cin.get();
      getline(cin, temp.title);
      cout << endl;
      cout << "Enter author please: " << endl;
      cin >> first_name >> last_name;
      first_name += (" " + last_name);
      temp.aNames.push_back(first_name);
      cout << endl;
      cout << "Enter price please: " << endl;
      cin >> temp.price;
      cout << endl;
      cout << "Enter the year it was published: " << endl;
      cin >> temp.year;
      cout << endl;
      library.insert_sorted(temp);
    }
    if (c == 2) {
      cout << "Enter a file to read from: " << endl;
      cin >> ifilename;
      library.read_from_file(ifilename);
    }
    if (c == 3) {
      library.print();
    }
    if (c == 4) {
      cout << "Enter a string to search for: " << endl;
      cin >> name;
      cout << endl;
      library.find_book(name);
    }
    if (c == 5) {
      cout << "Please enter an authors full name to search for: " << endl;
      cin >> first_name >> last_name;
      first_name += (" " + last_name);
      cout << endl;
      library.author_search(first_name);
    }
    if (c == 6) {
      cout << "Please enter a title or author name to remove all related books: " << endl;
      cin.get();
      getline(cin, Btitle);
      cout << endl;
      library.remove(Btitle);
    }
    if (c == 7) {
      cout << "Please enter a file name to write to: " << endl;
      cin >> ofilename;
      library.write_to_file(ofilename);
    }
  }
  return 0;
}
