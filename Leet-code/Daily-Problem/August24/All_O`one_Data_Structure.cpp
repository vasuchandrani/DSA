// 29/9/2024
// link = https://leetcode.com/problems/all-oone-data-structure/description/?envType=daily-question&envId=2024-09-29

#include<bits/stdc++.h>
using namespace std;

class AllOne {
public:
    struct Node {
        int count;  //freq
        list<string> keys;
        Node* prev;
        Node* next;
        Node (int c) {
            count = c;
            prev = nullptr;
            next = nullptr;
        }
    };

    unordered_map<string, Node*> mp;

    Node* head;
    //Node* first;  // head -> next will be the first and min key string 
    Node* last; // max key string 

    void addNode(Node* prevNode, int count) {
        Node* newNode = new Node(count);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        if (newNode->next != NULL) {
            newNode->next->prev = newNode;
        }

        if (prevNode == last) {
            last = newNode;
        }
    }

    void removeNode (Node* node) {
        
        node->prev->next = node->next;
        if (node->next != NULL) {
            node->next->prev = node->prev;
        }

        if (last == node) {
            last = node->prev;
        }

        delete node;
    } 
 
    AllOne() {
        head = new Node(0);
        last = head;
    }
    
    void inc(string key) {
        if (mp.find(key) == mp.end()) {
            // not exists
            // check if there is already a node with count = 1
            if (head->next == nullptr || head->next->count != 1) {
                addNode(head, 1);
            }

            head->next->keys.push_back(key);
            mp[key] = head->next;
        }
        else {  // key is already there in the map
            // increase it's freq.
            Node* currNode = mp[key];
            int currCount = currNode->count;
            if (currNode->next == nullptr || currNode->next->count != currCount+1) {
                addNode(currNode, currCount+1);
            }

            currNode->next->keys.push_back(key);
            mp[key] = currNode->next;
            currNode->keys.remove(key);

            if (currNode->keys.empty()) {
                removeNode(currNode);
            }
        }
    }
    
    void dec(string key) {
        Node* currNode = mp[key];
        int currCount = currNode->count;

        // if count become zero then remove the key 
        if (currCount == 1) {
            mp.erase(key);
        } else {
            if (currNode->prev->count != currCount-1) {
                addNode(currNode->prev, currCount-1);
            }
            
            currNode->prev->keys.push_front(key);
            mp[key] = currNode->prev;
        }

        currNode->keys.remove(key);
        if (currNode->keys.empty()) {
            removeNode(currNode);
        }
    }
    
    string getMaxKey() {
        
        if (last == head) { // no nodes available
            return "";
        }

        return last->keys.front();
    }
    
    string getMinKey() {
        
        if (head->next == nullptr) {  
            return "";
        }

        return head->next->keys.front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */