// INSERT BEFORE

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
};

void InsertAtHead(Node* &head, int d) {

    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void print (Node* &head) { 

    Node* temp = head;

    while (temp != NULL){
        cout<< temp -> data << " ";
        temp = temp -> next;  
    }cout<<endl;
}

int main(){
    Node *n1 = new Node(10);
    Node* head = n1;
    print(head);

    InsertAtHead(head, 12);
    print(head);
    
    InsertAtHead(head, 15);
    print(head);
}