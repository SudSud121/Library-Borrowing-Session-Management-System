#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

void DoublyLinkedList::PrintBackward()
{
    if (tail == nullptr)
    {
        cout << "Borrowing session is empty.\n";
        return;
    }

    cout << "\nSession (Last to First):\n";

    dNode* node = tail;

    while (node != nullptr)
    {
        cout << node->bookID << " - "
             << node->title;

        if (node == current)
            cout << " [CURRENT]";

        cout << endl;

        node = node->left;
    }
}
