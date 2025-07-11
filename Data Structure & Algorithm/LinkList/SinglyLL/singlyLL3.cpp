// INSERT ANYWHERE

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
    // print(head);
    InsertAtTail(tail, 12);
    // print(head);
    InsertAtTail(tail, 15);
    print(head);

    // InsertAtAnyPosition ( tail pointer , head pointer , position , data );
    InsertAtAnyPosition(tail, head, 3, 22);
    print(head);

    InsertAtAnyPosition(tail, head, 1, 0);
    print(head);

    InsertAtAnyPosition(tail, head, 6, 100);
    print(head);

    cout << "head " << head -> data << endl; // 0
    cout << "tail " << tail -> data << endl; // 100

}