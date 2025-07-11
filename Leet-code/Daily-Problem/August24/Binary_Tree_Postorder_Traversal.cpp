// 25/08/2024
// link - https://leetcode.com/problems/binary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-25

#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> num={};
    vector<int> postorderTraversal(TreeNode* root) {
        
        if (root==nullptr)
            return num;
        
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        num.push_back(root->val);
        
        return num;
    }
};