#include <iostream>
#include <cctype>

using namespace std;

int main()
{
  int n;

  cin >> n;

  while (n-- > 0)
  {
    string s;
    cin >> s;

    char op = s[1];
    int n1 = s[0] - '0';
    int n2 = s[2] - '0';

    if (n1 == n2)
    {
      cout << n1 * n2 << endl;
    }
    else if (isupper(op))
    {
      cout << n2 - n1 << endl;
    }
    else
    {
      cout << n1 + n2 << endl;
    }
  }

  return 0;
}