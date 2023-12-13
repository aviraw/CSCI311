#include <iostream>
#include <string>
using namespace std;

class TST
{
private:
    class Node
    {
    public:
        char data;
        bool isEndOfWord;
        Node *left;
        Node *equal;
        Node *right;
        Node(char val)
        {
            data = val;
            isEndOfWord = false;
            left = nullptr;
            equal = nullptr;
            right = nullptr;
        }
    };
    Node *root;

    // Helper recursive function for insertion
    // Time Complexity: O(h), where h is the height of the tree
    // Space Complexity: O(h)
    Node *insert(Node *node, const char *word)
    {
        if (node == nullptr)
        {
            node = new Node(*word);
        }
        if (*word < node->data)
            node->left = insert(node->left, word);
        else if (*word > node->data)
            node->right = insert(node->right, word);
        else
        {
            if (*(word + 1) != '\0')
                node->equal = insert(node->equal, word + 1);
            else
                node->isEndOfWord = true;
        }
        return node;
    }

    // Helper recursive function for printing words
    // Time Complexity: O(n), where n is the total number of nodes in the tree
    // Space Complexity: O(h), where h is the height of the tree
    void printWords(Node *node, string prefix)
    {
        if (node == nullptr)
            return;
        printWords(node->left, prefix);
        prefix += node->data;
        if (node->isEndOfWord)
        {
            cout << prefix << " ";
        }
        printWords(node->equal, prefix);
        printWords(node->right, prefix.substr(0, prefix.size() - 1));
        // remove the last character for the right subtree
    }

public:
    // Constructor
    TST() : root(nullptr) {}

    // Public function for inserting a word into the TST
    // Time Complexity: O(h), where h is the height of the tree
    // Space Complexity: O(h)
    void insert(string word)
    {
        root = insert(root, word.c_str());
    }

    // Public function for printing all words in TST alphabetically
    // Time Complexity: O(n), where n is the total number of nodes in the tree
    // Space Complexity: O(h), where h is the height of the tree
    void printWords()
    {
        string prefix = "";
        printWords(root, prefix);
    }
};

int main()
{
    TST tst;
    // Inserting some words into TST
    tst.insert("batman");
    tst.insert("bati");
    tst.insert("batis");
    tst.insert("batmaz");
    // Printing all words in TST alphabetically
    cout << "Words stored in the TST (Alphabetically order): ";
    tst.printWords();
    cout << endl;
    return 0;
}
