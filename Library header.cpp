#ifndef LIBRARY_HEADER_H
#define LIBRARY_HEADER_H

#include <iostream>
#include <string>
using namespace std;

// Node structure for book requests
struct BookRequestNode {
    int studentID;
    string studentName;
    int bookID;
    string bookTitle;
    int priority;
    BookRequestNode* next;
};

// Priority Queue class declaration
class PriorityQueue {
private:
    BookRequestNode* front;
    BookRequestNode* rear;
    int count;

public:
    PriorityQueue();
    void Add(BookRequestNode* request);
    BookRequestNode* Remove();
    bool IsEmpty();
    bool IsNotEmpty();
    void PrintQueue();
    ~PriorityQueue();
};

// Helper function declaration
BookRequestNode* CreateRequest(int studentID, string studentName, int bookID, string bookTitle, int priority);

#endif

