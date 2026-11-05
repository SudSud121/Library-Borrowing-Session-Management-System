#include "library_header.h"

PriorityQueue::PriorityQueue() {
    front = nullptr;
    rear = nullptr;
    count = 0;
}

void PriorityQueue::Add(BookRequestNode* request) {
    request->next = nullptr;
    if (front == nullptr) {
        front = request;
        rear = request;
    } else if (request->priority < front->priority) {
        request->next = front;
        front = request;
    } else {
        BookRequestNode* current = front;
        while (current->next != nullptr && current->next->priority <= request->priority) {
            current = current->next;
        }
        request->next = current->next;
        current->next = request;
        if (request->next == nullptr) {
            rear = request;
        }
    }
    count++;
}

BookRequestNode* PriorityQueue::Remove() {
    if (front == nullptr) {
        return nullptr;
    }
    BookRequestNode* request = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    request->next = nullptr;
    count--;
    return request;
}

bool PriorityQueue::IsEmpty() {
    return front == nullptr;
}

bool PriorityQueue::IsNotEmpty() {
    return front != nullptr;
}

void PriorityQueue::PrintQueue() {
    if (IsEmpty()) {
        cout << "Queue khali hai.\n";
        return;
    }
    BookRequestNode* current = front;
    while (current != nullptr) {
        cout << "Student ID: " << current->studentID << endl;
        cout << "Student Name: " << current->studentName << endl;
        cout << "Book ID: " << current->bookID << endl;
        cout << "Book Title: " << current->bookTitle << endl;
        cout << "Priority: " << current->priority << endl;
        cout << "-----------------------------------" << endl;
        current = current->next;
    }
}

PriorityQueue::~PriorityQueue() {
    while (front != nullptr) {
        BookRequestNode* temp = front;
        front = front->next;
        delete temp;
    }
    rear = nullptr;
}

BookRequestNode* CreateRequest(int studentID, string studentName, int bookID, string bookTitle, int priority) {
    BookRequestNode* request = new BookRequestNode;
    request->studentID = studentID;
    request->studentName = studentName;
    request->bookID = bookID;
    request->bookTitle = bookTitle;
    request->priority = priority;
    request->next = nullptr;
    return request;
}

