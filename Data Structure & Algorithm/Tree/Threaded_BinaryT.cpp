#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    bool isThreaded;

    Node (int val) {
        data = val;
    }
};

void createThreaded(Node* root) {
    if (root == nullptr) return;

    if (root->left) createThreaded(root->left);

    if (root->right) createThreaded(root->right);

    if (root->left == nullptr && root->right == nullptr) {
        root->isThreaded = true;
    } else if (root->right == nullptr && root->left) {
        Node* predecessor = root->left;
        while (predecessor->right) {
            predecessor = predecessor->right;
        }
        predecessor->isThreaded = true;
        predecessor->right = root;
    }
}


Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        if (root->isThreaded) {
            root->right = insert(nullptr, key);
            root->isThreaded = false;
        } else {
            root->right = insert(root->right, key);
        }
    }

    return root;
}


int main() {

}