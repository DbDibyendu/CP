
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

// Insert into binary tree in level order
TreeNode *insert(TreeNode *root, int val) {
  if (root == nullptr)
    return new TreeNode(val);

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *curr = q.front();
    q.pop();

    if (!curr->left) {
      curr->left = new TreeNode(val);
      break;
    } else {
      q.push(curr->left);
    }

    if (!curr->right) {
      curr->right = new TreeNode(val);
      break;
    } else {
      q.push(curr->right);
    }
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

// Search for a value
bool search(TreeNode *root, int key) {
  if (root == nullptr)
    return false;
  if (root->data == key)
    return true;
  return search(root->left, key) || search(root->right, key);
}

// Height of the tree
int height(TreeNode *root) {
  if (root == nullptr)
    return 0;
  return 1 + max(height(root->left), height(root->right));
}
