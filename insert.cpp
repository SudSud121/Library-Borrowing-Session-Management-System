#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

void DoublyLinkedList::InsertRight(dNode* node)
{
    if (node == nullptr)
        return;

    node->left = tail;
    node->right = nullptr;

    if (tail != nullptr)
        tail->right = node;
    else
        head = node;

    tail = node;

    if (current == nullptr)
        current = node;
}
