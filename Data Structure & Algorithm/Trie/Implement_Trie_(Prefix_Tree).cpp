#include<bits/stdc++.h>
using namespace std;

class Trie {
public:

    struct trieNode {
        bool eow;
        trieNode* children[26];
    };

    trieNode* getNode() {

        trieNode* newNode = new trieNode();

        newNode->eow = false;

        for (int i=0; i<26; i++) {
            newNode->children[i] = NULL;
        }

        return newNode;
    }

    trieNode* root;

    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* crawler = root;

        for (int i=0; i<word.length(); i++) {
            char ch = word[i] - 'a';

            if (crawler->children[ch] == NULL) {
                crawler->children[ch] = getNode();
            }

            crawler = crawler->children[ch];
        }

        crawler->eow = true;
    }
    
    bool search(string word) {
        trieNode* crawler = root;

        for (int i=0; i<word.length(); i++) {
            char ch = word[i] - 'a';

            if (crawler->children[ch] == NULL) {
                return false;
            }
            
            crawler = crawler->children[ch];
        }

        return crawler->eow;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawler = root;

        int i=0;
        for (; i<prefix.length(); i++) {
            char ch = prefix[i] - 'a';

            if (crawler->children[ch] == NULL) {
                return false;
            }

            crawler = crawler->children[ch];
        }

        return (i == prefix.length());
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */