#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!current->children[index]) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!current->children[index]) return false;
            current = current->children[index];
        }
        return current->isEndOfWord;
    }
};

int main() {
    Trie trie;
    trie.insert("hello");
    trie.insert("world");

    cout << "Search 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << endl;
    cout << "Search 'world': " << (trie.search("world") ? "Found" : "Not Found") << endl;
    cout << "Search 'trie': " << (trie.search("trie") ? "Found" : "Not Found") << endl;
    return 0;
}
