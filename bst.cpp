#include <iostream>
#include <string>
using namespace std;

class BST
{
private:
    class Node
    {
    public:
        string data;
        Node *left;
        Node *right;
        Node(string val)
        {
            data = val;
            left = nullptr;
            right = nullptr;
        }
    };
    Node *root;

    // Helper recursive function for insertion
    // Time Complexity: O(h), where h is the height of the tree
    // Space Complexity: O(h)
    Node *insert(Node *node, const string &word)
    {
        if (node == nullptr)
        {
            return new Node(word);
        }
        if (word < node->data)
        {
            node->left = insert(node->left, word);
        }
        else if (word > node->data)
        {
            node->right = insert(node->right, word);
        }
        return node;
    }

    // Helper recursive function for in-order traversal and printing
    // Time Complexity: O(n), where n is the total number of nodes in the tree
    // Space Complexity: O(h), where h is the height of the tree
    void printWords(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        printWords(node->left);
        cout << node->data << " ";
        printWords(node->right);
    }

public:
    // Constructor
    BST() : root(nullptr) {}

    // Public function for inserting a word into the BST
    // Time Complexity: O(h), where h is the height of the tree
    // Space Complexity: O(h)
    void insert(const string &word)
    {
        root = insert(root, word);
    }

    // Public function for printing all words in BST in-order
    // Time Complexity: O(n), where n is the total number of nodes in the tree
    // Space Complexity: O(h), where h is the height of the tree
    void printWords()
    {
        cout << "Words stored in the BST (In-order): ";
        printWords(root);
        cout << endl;
    }
};

int main()
{
    BST bst;
    // Inserting some words into BST
    bst.insert("batman");
    bst.insert("bati");
    bst.insert("batis");
    bst.insert("batmaz");
    // Printing all words in BST in-order
    bst.printWords();

    return 0;
}
