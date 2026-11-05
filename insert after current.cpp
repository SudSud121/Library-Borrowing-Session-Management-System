#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

void DoublyLinkedList::InsertAfterCurrent(dNode* node)
{
    if (node == nullptr)
        return;

    if (current == nullptr)
    {
        InsertRight(node);
        return;
    }

    node->left = current;
    node->right = current->right;

    if (current->right != nullptr)
        current->right->left = node;
    else
        tail = node;

    current->right = node;

    cout << "Book inserted successfully.\n";
}
