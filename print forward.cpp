#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

void DoublyLinkedList::PrintForward()
{
    if (head == nullptr)
    {
        cout << "Borrowing session is empty.\n";
        return;
    }

    cout << "\nSession (First to Last):\n";

    dNode* node = head;

    while (node != nullptr)
    {
        cout << node->bookID << " - "
             << node->title;

        if (node == current)
            cout << " [CURRENT]";

        cout << endl;

        node = node->right;
    }
}
