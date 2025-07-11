// invert binary tree

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
 
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 
/* Change a tree so that the roles of the left and
    right pointers are swapped at every node.
 
So the tree...
     4
    / \
   2   5
  / \
 3   1
 
is changed to...
     4
    / \
   5   2
      / \
     1   3
*/
void mirror(struct Node* node)
{
    if (node == NULL)
        return;
    else {
        struct Node* temp;
 
        mirror(node->left);
        mirror(node->right);
 
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
 
void display(struct Node* node)
{
    if (node == NULL)
        return;
 
    display(node->left);
    cout << node->data << " ";
    display(node->right);
}
 
// Driver Code
int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "display traversal of the constructed" << endl;
    display(root);
 
    /* Convert tree to its mirror */
    mirror(root);
 
    cout << "\ndisplay traversal of the mirror tree" <<endl;
    display(root);
 
    return 0;
}
 