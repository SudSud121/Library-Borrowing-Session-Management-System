#include "DoublyLinkedList.h"

DoublyLinkedList::~DoublyLinkedList()
{
    dNode* node = head;

    while (node != nullptr)
    {
        dNode* next = node->right;

        delete node;

        node = next;
    }
}
