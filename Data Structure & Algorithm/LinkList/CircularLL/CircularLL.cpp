#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int data){
            this -> data = data;
            next = NULL;
        }

        ~Node() {
            // int val = this -> data;
            if (this -> next != NULL) {
                delete next;
                next = NULL;
            }
        }
};

void insertNode(Node* &tail, int ele, int d) {

    if (tail == NULL) {
        Node* nn = new Node(d);
        tail = nn;
        nn -> next = nn;
    }

    else {

        Node* curr = tail;

        while (curr -> data != ele) {
            curr = curr -> next;
        }

        Node* nn = new Node(d);
        nn -> next = curr -> next;
        curr -> next = nn;
    }
}

void deleteNode(Node* &tail, int ele) {

    if (tail == NULL) {
        cout<< "empty"<<endl;
        return;
    }

    Node* prev = tail;
    Node* curr = prev -> next;

    while (curr -> data != ele) {
        prev = curr;
        curr = curr -> next;
    }

    prev -> next = curr -> next;

    if (curr == prev) {
        tail = NULL;
    }

    if (curr == tail) {
        prev = tail;
    }

    curr -> next = NULL;
    delete curr;
}

void print(Node* tail) {

    if (tail == NULL) {
        cout<<"empty"<<endl;
    }

    Node* temp = tail;
    do {
        cout<<temp -> data<<" ";
        temp = temp -> next; 
    }while (temp != tail); 

    cout<<endl;
}

int main() {

    Node* tail = NULL;

    insertNode(tail, 5, 1);
    print(tail);
    insertNode(tail, 1, 2);
    print(tail);
    insertNode(tail, 2, 3);
    print(tail);

    insertNode(tail, 1, 3);
    print(tail);
}