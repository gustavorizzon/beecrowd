#include <cctype>
#include <iostream>

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

  std::string dps_pre(const node* root) {
    if (root == nullptr) return "";

    return std::to_string(root->value) + " " + dps_pre(root->left) +
           dps_pre(root->right);
  }

  std::string dps_in(const node* root) {
    if (root == nullptr) return "";

    return dps_in(root->left) + std::to_string(root->value) + " " +
           dps_in(root->right);
  }
  std::string dps_post(const node* root) {
    if (root == nullptr) return "";

    return dps_post(root->left) + dps_post(root->right) +
           std::to_string(root->value) + " ";
  }
}  // namespace tree

std::string trim_right(string s) {
  auto end = s.size();

  while (end > 0 && isspace(s[end - 1])) {
    end--;
  }

  s.erase(end);

  return s;
}

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
    cout << "Pre.: " << trim_right(tree::dps_pre(root)) << endl;
    cout << "In..: " << trim_right(tree::dps_in(root)) << endl;
    cout << "Post: " << trim_right(tree::dps_post(root)) << endl;
    cout << endl;
  }
}