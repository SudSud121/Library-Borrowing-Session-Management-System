#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

dNode* DoublyLinkedList::RemoveCurrent()
{
    if (current == nullptr)
    {
        cout << "No book to remove.\n";
        return nullptr;
    }

    dNode* removed = current;

    dNode* previous = current->left;
    dNode* next = current->right;

    if (previous != nullptr)
        previous->right = next;
    else
        head = next;

    if (next != nullptr)
        next->left = previous;
    else
        tail = previous;

    if (next != nullptr)
        current = next;
    else
        current = previous;

    removed->left = nullptr;
    removed->right = nullptr;

    return removed;
}
