#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  int trips;
  cin >> trips;

  for (int t = 0; t < trips; t++) {
    int nProducts;
    cin >> nProducts;

    unordered_map<string, float> products;
    for (int p = 0; p < nProducts; p++) {
      string productName;
      cin >> productName;

      float price;
      cin >> price;

      products[productName] = price;
    }

    int nPurchase;
    cin >> nPurchase;

    float total = 0.0f;
    for (int p = 0; p < nPurchase; p++) {
      string product;
      cin >> product;

      int quantity;
      cin >> quantity;

      total += products[product] * quantity;
    }

    cout << "R$ " << fixed << setprecision(2) << total << endl;
  }

  return 0;
}