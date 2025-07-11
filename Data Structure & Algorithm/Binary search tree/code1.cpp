#include<iostream>
#include<queue>
using namespace std;

class Node {

public :
    int data;
    Node* right;
    Node* left;
    
    Node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

int maxVal(Node* &root) {

    Node* temp = root;
    int max;

    while (temp != NULL) {
        max = temp -> data;
        temp = temp -> right;
    }

    return max;
}

int minVal(Node* &root) {

    Node* temp = root;
    int min;

    while (temp != NULL) {
        min = temp -> data;
        temp = temp -> left;
    }

    return min;
}

void inorder(Node* root) { // LNR
    //base case 
    if (root == NULL) {
        return;
    }

    inorder(root -> left);
    cout<< root -> data <<" ";
    inorder(root -> right);

}

void preOrder(Node* root) { // NLR
    //base case 
    if (root == NULL) {
        return;
    }

    cout<< root -> data <<" ";
    preOrder(root -> left);
    preOrder(root -> right);

}

void postOrder(Node* root) { // LRN
    //base case 
    if (root == NULL) {
        return;
    }

    postOrder(root -> left);
    postOrder(root -> right);
    cout<< root -> data <<" ";

}

void levelOrderTraversal(Node* root) {

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
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

bool searchInBST(Node* &root, int x) {

    // if (root == NULL) {
    //     return false;
    // }

    // if (root -> data == x) {
    //     return true;
    // }

    // if (root -> data > x ) {
    //     searchInBST(root -> left, x);
    // }
    // else {
    //     searchInBST(root -> right, x);
    // }       

    Node* temp = root;

    while (temp != NULL) {

        if(temp -> data == x) {
            return true;
        }
        else if (temp -> data > x) {
            temp = temp -> left;
        }
        else {
            temp = temp -> right;
        }
    }
    return false;
}

void takeInput(Node* &root) {
    
    int data;   // data for root
    cin >> data;

    while (data != -1){
        insertInToBST(root, data);
        cin >> data;    // data for other Nodes
    }
    // cout<<"over while loop"<<endl;

}

Node* insertInToBST (Node* &root, int d) {

    if (root == NULL) {
        root = new Node(d);
        return root;
    }

    if (d > root -> data) {
        // right 
        root -> right = insertInToBST(root->right, d);
    }
    else {
        // left
        root -> left = insertInToBST(root->left, d);
    }
    // cout<<"insert ho rha hai "<<endl;
    return root;

}

void insertion (Node* &root, int d) {

    Node* temp = root;
    Node* prev;

    while (temp != NULL) {
        if(d > temp -> data) { 
            prev = temp;
            temp = temp -> right;
        }
        else {
            prev = temp;
            temp = temp -> left;
        }
    }
    
    if (prev -> data > d) {
        prev -> left = new Node(d); 
    }
    else {
        prev -> right = new Node(d);        
    }
}

Node* deletation (Node* &root, int x) {

    // base case
    if(root == NULL)
        return root;
    
    if (root -> data == x) {
        //0 child
        if (root -> right == NULL && root -> left == NULL) {
            delete root;
            return NULL;
        }

        //1 child
        //left
        if (root -> left != NULL && root -> right == NULL) {
            Node* temp = root -> left;
            delete root;
            return temp;
        }

        //right 
        if (root -> right != NULL && root -> left == NULL) {
            Node* temp = root -> right;
            delete root;
            return temp; 
        }
 
        //2 child
        if (root -> left != NULL && root -> right != NULL) {

            int mini = minVal(root -> right);
            root -> data = mini; 
            root -> right = deletation(root -> right, mini);
            return root;
        }

    }
    else if (root -> data > x) {
        //left me jao
        root -> left = deletation(root->left, x);
        return root;
    }
    else {
        //right me jao
        root -> right = deletation(root->right, x);
        return root;
    }
}

int main() {

    Node* root = NULL;
    takeInput(root);
    // cout<<"input taked"<<endl;

    cout << "level order traversal" <<endl;
    levelOrderTraversal(root);

    cout << "inorder traversal" <<endl;
    inorder(root);
    cout<<endl;

    cout << "preorder traversal" <<endl;
    preOrder(root);
    cout<<endl;

    cout << "postorder traversal" <<endl;
    postOrder(root);
    cout<<endl;

    cout<< searchInBST(root, 3) << endl;

    insertion(root, 9);
    cout<<endl;
    cout<< "After insert" <<endl;

    levelOrderTraversal(root);
    cout<< "maximum" <<maxVal(root) <<endl;
    cout<< "minimum" << minVal(root) <<endl;

    cout<< "After delete 9"<<endl;
    deletation(root, 9);
    levelOrderTraversal(root);

    cout<< "After delete 8"<<endl;
    deletation(root, 8);
    levelOrderTraversal(root);

    cout<< "After delete 21"<<endl;
    deletation(root, 21);
    levelOrderTraversal(root);
}