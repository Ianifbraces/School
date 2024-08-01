#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>

using namespace std;

struct Node {
    private:
        string catagory;
        string line;
        Node* next;
    public:
        string getCatagory() const;
        string getLine() const;
        Node* getNext() const;
        void setCatagory(const string& catagory);
        void setLine(const string& line);
        void setNext(Node* next);

};
#endif // NODE_H

