#include<iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node* next;
        Node* prev;

        Node() {

        }

        Node(int x) {
            data = x;
            prev = next = NULL;
        }

        ~Node() {
        // int val = this -> data;
            if(next != NULL) {
                delete next;
                next = NULL;
            }
        }

        int getLength (Node* &head) {
            
            if (head == NULL)   
                return 0;

            Node* temp = head;
            int count = 1;

            while (temp != NULL) {
                temp = temp -> next;
                count++;
            }
            return count;
        }

        void print(Node* &head) {
            
            if (head == NULL) {
                cout<<"LinkList is empty" <<endl;
                return;
            }

            Node* temp = head;
            while (temp != NULL) {
                cout<<temp -> data<<" ";
                temp = temp -> next;
            }cout<<endl;
        }

        void insertAtTail(Node* &tail, int data) {

            Node* n = new Node(data);
            if (tail == NULL) {
                tail = n;
            }
            else {
                tail -> next = n;
                n -> prev = tail;
                tail = n;
            }
        }

        void insertAtHead(Node* &head, int data) {

            Node* n = new Node(data);
            if (head == NULL) {
                head = n;
            }
            else {
                n -> next = head;
                head -> prev = n;
                head = n;
            }
        }

        void insertAtAnyPosition(Node* &head, Node* &tail, int position, int data) {

            if (position == 1) {
                insertAtHead(head, data);
                return;
            }

            Node* temp = head;
            int cnt = 1;
            while (cnt != position - 1) {
                cnt++;
                temp = temp -> next;
                if (temp == NULL) {
                    cout<<"Not valid position"<<endl;
                    return;
                }
            }
            if (temp -> next == NULL) {
                insertAtTail(tail, data);
                return;
            }

            Node* n = new Node(data);
            n -> next = temp;
            n -> prev = temp -> prev;
            temp -> prev = n;
        }

        void deleteHead(Node* &head) {

            Node* temp = head;
            temp -> next -> prev = NULL;
            head = head -> next;
            temp -> next = NULL;
            delete temp;

        }

        void deleteTail(Node* &tail, Node* &temp) {
            
            tail = tail -> prev;
            tail -> next = NULL;
            temp -> prev = NULL;
            delete temp;
        }

        void deleteNodeAtAnyPosition(Node* &head, Node* &tail, int position) {

            if (position == 1) {
                deleteHead(head);
                return;
            }

            Node* temp = head;
            int cnt = 1;
            while (cnt != position) {
                cnt++;
                temp = temp -> next;
                if (temp == NULL) {
                    cout<<"Not valid position"<<endl;
                    return;
                }
            }

            if (temp -> next == NULL) {
                deleteTail(tail, temp);
                return;
            }

            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;
            temp -> next = NULL;
            temp -> prev = NULL;

            delete temp;
        }
};

int main () {

    Node ll;

    Node* n1 = new Node(10);
    Node* head = n1;
    Node* tail = n1;
    
    ll.insertAtHead(head, 11);

    ll.insertAtHead(head, 12);

    ll.insertAtHead(head, 13);

    ll.insertAtTail(tail, 1000);
    // ll.print(head);

    ll.insertAtAnyPosition (head, tail, 6, 34);
    ll.print(head);

    ll.deleteNodeAtAnyPosition(head, tail, 5);
    ll.print(head);

    ll.deleteNodeAtAnyPosition(head, tail, 5);
    ll.print(head);
}