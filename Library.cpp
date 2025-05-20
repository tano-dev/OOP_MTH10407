#include<iostream>
#include<string>
#include<list>

using namespace std;

class Book;
class BorrowerRecord;
class Library;

class Book {
    //attributes
    string number;
    string author;
    string title;
    BorrowerRecord* borrower;
public:
    //default constructor
    Book() {
        this->number = "N/A";
        this->author = "N/A";
        this->title = "N/A";
        this->borrower = nullptr;
    }
    //constructor
    Book(string number, string author, string title) {
        this->setNumber(number);
        this->setAuthor(author);
        this->setTitle(title);
        this->setBorrower(nullptr);
    }
    //Access methods
    //setters()
    void setNumber(string number) {
        this->number = number;
    }
    void setAuthor(string author) {
        this->author = author;
    }
    void setTitle(string title) {
        this->title = title;
    }
    void setBorrower(BorrowerRecord* br);
    //getters()
    string getNumber() {
        return this->number;
    }
    string getAuthor() {
        return this->author;
    }
    string getTitle() {
        return this->title;
    }
    //display()
    void display();
    //Book <-> Borrower
    BorrowerRecord* getBorrower();
    void attachBorrower(BorrowerRecord* br);
    void detachBorrower();
    //Available Book
    bool isBookAvailableForLoan() {
        return this->getBorrower() == nullptr;
    }
};

class BorrowerRecord {
    string theName;
    list<Book*> books;
public:
    //constructors
    BorrowerRecord() {
        this->theName = "N/A";
    }
    BorrowerRecord(string theName) {
        this->setTheName(theName);
    }
    //Access methods
    //setters
    void setTheName(string theName) {
        this->theName = theName;
    }
    //getters
    string getTheName() {
        return this->theName;
    }
    //display
    void display();
    //attach a book
    void attachBook(Book* b);
    //detachBook
    void detachBook(Book* b);
};

class Library {
    string name;
    list<Book*> stock;
    list<BorrowerRecord*> borrowers;
public:
    //Constructors
    Library() {
        this->name = "N/A";
    }

    Library(string name) {
        this->setName(name);
    }
    //Access methods
    //setter
    void setName(string name) {
        this->name = name;
    }
    //getter
    string getName() {
        return this->name;
    }
    //display
    void display();
    //addOneBook()
    void addOneBook(Book* book);
    //Register
    void registerOneB(string name);
    //getStock
    list<Book*> getStock();
    //getBorrower
    list<BorrowerRecord*> getBorrowers();
    //lend 1 book
    void lendOneBook(string ID, string borrowerName);
    //return 1 book
    void returnOneBook(string ID);
    //displayBookAvailableForLoan()
    void displayBookAvailableForLoan();
    //display BOnLoan
    void displayBookOnLoan();
    //diplay all book
    void displayAllB();
    //display all borrower
    void displayABor();
    //destructor
    ~Library();
};
//Book:
//display
void Book::display() {
    cout << "Number: " << this->getNumber() << endl;
    cout << "Author: " << this->getAuthor() << endl;
    cout << "Title: " << this->getTitle() << endl << endl;
}

//Book <-> Borrower
void Book::setBorrower(BorrowerRecord* br) {
    this->borrower = br;
}
BorrowerRecord* Book::getBorrower()
{
    return this->borrower;
}
void Book::attachBorrower(BorrowerRecord* br) {
    setBorrower(br);
    borrower->attachBook(this);
}
void Book::detachBorrower() {
    BorrowerRecord* br = this->getBorrower();
    if (br) {
        br->detachBook(this);
    }
    br->detachBook(nullptr);
}

//Borrower:
//display
void BorrowerRecord::display() {
    cout << "Borrower's Name: " << this->getTheName() << endl << endl;
}
//attach a book
void BorrowerRecord::attachBook(Book* b) {
    this->books.push_back(b);
}
//detachBook
void BorrowerRecord::detachBook(Book* b) {
    this->books.remove(b);
}

//Library:
//add1book
void Library::addOneBook(Book* book) {
    this->stock.push_back(book);
}
//re1bor
void Library::registerOneB(string name) {
    this->borrowers.push_back(new BorrowerRecord(name));
}
//getStock
list<Book*> Library::getStock() {
    return stock;
}//getBorrower
list<BorrowerRecord*> Library::getBorrowers() {
    return borrowers;
}
//lend 1 book
void Library::lendOneBook(string ID, string borrowerName) {
    //find book
    Book* book = nullptr;
    for (Book* b : this->getStock()) {
        if (b->getNumber() == ID) {
            book = b;
            break;
        }
    }
    if (!book) {
        cout << "BOOK NOT FOUND!" << endl << endl;
        return;
    }
    if (!book->isBookAvailableForLoan()) {
        cout << "BOOK IN LOAN" << endl << endl;
        return;
    }
    //find borrower
    BorrowerRecord* borrower = nullptr;
    for (BorrowerRecord* br : this->getBorrowers()) {
        if (br->getTheName() == borrowerName) {
            borrower = br;
            break;
        }
    }
    if (!borrower) {
        cout << "Borrower not found! " << endl << endl;
        return;
    }
    book->attachBorrower(borrower);
    cout << "\nBook: " << book->getTitle() << endl << "Lend borrower: " << borrower->getTheName() << endl << endl;
}
//return one book
void Library::returnOneBook(string ID) {
    //find book
    Book* book = nullptr;
    for (Book* b : this->getStock()) {
        if (b->getNumber() == ID) {
            book = b;
            break;
        }
    }
    if (!book) {
        cout << "BOOK NOT FOUND!" << endl << endl;
        return;
    }
    if (book->isBookAvailableForLoan()) {
        cout << "BOOK IS AVAILABLE FOR LOAN" << endl << endl;
        return;
    }
    BorrowerRecord* borrower = book->getBorrower();
    book->detachBorrower();
    cout << "\nBook: " << book->getTitle() << " Was returned\n\n";
}

void Library::displayBookAvailableForLoan() {
    cout << "Book is available for loan: " << endl;
    bool found = false;
    for (auto i : this->stock) {
        if (i->isBookAvailableForLoan()) {
            i->display();
            found = true;
        }
    }
    if (!found) {
        cout << "No books are available for loan" << endl;
    }
}
void Library::displayBookOnLoan() {
    cout << "Book is on loan: " << endl;
    bool found = false;
    for (auto i : this->stock) {
        if (!i->isBookAvailableForLoan()) {
            i->display();
            found = true;
        }
    }
    if (!found) {
        cout << "No books are currently on loan" << endl;
    }
}
//display
void Library::display() {
    cout << "Library's Name: " << this->getName() << endl << endl;
}
//dispaly All Books
void Library::displayAllB() {
    cout << "Books in Lbrary: " << endl;
    for (auto i : this->stock) {
        cout << "Book: " << endl;
        i->display();
        cout << endl;
    }
}
//display All Borrowers
void Library::displayABor() {
    cout << "Borrowers: " << endl;
    for (auto i : this->borrowers) {
        i->display();
        cout << endl;
    }
}
//destructor
Library::~Library() {
    for (auto i : this->borrowers) {
        delete (i);
    }
}

//int main() {
//    cout << "The Library Application\n" << endl;
//
//    Book* first = new Book("000", "Aso Haro", "Alice in Borderland");
//
//    Book second("001", "Ha Van Thao", "Co so lap trinh huong doi tuong");
//
//    Library l1("THU VIEN");
//    l1.display();
//
//    l1.addOneBook(first);
//    l1.addOneBook(&second);
//    l1.displayAllB();
//
//    l1.registerOneB("Quang");
//    l1.registerOneB("Nam");
//    l1.registerOneB("Minh");
//
//    l1.displayABor();
//    l1.displayBookAvailableForLoan();
//    l1.displayBookOnLoan();
//
//    l1.lendOneBook("001", "Quang");
//    l1.lendOneBook("003", "Nam");
//    l1.lendOneBook("001", "Minh");
//    l1.lendOneBook("000", "Hung");
//
//    l1.displayBookOnLoan();
//
//    l1.returnOneBook("001");
//    l1.returnOneBook("000");
//    l1.returnOneBook("003");
//    delete(first);
//    return 0;
//}