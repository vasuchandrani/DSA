// 2415

#include<bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
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
    TreeNode* solve() {

    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        
    }
};

// BFS
// level-order 
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while (!q.empty()) {
            int n = q.size();

            vector<TreeNode*> v;
            while (n--) {
                TreeNode* temp = q.front();
                q.pop();

                v.push_back(temp);

                if (temp -> left) {
                    q.push(temp->left);
                }
                if (temp -> right) {
                    q.push(temp->right);
                }
            }

            if (level % 2 == 1) {
                int i = 0;
                int j = v.size() -1;

                while (i < j) {
                    int tempVal = v[i]->val;
                    v[i]->val = v[j]->val;
                    v[j]->val = tempVal;
                    i++;
                    j--;
                }
            }

            level++;
        }

        return root;
    }
};


// DFS
class Solution {
public:
    void solve(TreeNode* L, TreeNode* R, int level) {

        // base-case
        if (L == NULL) {
            return;
        }
        if (R == NULL) {
            return;
        }

        // level -1 is easy to code or swap 
        if (level % 2 == 1) {
            int temp = L->val;
            L->val = R->val;
            R->val = temp;
        }

        // generalised logic - I trust recursion
        solve(L->left, R->right, level+1);
        solve(L->right, R->left, level+1);
    }


    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root->left, root->right, 1);
        return root;
    }
};