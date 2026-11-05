#include "library_header.h"

int main() {
    PriorityQueue requests;
    int choice = 0;

    while (choice != 5) {
        cout << "\n=========================================\n";
        cout << "       Library Book Request System\n";
        cout << "=========================================\n";
        cout << "1. Add Book Request\n";
        cout << "2. Process Highest Priority Request\n";
        cout << "3. Display All Requests\n";
        cout << "4. Check Queue Status\n";
        cout << "5. Exit\n";
        cout << "Option select karein (1-5): ";
        cin >> choice;

        if (choice == 1) {
            int sID, bID, prio;
            string sName, bTitle;

            cout << "Enter Student ID: ";
            cin >> sID;
            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, sName);
            cout << "Enter Book ID: ";
            cin >> bID;
            cout << "Enter Book Title: ";
            getline(cin, bTitle);
            cout << "Enter Priority (1: Exam/Urgent, 2: Assignment, 3: Normal): ";
            cin >> prio;

            BookRequestNode* newNode = CreateRequest(sID, sName, bID, bTitle, prio);
            requests.Add(newNode);
            cout << "Request successfully add ho gayi!\n";

        } else if (choice == 2) {
            BookRequestNode* processed = requests.Remove();
            if (processed != nullptr) {
                cout << "\n--- Processing Request ---\n";
                cout << "Student: " << processed->studentName << " (ID: " << processed->studentID << ")\n";
                cout << "Book: " << processed->bookTitle << " (ID: " << processed->bookID << ")\n";
                cout << "Priority: " << processed->priority << "\n";
                delete processed;
            } else {
                cout << "Queue khali hai! Koi request process karne ke liye nahi hai.\n";
            }

        } else if (choice == 3) {
            cout << "\n--- All Pending Requests ---\n";
            requests.PrintQueue();

        } else if (choice == 4) {
            if (requests.IsEmpty()) {
                cout << "Status: Queue bilkul khali (Empty) hai.\n";
            } else {
                cout << "Status: Queue mein requests pending hain (Not Empty).\n";
            }

        } else if (choice == 5) {
            cout << "Program close ho raha hai...\n";
        } else {
            cout << "Invalid choice! Dubara koshish karein.\n";
        }
    }

    return 0;
}

