#include <iostream>
#include <vector>
#include "Header.h"
using namespace std;

struct Node {
    int value;
    int count;
    Node* next;
};

void insertAfter(vector<int>& v, int firstValue, int secondValue) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == firstValue) {
            v.insert(v.begin() + i + 1, secondValue);
            i++;
        }
    }
}

LinkedList createLinkedList(vector<int>& v) {
    LinkedList list;
    for (int i = 0; i < v.size(); i++) {
        int value = v[i];
        int count = 1;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] == value) {
                count++;
                v.erase(v.begin() + j);
                j--;
            }
        }
        list.addNode(value, count);
    }
    return list;
}

int main() {
    vector<int> v;
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cout << "Enter integer #" << i + 1 << ": ";
        cin >> num;
        v.push_back(num);
    }

    int firstValue, secondValue;
    cout << "Enter the first value: ";
    cin >> firstValue;
    cout << "Enter the second value: ";
    cin >> secondValue;

    insertAfter(v, firstValue, secondValue);

    LinkedList list = createLinkedList(v);

    cout << "Elements of the linked list: ";
    list.printList();
    cout << "Sum of all nodes: " << list.sumOfNodes() << endl;

    return 0;
}