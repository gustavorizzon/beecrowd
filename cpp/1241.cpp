#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;

  while (n-- > 0)
  {
    string t1, t2;
    cin >> t1;
    cin >> t2;

    if (t1.length() < t2.length())
    {
      cout << "nao encaixa" << endl;
      continue;
    }

    string strPart = t1.substr(t1.length() - t2.length(), t2.length());

    cout << (strPart == t2 ? "encaixa" : "nao encaixa") << endl;
  }

  return 0;
}