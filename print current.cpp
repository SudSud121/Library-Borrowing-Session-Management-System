#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

void DoublyLinkedList::PrintCurrent()
{
    if (current == nullptr)
    {
        cout << "Borrowing session is empty.\n";
        return;
    }

    cout << "Current Book: "
         << current->bookID << " - "
         << current->title << endl;
}
