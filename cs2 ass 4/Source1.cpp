#include <iostream>
#include "Header.h"

using namespace std;

LinkedList::LinkedList() {
    head = NULL;
}

void LinkedList::addNode(int value, int count) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->count = count;
    newNode->next = head;
    head = newNode;
}

void LinkedList::removeNode(int value) {
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL && temp->value != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Element not found" << endl;
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    }
    else {
        prev->next = temp->next;
    }
    delete temp;
}

void LinkedList::printList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value << "(" << temp->count << ") ";
        temp = temp->next;
    }
    cout << endl;
}

int LinkedList::sumOfNodes() {
    Node* temp = head;
    int sum = 0;
    while (temp != NULL) {
        sum += temp->value * temp->count;
        temp = temp->next;
    }
    return sum;
}