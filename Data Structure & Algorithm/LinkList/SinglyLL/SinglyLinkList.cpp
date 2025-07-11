#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *link;

        Node(int x){
            data = x;
            link = NULL;
        }

        friend void display(Node *head){
            Node *temp = head;
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp = temp->link;
            }
        }
        friend void Insert(int a, Node *head){
            Node *temp = head;
            while(temp->link!=NULL){
                temp = temp->link;
            }
            temp->link = new Node(a);
        }
        friend void deletafter(int curr, Node *head){
            Node *temp = head;
            while(temp->data != curr){
                temp = temp->link;
            }
            temp->link = temp->link->link;
        }
        friend void deletbefore(int curr, Node *head){
            Node *temp = head;
            while(temp->link->link->data!=curr){
                temp = temp->link;
            }
            temp->link = temp->link->link;
        }
        friend void InsertAfter(int c, int n, Node *head){
            Node *temp = head;
            while(temp->data!=c){
                temp = temp->link;
            }
            Node *p = new Node(n);
            p->link = temp->link;
            temp->link = p;
        }
        friend void InsertBefore(int c, int n, Node *head){
            Node *temp = head;
            while(temp->link->data!=c){
                temp = temp->link;
            }
            Node *nn = new Node(n);
            nn->link = temp->link;
            temp->link = nn;
        }
};

int main(){
    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);

    n1->link = n2;
    n2->link = n3;
    n3->link = n4;
    n4->link = NULL;

    Node *head = n1;
    display(head);

    cout<<"Enter element at end"<<endl;
    int n;
    cin>>n;
    Insert(n, head);
    display(head);

    cout<<"Enter element after given element"<<endl;
    InsertAfter(20, 80, head);
    display(head);

    cout<<"delete element after given element"<<endl;
    deletafter(20, head);
    display(head);

    cout<<"Insert element before given element"<<endl;
    deletbefore(20, head);
    display(head);

    return 0;
}