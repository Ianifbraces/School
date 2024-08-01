#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
#include <iostream>
#include "Node.h"

using namespace std;

//struct Node {
//    string catagory;
//    string line;
//    Node* next;
//};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    LinkedList copy();
    void addNode(const string& catagory, const string& line);
    void display() const;
    int getNumItems() const;
    void toVector(vector<string>& v) const;
private:
    Node* head;
    int numItems;
};

#endif // LINKED_LIST_H

