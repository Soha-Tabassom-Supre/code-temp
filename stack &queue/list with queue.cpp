#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* frontNode;
    Node* rearNode;

public:
    Queue() {
        frontNode = nullptr;
        rearNode = nullptr;
    }

  
    void enqueue(int x) {
        Node* newNode = new Node(x);

        if (rearNode == nullptr) {
           
            frontNode = rearNode = newNode;
            return;
        }

        rearNode->next = newNode;
        rearNode = newNode;
    }

    void dequeue() {
        if (frontNode == nullptr) {
            cout << "Queue is empty, nothing to dequeue" << endl;
            return;
        }

        Node* temp = frontNode;
        frontNode = frontNode->next;

      
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }

        delete temp;
    }

 
    int front() {
        if (frontNode == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return frontNode->data;
    }

    bool empty() {
        return frontNode == nullptr;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.front() << endl; 
    q.dequeue();

    cout << q.front() << endl; 
    cout << q.empty() << endl;

    return 0;
}