/*
 * Author: Anderson Taylor & Trey Howell
 * Date: 11/19/18
 * File: Library.h
 * Description: Header file for the Library class..
 */
#pragma once
#include <string>
#include <fstream>
#include <iomanip>
#include <list>
#include <iostream>

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
private:
	list<book> books;
};

