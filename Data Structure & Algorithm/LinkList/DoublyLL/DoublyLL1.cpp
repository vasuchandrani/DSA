#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev; 
    Node* next;

    Node (int d) {
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    ~Node() {
        // int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

int getLength(Node* &head) {
    int len = 0;
    Node* temp = head;

    while (temp != NULL) {
        len++;
        temp = temp -> next;
    }
    return len;
}

void print (Node* &head){
    Node* temp = head;

    while (temp != NULL){
        cout<< temp -> data <<" ";
        temp = temp -> next;
    }cout<<endl;
}

void InsertAtTail (Node* &tail, int data){

    Node* temp = new Node(data); 
    if(tail == NULL){
        tail = temp;
    } 
    else{        
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void InsertAtHead (Node* &head, int data) {

    Node* temp = new Node(data);
    if(head == NULL){
        head = temp;
    } 
    else{    
        temp -> next = head;
        head -> prev = temp;
        head = temp; 
    }
}

void InsertAtAnyPosition (Node* &head, Node* &tail, int position, int data) {

    if(position == 1){
        InsertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position-1) {
        temp = temp -> next;
        cnt++;
    }

    // insert the node at end 
    // for update the tail pointer
    if(temp -> next == NULL){
        InsertAtTail(tail,  data);
        return;
    }
    
    // ye data d k liye ak node bana lo 
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;

}

void DeleteNode (int position, Node* &head, Node* &tail) {

    // delete first node
    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else {

        //delete middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while (cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        // update tail if the last node deleted
        if(curr -> next == NULL){
            tail = prev;
        }

        prev -> next = curr -> next;
        // curr -> next -> prev = prev; - wrong line
        curr -> prev = NULL;
        curr -> next = NULL;
        delete curr;
        
    }
}

int main(){
    
    Node* n1 = new Node(10);
    Node* head = n1;
    Node* tail = n1;

    // print(head);
    InsertAtHead(head, 11);
    // print(head);

    InsertAtHead(head, 12);
    // print(head);

    InsertAtHead(head, 13 );
    // print(head);

    InsertAtTail(tail, 1000);
    // print(head);

    InsertAtAnyPosition (head, tail, 6, 34);
    print(head);
    cout<<"length of LL is "<<getLength(head)<<endl;

    DeleteNode(6, head, tail);
    print(head);

    return 0;
}

