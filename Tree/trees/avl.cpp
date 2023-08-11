#include<bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  int height;
  Node* left;
  Node* right;

  Node(int v, Node* l = nullptr, Node* r = nullptr)
    : val(v), left(l), right(r), height(0) {}
};

int height(Node* n) {
  return n ? n->height : -1;
}

void updateHeight(Node* n) {
  n->height = max(height(n->left), height(n->right)) + 1;
}

// Left-left rotation
Node* rotateLeftLeft(Node* n) {
  Node* tmp = n->left;
  n->left = tmp->right;
  tmp->right = n;

  updateHeight(n);
  updateHeight(tmp);

  return tmp;
}

// Right-right rotation
Node* rotateRightRight(Node* n) {
  Node* tmp = n->right;
  n->right = tmp->left;
  tmp->left = n;

  updateHeight(n);
  updateHeight(tmp);

  return tmp;
}

// Left-right rotation
Node* rotateLeftRight(Node* n) {
  n->left = rotateRightRight(n->left);
  return rotateLeftLeft(n);
}

// Right-left rotation
Node* rotateRightLeft(Node* n) {
  n->right = rotateLeftLeft(n->right);
  return rotateRightRight(n);
}

Node* balance(Node* n) {
  if (height(n->left) - height(n->right) > 1) {
    if (height(n->left->left) >= height(n->left->right)) {
      // Left-left case
      //cout << "Performing left-left rotation on node " << n->val << endl;
      return rotateLeftLeft(n);
    } else {
      // Left-right case
      //cout << "Performing left-right rotation on node " << n->val << endl;
      return rotateLeftRight(n);
    }
  } else if (height(n->right) - height(n->left) > 1) {
    if (height(n->right->right) >= height(n->right->left)) {
      // Right-right case
      //cout << "Performing right-right rotation on node " << n->val << endl;
      return rotateRightRight(n);
    } else {
      // Right-left case
      //cout << "Performing right-left rotation on node " << n->val << endl;
      return rotateRightLeft(n);
    }
  } else {
    // No rotations necessary
    return n;
  }
}



Node* insert(Node* n, int val) {
  if (!n) return new Node(val);

  if (val < n->val) {
    n->left = insert(n->left, val);
  } else {
    n->right = insert( n->right, val);
    }

    updateHeight(n);
    return balance(n);
}

void preorder(Node* n) {
  if (!n) return;

  cout << n->val << " ";
  preorder(n->left);
  preorder(n->right);
}

void post_order(Node *n){
    if(!n) return;
    post_order(n->left);
    post_order(n->right);
    cout<<n->val<<" ";
}

void inorder(Node *n){
    if(!n) return;
    inorder(n->left);
    cout<<n->val<<" ";
    inorder(n->right);
}



int main() {
  /*
  int a[] = {1,2,3};
  int n = sizeof(a)/sizeof(a[0]);
  Node* root = nullptr;
  root = bst(root, a[0]);
  for (int i = 1; i < n; i++) {
    root = bst(root, a[i]);
  }
  bool balanced = isBalanced(root);
  if(balanced) cout << "The tree is balanced" << endl;
  else{
    Node* root = nullptr;
    root = insert(root, a[0]);
    for (int i = 1; i < n; i++) {
      root = insert(root, a[i]);
    }
    preorder(root);
  }*/
  int a[] = {1,2,3,4,5,6,7};
  int n = sizeof(a)/sizeof(a[0]);
  Node* root = nullptr;
  root = insert(root, a[0]);
  for (int i = 1; i < n; i++) {
    root = insert(root, a[i]);
  }
  //preorder(root);
  post_order(root);
  cout<<endl;
  preorder(root);
  cout << endl;

  inorder(root);
}
