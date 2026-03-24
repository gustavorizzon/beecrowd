#include <iostream>
#include <list>

using namespace std;

int hashFunction(int index, int hashTableSize) {
  return index % hashTableSize;
}

int main() {
  int tests;
  cin >> tests;

  for (int t = 0; t < tests; t++) {
    int hashTableSize;
    cin >> hashTableSize;

    int keysAmount;
    cin >> keysAmount;

    list<int> hashTable[hashTableSize];

    // read
    for (int i = 0; i < keysAmount; i++) {
      int n;
      cin >> n;
      hashTable[hashFunction(n, hashTableSize)].push_back(n);
    }

    // print
    for (int i = 0; i < hashTableSize; i++) {
      cout << i << " -> ";

      for (auto it = hashTable[i].begin(); it != hashTable[i].end(); ++it) {
        cout << *it << " -> ";
      }

      cout << "\\" << endl;
    }

    if (t != tests - 1) cout << endl;
  }

  return 0;
}