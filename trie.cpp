#include <iostream>
#include <string>
using namespace std;
const int ALPHABET_SIZE = 26;
class Trie
{
public:
    class Node
    {
    public:
        char data;
        Node *children[ALPHABET_SIZE];
        bool isEndOfWord;

        Node(char c)
        {
            data = c;
            isEndOfWord = false;
            for (int i = 0; i < ALPHABET_SIZE; i++)
            {
                children[i] = nullptr;
            }
        }
    };
    Node *root;

    // Time Complexity: O(m), where m is the length of the word
    // Space Complexity: O(m)
    void insert(const string word)
    {
        Node *temp = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (temp->children[index] == nullptr)
            {
                temp->children[index] = new Node(c);
            }
            temp = temp->children[index];
        }
        temp->isEndOfWord = true;
    }

    Trie()
    {
        // Time Complexity: O(1)
        // Space Complexity: O(1)
        root = new Node('\0');
    }

    // Time Complexity: O(n), where n is the total number of nodes in the Trie
    // Space Complexity: O(m), where m is the length of the longest word
    void printWord()
    {
        printWords(root);
    }

    // Time Complexity: O(n), where n is the total number of nodes in the Trie
    // Space Complexity: O(m), where m is the length of the longest word
    void printWords(Node *node, string prefix = "")
    {
        if (node->data != '\0')
        {
            prefix += node->data;
        }
        if (node->isEndOfWord)
        {
            cout << prefix << endl;
        }
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            printWords(node->children[i], prefix);
        }
    }

    // Time Complexity: O(n), where n is the total number of nodes in the Trie
    // Space Complexity: O(1)
    void clear()
    {
        __clear(root);
    }

    // Time Complexity: O(n), where n is the total number of nodes in the Trie
    // Space Complexity: O(1)
    void __clear(Node *node)
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (node->data != '\0')
            {
                __clear(node->children[i]);
            }
        }
        delete node;
    }
};
