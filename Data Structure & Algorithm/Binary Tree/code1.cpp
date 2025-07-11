// build a binary tree and all traversal (levelOrder, inOrder, preOrder, postOrder)

#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
    
    node(int d) {
        left = right = NULL;
        data = d;
    } 
};

node* buildTree (node* root) {

    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if (data == -1) {
        return NULL;
    }

    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root -> left = buildTree(root -> left);

    cout<<"Enter the data for inserting in right of "<<data<<endl;
    root -> right = buildTree(root -> right);

        return root;
}

void levelOrderTraversal(node* root) {

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }

        else {
            cout<< temp -> data <<" ";
            if (temp -> left) {
                q.push(temp -> left);
            }
            if (temp -> right) {
                q.push(temp -> right);
            }
        }
    }
}

void inOrder(node* root) { // LNR
    //base case 
    if (root == NULL) {
        return;
    }

    inOrder(root -> left);
    cout<< root -> data <<" ";
    inOrder(root -> right);

}

void preOrder(node* root) { // NLR
    //base case 
    if (root == NULL) {
        return;
    }

    cout<< root -> data <<" ";
    preOrder(root -> left);
    preOrder(root -> right);

}

void postOrder(node* root) { // LRN
    //base case 
    if (root == NULL) {
        return;
    }

    postOrder(root -> left);
    postOrder(root -> right);
    cout<< root -> data <<" ";

}

int main () {

    node* root = NULL;

    // creating a tree
    root = buildTree(root);

    // level Order printing or Traversal
    cout<<"Level Order Traversal: "<<endl;
    levelOrderTraversal(root);
    
    // inorder
    cout<<"Inorder Traversal: "<<endl;
    inOrder(root);
    cout<<endl;

    // preorder
    cout<<"Preorder Traversal: "<<endl;
    preOrder(root);
    cout<<endl;
     
    // post-order
    cout<<"Post-order Traversal: "<<endl;
    postOrder(root);
    return 0;
}