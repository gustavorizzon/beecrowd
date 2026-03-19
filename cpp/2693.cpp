#include <iostream>
#include <algorithm>

using namespace std;

struct Student
{
  int cost;
  char region;
  string name;

  static bool compare(const Student &sA, const Student &sB)
  {
    if (sA.cost != sB.cost)
      return sA.cost < sB.cost;

    if (sA.region != sB.region)
      return sA.region < sB.region;

    return sA.name < sB.name;
  }
};

int main()
{
  int nStudents;
  while (cin >> nStudents)
  {
    vector<Student> students;
    for (int i = 0; i < nStudents; i++)
    {
      Student s;
      cin >> s.name;
      cin >> s.region;
      cin >> s.cost;

      students.push_back(s);
    }

    sort(students.begin(), students.end(), Student::compare);

    for (const Student &student : students)
    {
      cout << student.name << endl;
    }
  }

  return 0;
}