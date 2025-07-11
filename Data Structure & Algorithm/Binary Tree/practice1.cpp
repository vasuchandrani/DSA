#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* right;
        Node* left;

        Node() {}

        Node(int data) {
            this -> data = data; 
            right = left = NULL;
        }

        Node* buildTree(Node* &root) {
            // this fnc return the root pointer of tree 

            cout<<"Enter the data"<<endl;
            int data;
            cin>>data;
            root = new Node(data);

            if (data == -1) {
                return NULL;
            }

            cout<<"Enter the data for inserting in left of "<<data<<endl;
            root -> left = buildTree(root -> left);

            cout<<"Enter the data for inserting in right of "<<data<<endl;
            root -> right = buildTree(root -> right);

            return root;
        }

        void levelOrderTraversal(Node* &root) {

            queue<Node*> q;
            q.push(root);
            q.push(NULL);

            while (!q.empty()) {
                Node* temp = q.front();
                q.pop();

                if (temp == NULL) {

                    cout<<endl;
                    if (!q.empty()) {
                        q.push(NULL);
                    }
                }
                else {
                    
                    cout<<temp -> data<<" ";
                    if (temp -> right) {
                        q.push(temp -> right);
                    }
                    if (temp -> left) {
                        q.push(temp -> left);
                    }
                }
            }   
        }

        void inOrder(Node* &root) {
            //LNR

            //base-case
            if (root == NULL) {
                return;
            }

            inOrder(root -> left);
            cout<<root -> data<<" ";
            inOrder(root -> right);
        }

        void preOrder(Node* &root) {
            //NLR
            
            //base-case
            if (root == NULL) {
                return;
            }

            cout<<root -> data<<" ";
            preOrder(root -> left);
            preOrder(root -> right);
        }

        void postOrder(Node* &root) {
            //LRN

            //base-case
            if (root == NULL) {
                return;
            }

            postOrder(root -> left);
            postOrder(root -> right); 
            cout<<root -> data<<" ";
        }
};

int main () {

    Node t;

    Node* root = NULL;

    // creating a tree
    root = t.buildTree(root);

    // level Order printing or Traversal
    cout<<"Level Order Traversal: "<<endl;
    t.levelOrderTraversal(root);
    
    // inorder
    cout<<"Inorder Traversal: "<<endl;
    t.inOrder(root);
    cout<<endl;

    // preorder
    cout<<"Preorder Traversal: "<<endl;
    t.preOrder(root);
    cout<<endl;
     
    // post-order
    cout<<"Post-order Traversal: "<<endl;
    t.postOrder(root);
    return 0;
}
