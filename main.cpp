#include <iostream>
#include <string>
#include "DoublyLinkedList.h"

using namespace std;

int main()
{
    DoublyLinkedList session;

    session.InsertRight(
        new dNode(101, "Data Structures")
    );

    session.InsertRight(
        new dNode(102, "Database Systems")
    );

    session.InsertRight(
        new dNode(103, "Operating Systems")
    );

    int choice;

    do
    {
        cout << "\n===== LIBRARY BORROWING SESSION =====\n";

        cout << "1. Display Current Book\n";
        cout << "2. Move to Next Book\n";
        cout << "3. Move to Previous Book\n";
        cout << "4. Insert Book at the End\n";
        cout << "5. Insert Book After Current Book\n";
        cout << "6. Remove Current Book\n";
        cout << "7. Display Session from First to Last\n";
        cout << "8. Display Session from Last to First\n";
        cout << "9. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                session.PrintCurrent();
                break;
            }

            case 2:
            {
                session.Next();
                break;
            }

            case 3:
            {
                session.Previous();
                break;
            }

            case 4:
            {
                int id;
                string title;

                cout << "Enter Book ID: ";
                cin >> id;

                cin.ignore();

                cout << "Enter Book Title: ";
                getline(cin, title);

                session.InsertRight(
                    new dNode(id, title)
                );

                cout << "Book inserted at the end.\n";

                break;
            }

            case 5:
            {
                int id;
                string title;

                cout << "Enter Book ID: ";
                cin >> id;

                cin.ignore();

                cout << "Enter Book Title: ";
                getline(cin, title);

                session.InsertAfterCurrent(
                    new dNode(id, title)
                );

                break;
            }

            case 6:
            {
                dNode* removed = session.RemoveCurrent();

                if (removed != nullptr)
                {
                    cout << "Removed Book: "
                         << removed->bookID << " - "
                         << removed->title << endl;

                    delete removed;
                }

                break;
            }

            case 7:
            {
                session.PrintForward();
                break;
            }

            case 8:
            {
                session.PrintBackward();
                break;
            }

            case 9:
            {
                cout << "Exiting program...\n";
                break;
            }

            default:
            {
                cout << "Invalid choice. Try again.\n";
            }
        }

    } while (choice != 9);

    return 0;
}
