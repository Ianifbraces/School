
#include "Linked_list.h"
#include <iostream>
#include <vector>

using namespace std;

LinkedList::LinkedList(){
    head = nullptr;
    int numItems = 0;
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->getNext();
        delete current;
        current = next;
    }
}

void LinkedList::addNode(const string& catagory, const string& line) { // adds node to linked list and sorts it
    Node* newNode = new Node;
    newNode->setCatagory(catagory);
    newNode->setLine(line);
    newNode->setNext(nullptr);
    this->numItems += 1;

    if (head == nullptr || head->getCatagory() > catagory) { // if head is null or head's category is greater than category
        newNode->setNext(head); // new node's next is head
        head = newNode; // head now points to new node
        return;
    } // end if (head == nullptr || head->catagory > catagory)

    Node* cur = head;
    while (cur->getNext() != nullptr && cur->getNext()->getCatagory() < catagory) { // while current's next is not null and current's next's category is less than category
        cur = cur->getNext(); // current is now current's next
    } // end while (cur->next != nullptr && cur->next->catagory < catagory)
    newNode->setNext(cur->getNext()); // new node's next is current's next
    cur->setNext(newNode); // current's next is new node
} // end void LinkedList::addNode(const string& catagory, const string& line)

void LinkedList::display() const { // displays linked list
    Node* current = head;
    string currentCatagory = "";
    while (current != nullptr) { // while current is not null
        if (currentCatagory != current->getCatagory()) { // if current category is not equal to current's category
            cout << current->getCatagory() << endl; // display current's category
            currentCatagory = current->getCatagory(); // current category is now current's category
        } // end if (currentCatagory != current->catagory)
        cout << '\t' << current->getLine() << endl; // display current's line
        current = current->getNext(); // current is now current's next
    }// end while (current != nullptr)
}// end void LinkedList::display() const

int LinkedList::getNumItems() const {
    return this->numItems;
} // end int LinkedList::getNumItems() const

LinkedList LinkedList::copy() {
    LinkedList copy;
    Node* current = head;
    while (current != nullptr) {
        copy.addNode(current->getCatagory(), current->getLine());
        current = current->getNext();
    }
    return copy;
} // end LinkedList LinkedList::copy()

void LinkedList::toVector(vector<string>& v) const {
    Node* current = head;
    while (current != nullptr) {
        v.push_back(current->getCatagory());
        v.push_back(current->getLine());
        current = current->getNext();
    }
} // end void LinkedList::toVectoy(vector<string>& v) const
