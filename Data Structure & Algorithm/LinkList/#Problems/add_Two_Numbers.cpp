// not a DFS code

#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        
        while (temp1 != NULL && temp2 != NULL) {
            int val = temp1->val + temp2->val + carry;
            carry += val/10;

            ListNode* n = new ListNode(val);
            temp -> next = n;
            temp = temp -> next;   
        }

        while (temp1 != NULL) {
            int val = temp1->val + carry;
            carry += val/10;

            ListNode* n = new ListNode(val);
            temp -> next = n;
            temp = temp -> next; 
        }

        while (temp2 != NULL) {
            int val = temp2->val + carry;
            carry += val/10;

            ListNode* n = new ListNode(val);
            temp -> next = n;
            temp = temp -> next; 
        }
        ListNode* k = ans;
        ans = ans -> next;
        delete(k);      
        return ans;
    }
};

int main () {
    ListNode* l1 = new ListNode(1);
    for (int i=0; i<5; i++) {
        ListNode* n = new ListNode(1);
    }

    ListNode* l2 = new ListNode(2); 
    for (int i=0; i<5; i++) {
        ListNode* n = new ListNode(2);
    }

}