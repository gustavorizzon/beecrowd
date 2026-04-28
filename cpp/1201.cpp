#include <iostream>
#include <string>

using namespace std;

namespace tree {
  struct node {
    int value;
    node* left;
    node* right;
  };

  node* create_node(const int& val) {
    node* n = new node;
    n->value = val;
    n->left = nullptr;
    n->right = nullptr;
    return n;
  }

  void insert(node*& root, const int& val) {
    if (root == nullptr) {
      root = create_node(val);
    } else if (val < root->value) {
      insert(root->left, val);
    } else if (val > root->value) {
      insert(root->right, val);
    }
  }

  bool search(const node* root, const int& val) {
    if (root == nullptr) return false;
    if (val == root->value) return true;
    if (val < root->value) return search(root->left, val);
    return search(root->right, val);
  }

  node* remove_max(node*& root) {
    if (root->right == nullptr) {
      node* n = root;
      root = root->left;
      return n;
    }
    return remove_max(root->right);
  }

  void remove(node*& root, const int& val) {
    if (root == nullptr) return;

    if (val < root->value) {
      remove(root->left, val);
    } else if (val > root->value) {
      remove(root->right, val);
    } else {
      if (root->left == nullptr && root->right == nullptr) {
        delete root;
        root = nullptr;
      } else if (root->left == nullptr) {
        node* tmp = root;
        root = root->right;
        delete tmp;
      } else if (root->right == nullptr) {
        node* tmp = root;
        root = root->left;
        delete tmp;
      } else {
        node* predecessor = remove_max(root->left);
        predecessor->left = root->left;
        predecessor->right = root->right;
        delete root;
        root = predecessor;
      }
    }
  }

  void infixa(const node* root, bool& first) {
    if (root == nullptr) return;
    infixa(root->left, first);
    if (!first) cout << " ";
    cout << root->value;
    first = false;
    infixa(root->right, first);
  }

  void prefixa(const node* root, bool& first) {
    if (root == nullptr) return;
    if (!first) cout << " ";
    cout << root->value;
    first = false;
    prefixa(root->left, first);
    prefixa(root->right, first);
  }

  void posfixa(const node* root, bool& first) {
    if (root == nullptr) return;
    posfixa(root->left, first);
    posfixa(root->right, first);
    if (!first) cout << " ";
    cout << root->value;
    first = false;
  }
}  // namespace tree

int main() {
  tree::node* root = nullptr;
  string cmd;

  while (cin >> cmd) {
    if (cmd == "I") {
      int val;
      cin >> val;
      tree::insert(root, val);
    } else if (cmd == "P") {
      int val;
      cin >> val;
      if (tree::search(root, val)) {
        cout << val << " existe" << endl;
      } else {
        cout << val << " nao existe" << endl;
      }
    } else if (cmd == "R") {
      int val;
      cin >> val;
      tree::remove(root, val);
    } else if (cmd == "INFIXA") {
      bool first = true;
      tree::infixa(root, first);
      cout << endl;
    } else if (cmd == "PREFIXA") {
      bool first = true;
      tree::prefixa(root, first);
      cout << endl;
    } else if (cmd == "POSFIXA") {
      bool first = true;
      tree::posfixa(root, first);
      cout << endl;
    }
  }

  return 0;
}