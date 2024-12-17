#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int id[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float price[10] = {100, 10, 239, 50, 60, 70, 80, 8, 90, 25};
    int availableCopies[10] = {1, 1, 1, 1, 1, 1, 9, 9, 5, 3};
    string title[10] = {
        "Programming 1", "Programming 2", "Programming 3", "Programming 4", "Programming 5",
        "Programming 6", "Programming 7", "Programming 8", "Programming 9", "Programming 10"};
    string author[10] = {
        "Author 1", "Author 2", "Author 3", "Author 4", "Author 5",
        "Author 6", "Author 7", "Author 8", "Author 9", "Author 10"};

public:
    Book() {
        int choice;
        cout << "1. ISSUE BOOK" << endl;
        cout << "2. RETURN BOOK" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            issueBook();
        } else if (choice == 2) {
            returnBook();
        } else {
            cout <<"Invalid choice!"<< endl;
        }
    }

    void issueBook() {
        int bookId;
        cout <<"Enter the ID of the book you want to issue (1-10):";
        cin >>bookId;

        if (bookId >= 1 && bookId <= 10) {
            int index = bookId - 1;
            if (availableCopies[index] > 0) {
                availableCopies[index]--;
                cout << "Book issued successfully!" << endl;
                cout << "Title: " << title[index] << ", Author: " << author[index] << endl;
            } else {
                cout << "Sorry, the book is out of stock." << endl;
            }
        } else {
            cout << "Invalid book ID!" << endl;
        }
    }

    void returnBook() {
        int bookId;
        cout << "Enter the ID of the book you want to return (1-10): ";
        cin >> bookId;

        if (bookId >= 1 && bookId <= 10) {
            int index = bookId - 1;
            availableCopies[index]++;
            cout << "Book returned successfully!" << endl;
        } else {
            cout << "Invalid book ID!" << endl;
        }
    }
};

int main() {
    Book b1;
    return 0;
}
