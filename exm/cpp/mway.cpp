#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    vector<int> keys;
    vector<TreeNode*> children;
    int t;  // Minimum degree (defines the range for number of keys)

    TreeNode(int _t, bool _isLeaf) {
        t = _t;
        keys.resize(2 * t - 1);
        children.resize(2 * t);
    }

    bool isLeaf() {
        return children[0] == nullptr;
    }
};

class MWaySearchTree {
public:
    TreeNode* root;
    int t;  // Minimum degree

    MWaySearchTree(int _t) {
        root = nullptr;
        t = _t;
    }

    void insert(int key) {
        // If root is null, create a new root
        if (root == nullptr) {
            root = new TreeNode(t, true);
            root->keys[0] = key;
            root->children[0] = nullptr;
            root->children[1] = nullptr;
        } else {
            // If root is full, then tree grows in height
            if (root->keys.size() == 2 * t - 1) {
                TreeNode* newRoot = new TreeNode(t, false);
                newRoot->children[0] = root;
                splitChild(newRoot, 0, root);
                int i = 0;
                if (newRoot->keys[0] < key) {
                    i++;
                }
                insertNonFull(newRoot->children[i], key);
                root = newRoot;
            } else {
                insertNonFull(root, key);
            }
        }
    }

private:
    void insertNonFull(TreeNode* node, int key) {
        int i = node->keys.size() - 1;

        // If this is a leaf node
        if (node->isLeaf()) {
            node->keys.resize(node->keys.size() + 1);
            while (i >= 0 && node->keys[i] > key) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
        } else {
            // Find the child which is going to have the new key
            while (i >= 0 && node->keys[i] > key) {
                i--;
            }
            // Check if the found child is full
            if (node->children[i + 1]->keys.size() == 2 * t - 1) {
                splitChild(node, i + 1, node->children[i + 1]);
                if (node->keys[i + 1] < key) {
                    i++;
                }
            }
            insertNonFull(node->children[i + 1], key);
        }
    }

    void splitChild(TreeNode* parent, int i, TreeNode* child) {
        TreeNode* newChild = new TreeNode(t, child->isLeaf());
        newChild->keys.resize(t - 1);

        for (int j = 0; j < t - 1; j++) {
            newChild->keys[j] = child->keys[j + t];
        }

        if (!child->isLeaf()) {
            newChild->children.resize(t);
            for (int j = 0; j < t; j++) {
                newChild->children[j] = child->children[j + t];
            }
        }

        child->keys.resize(t - 1);
        parent->children.resize(parent->children.size() + 1);

        for (int j = parent->children.size() - 1; j >= i + 1; j--) {
            parent->children[j] = parent->children[j - 1];
        }

        parent->children[i + 1] = newChild;

        for (int j = parent->keys.size(); j >= i; j--) {
            parent->keys[j] = parent->keys[j - 1];
        }

        parent->keys[i] = child->keys[t - 1];
        parent->keys.resize(parent->keys.size() + 1);
    }
};

int main() {
    MWaySearchTree tree(3);  // Creating an M-Way Search Tree with t = 3

    // Inserting elements
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    // Add code for traversal or other operations as needed

    return 0;
}
