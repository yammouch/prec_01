#include <iostream>
#include <string>

int main()
{
  using namespace std;
  string s;
  cin >> s;

  for (int i = 0; i < s.size(); i += 2) {
    if (s[i] == 'L') {
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = 1; i < s.size(); i += 2) {
    if (s[i] == 'R') {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}
