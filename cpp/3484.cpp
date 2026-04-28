#include <iostream>
#include <map>
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

  map<int, int> min_per_level(node* root) {
    map<int, int> result;
    queue<pair<const node*, int> > q;

    q.push(make_pair(root, 0));

    while (!q.empty()) {
      const node* current = q.front().first;
      int level = q.front().second;
      q.pop();

      if (!result[level] || current->value < result[level]) {
        result[level] = current->value;
      }

      if (current->left) q.push(make_pair(current->left, level + 1));
      if (current->right) q.push(make_pair(current->right, level + 1));
    }

    return result;
  }
}  // namespace tree

int main() {
  int n;
  cin >> n;

  tree::node* root = nullptr;

  while (n-- > 0) {
    int val;
    cin >> val;
    tree::insert(root, val);
  }

  map<int, int> result = tree::min_per_level(root);

  for (map<int, int>::iterator it = result.begin(); it != result.end(); ++it) {
    cout << it->first << " " << it->second << endl;
  }
}