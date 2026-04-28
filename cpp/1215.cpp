#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace tree {
  struct node {
    string value;
    node* left;
    node* right;
  };

  node* create_node(const string& val) {
    node* n = new node;
    n->value = val;
    n->left = nullptr;
    n->right = nullptr;

    return n;
  }

  void insert(node*& root, const string& val) {
    if (root == nullptr) {
      root = create_node(val);
    } else if (val < root->value) {
      insert(root->left, val);
    } else if (val > root->value) {
      insert(root->right, val);
    }
  }

  void dfs_in(const node* root) {
    if (root == nullptr) return;

    dfs_in(root->left);
    cout << root->value << "\n";
    dfs_in(root->right);
  }
}  // namespace tree

int main() {
  tree::node* root = nullptr;

  string line;
  while (getline(cin, line)) {
    string word;
    for (char c : line) {
      if (isalpha(c)) {
        word += tolower(c);
      } else {
        if (!word.empty()) {
          tree::insert(root, word);
          word.clear();
        }
      }
    }
    if (!word.empty()) {
      tree::insert(root, word);
    }
  }

  tree::dfs_in(root);
}