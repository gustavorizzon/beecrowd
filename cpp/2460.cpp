#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
  int nPeople;
  cin >> nPeople;

  int queue[nPeople];
  for (int i = 0; i < nPeople; i++)
  {
    cin >> queue[i];
  }

  int npExited;
  cin >> npExited;

  if (npExited >= nPeople)
  {
    return 0;
  }

  unordered_set<int> exited;
  for (int i = 0; i < npExited; i++)
  {
    int id;
    cin >> id;
    exited.insert(id);
  }

  bool first = true;
  for (int i = 0; i < nPeople; i++)
  {
    if (!exited.count(queue[i]))
    {
      if (!first)
        cout << " ";

      cout << queue[i];
      first = false;
    }
  }

  cout << endl;

  return 0;
}