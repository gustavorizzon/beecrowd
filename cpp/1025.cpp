#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  short nCase = 1;

  do
  {
    int nMarbles;
    do
    {
      cin >> nMarbles;
    } while (nMarbles < 0 || nMarbles > 10000);

    int nQueries;
    do
    {
      cin >> nQueries;
    } while (nQueries < 0 || nQueries > 10000);

    if (nMarbles == 0 && nQueries == 0)
      break;

    cout << "CASE# " << nCase++ << ":" << endl;

    int marbles[nMarbles];
    for (int m = 0; m < nMarbles; m++)
    {
      cin >> marbles[m];
    }

    sort(marbles, marbles + nMarbles);

    for (int q = 0; q < nQueries; q++)
    {
      int query;
      cin >> query;

      bool found = false;
      for (int m = 0; m < nMarbles; m++)
      {
        if (marbles[m] == query)
        {
          found = true;
          cout << query << " found at " << m + 1 << endl;
          break;
        }
      }

      if (!found)
      {
        cout << query << " not found" << endl;
      }
    }
  } while (nCase < 65);

  return 0;
}