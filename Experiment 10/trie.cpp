#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct Node {
        Node* links[26];
        bool flag;

        Node() {
            for (int i = 0; i < 26; i++) links[i] = NULL;
            flag = false;
        }

        bool containsKey(char ch) {
            return links[ch - 'a'] != NULL;
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }

        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }

        void setEnd() {
            flag = true;
        }

        bool isEnd() {
            return flag;
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) return false;
            node = node->get(ch);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch)) return false;
            node = node->get(ch);
        }
        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    cout << trie.search("apple") << endl;
    cout << trie.search("app") << endl;
    cout << trie.startsWith("app") << endl;

    trie.insert("app");
    cout << trie.search("app") << endl;

    return 0;
}
