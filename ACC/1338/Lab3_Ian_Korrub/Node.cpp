// Node.cpp
#include "Node.h"

using namespace std;

Node::Node(){
    catagory = "";
    line = "";
    next = nullptr;
}

void Node::setCatagory(const string& catagory) {
    this->catagory = catagory;
}

void Node::setLine(const string& line) {
    this->line = line;
}

void Node::setNext(Node* next) {
    this->next = next;
}

string Node::getCatagory() const {
    return this->catagory;
}

string Node::getLine() const {
    return this->line;
}

Node* Node::getNext() const {
    return this->next;
}

// No additional implementation needed for Node.cpp since Node is a simple struct
