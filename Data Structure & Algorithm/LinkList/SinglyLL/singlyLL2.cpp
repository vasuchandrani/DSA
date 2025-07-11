// INSERT AFTER

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

void InsertAtTail(Node* &tail, int d) {

    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
} 

void print (Node* &head) {  // print to head se hi hoga na meri jaan 
    Node* temp = head;

    while (temp != NULL){
        cout<< temp -> data << " ";
        temp = temp -> next;
    }cout<<endl;
}

int main(){
    Node *n1 = new Node(10);
    Node* tail = n1;
    Node* head = n1;
    print(head);

    InsertAtTail(tail, 12);
    print(head);

    
    InsertAtTail(tail, 15);
    print(head);
}