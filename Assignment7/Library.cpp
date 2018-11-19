#include "Library.h"



Library::Library()
{

}


Library::~Library()
{

}

void Library::insert_sorted(book addBook)
{

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
		
		while (loop){
			getline(iFile, tempName);
			
			if (tempName[tempName.size() - 1] == '*') {
				tempName.pop_back();
				loop = false;
			}

			temp.aNames.push_back(tempName);
		}

		iFile >> temp.price;
		iFile >> temp.year;

		insert_sorted(temp);

		iFile.get();
	}

	iFile.close();
}

void Library::print()
{
	list<book>::iterator temp = books.begin();

	while (temp != books.end()) {
		cout << "Title: " << temp->title << '\n';
		cout << fixed << setprecision(2) << "Price: $" << temp->price << '\n' << endl;

		temp++;
	}
}

void Library::find_book(string name)
{

}

void Library::author_search(string name)
{

}

void Library::remove(string name)
{

}

void Library::write_to_file(string filename)
{
	/*
	ofstream oFile;
	oFile.open(file.c_str());
	node * temp = head;

	while (temp != NULL) {
		oFile << '\n' << temp->first_name << " " << temp->last_name << '\n';
		oFile << fixed << setprecision(2) << temp->salary;

		temp = temp->next;
	}

	oFile.close();
	*/
}
