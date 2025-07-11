// DELETATION
 
#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node (int data){
        this -> data = data; 
        next = NULL;
    }

    //destructor
    ~Node() {
        // int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this -> next = NULL; 
        }
    }
};
  
// insert
void InsertAtTail (Node* &tail, int d) {

    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
} 

void InsertAtHead(Node* &head, int d) {

    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void InsertAtAnyPosition (Node* &tail, Node* &head, int position, int d) {

    // inserting the node at start
    if(position == 1){
        InsertAtHead(head, d);
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
        InsertAtTail(tail, d);
        return;
    }
    
    // ye data d k liye ak node bana lo 
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;

}

// print
void print (Node* &head) {  // print to head se hi hoga na meri jaan 
    Node* temp = head;

    while (temp != NULL){
        cout<< temp -> data << " ";
        temp = temp -> next;
    }cout<<endl;
}

//delete
void DeleteAnyNode (int position, Node* &head, Node* &tail) {

    
    // deleting start/first Node 
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        // memory free kardo
        temp -> next = NULL;
        delete temp; 
    }
    else{
        // deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        
        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        // update tail if the last node deleted
        if(curr -> next == NULL){
            tail = prev;
        }

        prev -> next = curr -> next;

        // memory free
        curr -> next = NULL; 
        delete curr;
    }
}


int main(){

    Node* n1 = new Node(10);
    Node* head = n1; 
    Node* tail = n1; 

    InsertAtTail(tail, 12);
    InsertAtTail(tail, 15);
    InsertAtAnyPosition(tail, head, 3, 22);
    InsertAtAnyPosition(tail, head, 1, 0);
    InsertAtAnyPosition(tail, head, 6, 100);
    print(head);

    DeleteAnyNode (1, head, tail);
    print(head);

    cout<< head -> data<<endl;
    cout<< tail -> data<<endl;

}

