#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node (int x) {
            data = x;
            next = NULL;
        }
        ~Node() {
            // int val = this -> data;
            if(next != NULL) {
                delete next;
                next = NULL;
            }
        }

        void display (Node* &head) {
            
            Node* temp = head;
            while (temp != NULL) {
                cout<<temp -> data<<" ";
                temp = temp -> next;
            }
        }

        void insert(int data, Node* &head) {

            Node* n = new Node(data);
            if (head == NULL) {
                head = n;
                return;
            }   

            Node* temp = head;

            while (temp -> next != NULL) {
                temp = temp -> next;
            }
            
            temp -> next = n;
        }

        void deletation(int data, Node* &head) {

            if (head == NULL) {
                cout<<"Link-list is Empty"<<endl;
                return;
            }

            Node* temp = head;
            Node* prev = NULL;
            while (temp -> data != data) {
                prev = temp;
                temp = temp -> next;
            }

            // if delete karne vala data head ka data hai..
            if (prev == NULL) {
                head = temp -> next;
                temp -> next = NULL;
                return;
            }

            // if delete karne vala data bichke kisi node ka data hai..
            prev -> next = temp -> next;
            temp -> next = NULL;
            delete temp;
        }

        void deleteHead (Node* &head) {

            if (head -> next == NULL) {
                delete head;
            }

            Node* newHead = head -> next;
            head -> next = NULL;
 
            head = newHead;
        }

        void insertAfter(int data, int x, Node* &head) {
            
            Node* n = new Node(data);
            Node* temp = head;

            while (temp -> data != x) {
                temp = temp -> next;
                if(temp == NULL){
                    cout<<"The node u enter is not exist in this link-list"<<endl;
                    return;
                }
            }

            n -> next = temp -> next;
            temp -> next = n;
        }

        void insertBefore(int data, int x, Node* &head) {

            Node* n = new Node(data);
            Node* temp = head;
            Node* prev = NULL;

            while (temp -> data != x && temp != NULL) {
                prev = temp;
                temp = temp -> next;
                if(temp == NULL){
                    cout<<"The node u enter is not exist in this link-list"<<endl;
                    return;
                }
            }

            // if data head ke pehle insert karna hai..
            if (prev == NULL) {
                n -> next = temp;
                head = n;
                return;
            }

            prev -> next = n;
            n -> next = temp;
        }
 
        void deleteAfter(int nodeData, Node* &head) {
            //delete the node after the given node
            Node* temp = head;
            while (temp -> data != nodeData) {
                temp = temp -> next;
                if(temp == NULL){
                    cout<<"The node u enter is not exist in this link-list"<<endl;
                    return;
                }
            }

            temp -> next = temp -> next -> next;
            temp -> next -> next = NULL;

            delete temp -> next; 
        }

        void deleteBefore(int nodeData, Node* &head) {
            //delete the node before the given node
            Node* temp = head;
            Node* prev = NULL;
            while (temp -> data != nodeData) {
                prev = temp;
                temp = temp -> next;
                if(temp == NULL){
                    cout<<"The node u enter is not exist in this link-list"<<endl;
                    return;
                }
            }

            if (prev == NULL) {
                cout<<"NO node exist this Node"<<endl;
                return;
            }

            if (prev == head) {
                deleteHead(head);
            }

            // prev ke aage vale ko kese delete karu ???????
            // write ur code here
        }
};

int main () {
    
    Node* head = NULL;

    // write code as per your requirment 
}