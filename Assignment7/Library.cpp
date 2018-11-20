#include "Library.h"



Library::Library()
{
	// Not Needed.
}


Library::~Library()
{
	// Not Needed.
}

void Library::insert_sorted(book addBook)
{
	list<book>::iterator it = books.begin();
	int currChar = 0;
	int shortestTitle = 0;

	if (books.empty()) {										// Check if this is the first book to be added to the library.
		books.push_back(addBook);								// If so then add it and return.
		return;
	}

	if (addBook.title.length() < it->title.length()) {			// In case of duplicate titles find the shorter one.
		shortestTitle = addBook.title.length();
	}
	else if (addBook.title.length() > it->title.length()) {
		shortestTitle = it->title.length();
	}
	else {														// If same length.
		shortestTitle = addBook.title.length();
	}
	
	while (currChar < shortestTitle) {							// Compare each char until one is bigger, up until the last char of the shortest title.
		if (it == books.end()) {								// If we are at the end of the list just insert the book.
			books.push_back(addBook);
			return;
		}
		else if (addBook.title[currChar] < it->title[currChar]) {	// If the new book is less insert it where the iterator currently is.
			books.insert(it, addBook);
			return;
		}
		else if (addBook.title[currChar] > it->title[currChar]) {	// If the new book is bigger go to next book in list.
			it++;
		}
		else {														// If the chars are equal then go to the next char in each title and loop again.
			currChar++;
		}
	}
	books.insert(it, addBook);		// If the titles are the same up to the last char of the shortest title insert the book before the longer one.
	return;
}

void Library::read_from_file(string filename)
{
	ifstream iFile;

	iFile.open(filename.c_str());

	while (iFile) {
		book temp;
		string tempName;
		bool loop = true;

		getline(iFile, temp.title);
		
		while (loop){										// Add the multiple author names if there are more than one.
			getline(iFile, tempName);
			
			if (tempName[tempName.size() - 1] == '*') {		// Remove the star from the last author name.
				tempName.pop_back();
				loop = false;
			}

			temp.aNames.push_back(tempName);
		}

		iFile >> temp.price;
		iFile >> temp.year;

		insert_sorted(temp);

		iFile.get();		// Throw away newline character.
	}

	iFile.close();
}

void Library::print()
{
	list<book>::iterator temp = books.begin();

	while (temp != books.end()) {
		cout << "Title: " << temp->title << '\n';
		cout << "Authors: " << endl;

		list<string>::iterator it;

		for (it = temp->aNames.begin(); it != temp->aNames.end(); it++) {		// Print all author names.
			cout << *it << endl;
		}

		cout << "Year Published: " << temp->year << '\n';

		cout << fixed << setprecision(2) << "Price: $" << temp->price << '\n' << endl;

		temp++;
	}
}

void Library::find_book(string name)
{
	list<book>::iterator temp = books.begin();
	Library results;

	while (temp != books.end()) {							// Search all the books in the library for the string.
		if (temp->title.find(name) != std::string::npos) {
			results.insert_sorted(*temp);
		}
		temp++;
	}
	results.print();
}

void Library::author_search(string name)
{
	list<book>::iterator temp = books.begin();
	Library results;
	list<string>::iterator it;

	while (temp != books.end()) {							// Search all the books in the library for the string.
		for (it = temp->aNames.begin(); it != temp->aNames.end(); it++) {		// Search all author names.
			if (it->find(name) != std::string::npos) {
				results.insert_sorted(*temp);
			}
		}
		temp++;
	}
	results.print();
}

void Library::remove(string name)
{
	list<book>::iterator temp = books.begin();
	list<book>::iterator next = temp;
	next++;
	
	list<string>::iterator it;

	while (temp != books.end()) {							// Search all the books in the library for the string.
		for (it = temp->aNames.begin(); it != temp->aNames.end(); it++) {		// Search all author names and titles.
			if (it->find(name) != std::string::npos || temp->title == name) {
				books.erase(temp);
				temp = next;
				break;
			}
		}

		if (temp != next) {
			temp++;
		}
		if (next != books.end()) {
			next++;
		}
	}
}

void Library::write_to_file(string filename)
{
	ofstream oFile;
	oFile.open(filename.c_str());

	list<book>::iterator temp = books.begin();

	while (temp != books.end()) {						// Works essentially the same as the print function.
		if (temp != books.begin())
		{
			oFile << endl;
		}
		oFile << temp->title;

		list<string>::iterator it;

		for (it = temp->aNames.begin(); it != temp->aNames.end(); it++) {
			oFile << '\n' << *it;
		}
		oFile << '*' << '\n';							// Replace the star to indicate the final author name in the file.
		
		oFile << temp->price << endl;
		oFile << temp->year;

		temp++;
	}

	oFile.close();
	
}
