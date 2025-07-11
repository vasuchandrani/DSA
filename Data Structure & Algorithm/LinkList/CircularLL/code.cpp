#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node() {}

        Node(int d) {
            this -> data = d;
            this -> next = NULL;
        }

        ~Node () {
            if(this -> next != NULL) {
                delete next;
                next = NULL;
            }
        }

        void insertAtHead(Node* &head, int data) {

            Node* n = new Node(data);
            head = n;
            head -> next = head;
        }

        void insertAfter(Node* &head, int ele, int data) {

            if (head == NULL) {
                insertAtHead(head, data);
            }

            Node* n = new Node(data);

            Node* temp = head;
            while (temp -> data != ele) {
                
                temp = temp -> next;
                if (temp == head) {
                    cout<<"Element not found"<<endl;
                    return;
                }
            }

            n -> next = temp -> next;
            temp -> next = n;
        }

        void deleteHead (Node* &head) {

            if (head == NULL) {
                cout<<"there is nothing to delete"<<endl;
            }

            if (head -> next == head) {
                head = NULL;
                return;
            }

            Node* temp = head;
            while (temp -> next != head) {
                temp = temp -> next;
            }

            Node* deleteNode = temp -> next;

            temp -> next = deleteNode -> next;
            deleteNode -> next = NULL;
            head = temp -> next;

            delete deleteNode;
        }

        void deleteNode (Node* &head, int data) {

            if (head == NULL) {
                cout<<"there is nothing to delete"<<endl;
            }

            Node* temp = head;
            Node* prev = NULL;
            while (temp -> data != data) {
                prev = temp;
                temp = temp -> next;
                if (temp == head) {
                    cout<<"Data not found"<<endl;
                    return;
                }
            }

            if (temp == head) {
                deleteHead(head);
            }

            prev -> next = temp -> next;
            temp -> next = NULL;
            delete temp;
        } 

        void print (Node* &head) {

            if(head == NULL) {
                cout<<"there is nothing to print"<<endl;
            }

            Node* temp = head;
            cout<<temp -> data<<" ";
            while (temp -> next != head) {
                temp = temp -> next;
                cout<<temp -> data<<" ";
            }
            cout<<endl;
        }
};

int main() {

    Node ll;
    Node* head = NULL;

    ll.insertAtHead(head, 1);
    ll.print(head);
    ll.insertAfter(head, 1, 2);
    ll.print(head);
    ll.insertAfter(head, 2, 3);
    ll.print(head);

    ll.insertAfter(head, 1, 3);
    ll.print(head);
}