#include "dNode.h"

dNode::dNode(int id, string name)
{
    bookID = id;
    title = name;

    left = nullptr;
    right = nullptr;
}
