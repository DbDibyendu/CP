

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

// Insert into BST
TreeNode *insert(TreeNode *root, int val) {
  if (root == nullptr)
    return new TreeNode(val);

  if (val < root->data) {
    root->left = insert(root->left, val);
  } else {
    root->right = insert(root->right, val);
  }

  return root;
}

// Inorder: Left, Root, Right
void inorderTraversal(TreeNode *root) {
  if (root == nullptr)
    return;
  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}

// Preorder: Root, Left, Right
void preorderTraversal(TreeNode *root) {
  if (root == nullptr)
    return;
  cout << root->data << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// Postorder: Left, Right, Root
void postorderTraversal(TreeNode *root) {
  if (root == nullptr)
    return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout << root->data << " ";
}

// Search for a value, optimised search for BST
bool search(TreeNode *root, int key) {
  if (root == nullptr)
    return false;
  if (root->data == key)
    return true;
  if (key < root->data)
    return search(root->left, key);

  return search(root->right, key);
}

// Height of the tree
int height(TreeNode *root) {
  if (root == nullptr)
    return 0;
  return 1 + max(height(root->left), height(root->right));
}
