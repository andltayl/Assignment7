#pragma once
#include <string>
 
using namespace std;

struct book {
	string title;
	list<string> aNames;
	float price;
	int year;
};

class Library
{
public:
	Library();
	~Library();
	void insert_sorted(book addBook);
	void read_from_file(string filename);
	void print();
	void find_book(string name);
	void author_search(string name);
	void remove(string name);
	void write_to_file(string filename);
};
