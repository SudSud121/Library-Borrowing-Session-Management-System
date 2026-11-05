#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

void DoublyLinkedList::Previous()
{
    if (current != nullptr && current->left != nullptr)
    {
        current = current->left;
        PrintCurrent();
    }
    else
    {
        cout << "No previous book available.\n";
    }
}
