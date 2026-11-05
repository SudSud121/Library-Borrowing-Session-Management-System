#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

void DoublyLinkedList::Next()
{
    if (current != nullptr && current->right != nullptr)
    {
        current = current->right;
        PrintCurrent();
    }
    else
    {
        cout << "No next book available.\n";
    }
}
