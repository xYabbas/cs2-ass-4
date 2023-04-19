#pragma once


class LinkedList {
private:
    struct Node {
        int value;
        int count;
        Node* next;
    };

public:
    Node* head;
    LinkedList();
    void addNode(int value, int count);
    void removeNode(int value);
    void printList();
    int sumOfNodes();
};