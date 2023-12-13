#include <iostream>
using namespace std;

class AVL
{
private:
    class Node
    {
    public:
        int key;
        Node *left;
        Node *right;
        int height;

        Node(int k)
        {
            key = k;
            left = nullptr;
            right = nullptr;
            height = 1;
        }

        ~Node()
        {
        }
    };

public:
    Node *root;

    // Time Complexity: O(1)
    int height(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        else
        {
            return node->height;
        }
    }

    // Time Complexity: O(1)
    int getBalance(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        else
        {
            return height(node->left) - height(node->right);
        }
    }

    // Time Complexity: O(1)
    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    // Time Complexity: O(1)
    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    // Time Complexity: O(log n), where n is the number of nodes in the tree
    Node *insert(Node *node, int key)
    {
        if (node == nullptr)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
        {
            return rightRotate(node);
        }
        if (balance < -1 && key > node->right->key)
        {
            return leftRotate(node);
        }
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Time Complexity: O(log n), where n is the number of nodes in the tree
    void insert(int key)
    {
        root = insert(root, key);
    }

    // Time Complexity: O(n), where n is the number of nodes in the tree
    void __preOrder(Node *root)
    {
        if (root != nullptr)
        {
            cout << root->key << endl;
            __preOrder(root->left);
            __preOrder(root->right);
        }
    }

    // Time Complexity: O(n), where n is the number of nodes in the tree
    void preOrder()
    {
        __preOrder(root);
    }

    // Time Complexity: O(log n), where n is the number of nodes in the tree
    Node *deleteNode(Node *root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (key < root->key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == nullptr || root->right == nullptr)
            {
                Node *temp = root->left ? root->left : root->right;
                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                {
                    *root = *temp;
                }
                delete temp;
            }
            else
            {
                Node *temp = getMax(root->left);
                root->key = temp->key;
                root->left = deleteNode(root->left, temp->key);
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
        {
            return rightRotate(root);
        }
        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0)
        {
            return leftRotate(root);
        }
        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Time Complexity: O(log n), where n is the number of nodes in the tree
    Node *getMax(Node *root)
    {
        Node *current = root;
        while (current->right != nullptr)
        {
            current = current->right;
        }
        return current;
    }

    AVL() : root(nullptr) {}
};

int main()
{
    AVL *tree = new AVL();

    tree->insert(10);
    tree->insert(20);
    tree->insert(30);
    tree->insert(40);
    tree->insert(50);
    tree->insert(90);
    tree->insert(15);
    tree->insert(100);
    tree->insert(500);
    tree->insert(25);

    cout << "Let us print the tree in level order: " << endl;
    tree->preOrder();

    return 0;
}