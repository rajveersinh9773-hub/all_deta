#include <iostream>
using namespace std;

const int MAX_ITEMS = 100;

class LibraryItem 
{
private:
	string title;
	string author;
	string dueDate;

public:
	LibraryItem(string t="", string a="", string d="") 
	{
		title = t;
		author = a;
		dueDate = d;
	}

	string getTitle() 
	{
		return title;
	}
	string getAuthor() 
	{
		return author;
	}
	string getDueDate() 
	{
		return dueDate;
	}

	void setTitle(string t) 
	{
		title = t;
	}
	void setAuthor(string a) {
		author = a;
	}
	void setDueDate(string d) {
		dueDate = d;
	}

	virtual void checkOut() = 0;
	virtual void returnItem() = 0;
	virtual void displayDetails() = 0;

	virtual ~LibraryItem() {}
};

class Book : public LibraryItem 
{
private:
	string ISBN;
	int copies;

public:
	Book(string t="", string a="", string d="", string isbn="", int c=0)
		: LibraryItem(t, a, d) 
	{
		ISBN = isbn;
		copies = (c < 0 ? 0 : c); 
	}

	void checkOut() override 
	{
		if (copies > 0) {
			copies--;
			cout << "Book checked out.\n";
		} 
		else {
			cout << "No copies available!\n";
		}
	}

	void returnItem() override 
	{
		copies++;
		cout << "Book returned.\n";
	}

	void displayDetails() override 
	{
		cout << "[Book] " << getTitle()
		     << " | Author: " << getAuthor()
		     << " | Due: " << getDueDate()
		     << " | ISBN: " << ISBN
		     << " | Copies: " << copies << endl;
	}
};

class DVD : public LibraryItem 
{
private:
	int duration;

public:
	DVD(string t="", string a="", string d="", int dur=0)
		: LibraryItem(t, a, d) {
		duration = (dur < 0 ? 0 : dur);
	}

	void checkOut() override {
		cout << "DVD checked out.\n";
	}

	void returnItem() override {
		cout << "DVD returned.\n";
	}

	void displayDetails() override {
		cout << "[DVD] " << getTitle()
		     << " | Director: " << getAuthor()
		     << " | Due: " << getDueDate()
		     << " | Duration: " << duration << " mins" << endl;
	}
};

class Magazine : public LibraryItem 
{
private:
	int issueNumber;

public:
	Magazine(string t="", string a="", string d="", int issue=0)
		: LibraryItem(t, a, d) {
		issueNumber = (issue < 0 ? 0 : issue);
	}

	void checkOut() override {
		cout << "Magazine checked out.\n";
	}

	void returnItem() override {
		cout << "Magazine returned.\n";
	}

	void displayDetails() override {
		cout << "[Magazine] " << getTitle()
		     << " | Editor: " << getAuthor()
		     << " | Due: " << getDueDate()
		     << " | Issue: " << issueNumber << endl;
	}
};

int main() 
{
	LibraryItem* libraryItems[MAX_ITEMS];
	int itemCount = 0;
	int choice;

	do {
		cout << "\n===== Library Management System =====\n";
		cout << "1. Add Book\n";
		cout << "2. Add DVD\n";
		cout << "3. Add Magazine\n";
		cout << "4. Display All Items\n";
		cout << "5. Check Out Item\n";
		cout << "6. Return Item\n";
		cout << "7. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1) 
		{
			string t,a,d,isbn;
			int c;
			cout << "Enter title: ";
			cin >> ws;
			getline(cin,t);
			cout << "Enter author: ";
			getline(cin,a);
			cout << "Enter due date: ";
			getline(cin,d);
			cout << "Enter ISBN: ";
			getline(cin,isbn);
			cout << "Enter copies: ";
			cin >> c;
			libraryItems[itemCount++] = new Book(t,a,d,isbn,c);
		} 
		else if (choice == 2) {
			string t,a,d;
			int dur;
			cout << "Enter title: ";
			cin >> ws;
			getline(cin,t);
			cout << "Enter director: ";
			getline(cin,a);
			cout << "Enter due date: ";
			getline(cin,d);
			cout << "Enter duration (minutes): ";
			cin >> dur;
			libraryItems[itemCount++] = new DVD(t,a,d,dur);
		} 
		else if (choice == 3) {
			string t,a,d;
			int issue;
			cout << "Enter title: ";
			cin >> ws;
			getline(cin,t);
			cout << "Enter editor: ";
			getline(cin,a);
			cout << "Enter due date: ";
			getline(cin,d);
			cout << "Enter issue number: ";
			cin >> issue;
			libraryItems[itemCount++] = new Magazine(t,a,d,issue);
		} 
		else if (choice == 4) {
			for (int i=0; i<itemCount; i++) {
				libraryItems[i]->displayDetails();
			}
		} 
		else if (choice == 5) {
			string title;
			cout << "Enter title to check out: ";
			cin >> ws;
			getline(cin,title);
			bool found = false;
			for (int i=0; i<itemCount; i++) {
				if (libraryItems[i]->getTitle() == title) {
					libraryItems[i]->checkOut();
					found = true;
				}
			}
			if (!found) cout << "Item not found.\n";
		} 
		else if (choice == 6) {
			string title;
			cout << "Enter title to return: ";
			cin >> ws;
			getline(cin,title);
			bool found = false;
			for (int i=0; i<itemCount; i++) {
				if (libraryItems[i]->getTitle() == title) {
					libraryItems[i]->returnItem();
					found = true;
				}
			}
			if (!found) cout << "Item not found.\n";
		} 
		else if (choice == 7) {
			cout << "Exiting program...\n";
		} else {
			cout << "Invalid choice!\n";
		}

	} while(choice != 7);

	for (int i=0; i<itemCount; i++) {
		delete libraryItems[i];
	}

	return 0;
}
