#include <cctype>
#include <iostream>
#include <queue>

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

  void bfs(node* root) {
    std::queue<const node*> q;

    q.push(root);

    while (!q.empty()) {
      auto current = q.front();
      cout << current->value;
      q.pop();

      if (current->left) q.push(current->left);
      if (current->right) q.push(current->right);

      if (!q.empty()) {
        cout << " ";
      }
    }

    cout << endl;
  }
}  // namespace tree

int main() {
  int c;
  cin >> c;

  for (int i = 1; i <= c; i++) {
    int n;
    cin >> n;

    tree::node* root = nullptr;

    while (n-- > 0) {
      int val;
      cin >> val;
      tree::insert(root, val);
    }

    cout << "Case " << i << ":" << endl;
    tree::bfs(root);
    cout << endl;
  }
}