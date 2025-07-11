#include<bits/stdc++.h>
using namespace std;

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
    int minSwap(vector<int> &v) {
        int swapOpr = 0;
        unordered_map<int, int> mp;
        for (int i=0; i<v.size(); i++) {
            mp[v[i]] = i;
        }

        vector<int> sorted(v.begin(), v.end());
        sort(sorted.begin(), sorted.end());

        for (int i=0; i<v.size(); i++) {
            
            if (sorted[i] != v[i]) {
                
                int idx = mp[sorted[i]];
                mp[v[i]] = idx;     
                swap(v[idx], v[i]);
                swapOpr++;
            }
        }

        return swapOpr;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int result = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> vec;
            while (n--) {
                TreeNode* node = q.front();
                vec.push_back(node->val);
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            result += minSwap(vec);
        }
        return result;
    }
};