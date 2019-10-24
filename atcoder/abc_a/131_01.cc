#include <iostream>

int main()
{
  using namespace std;
  string str;

  cin >> str;

  for (int i = 0; i < 3; i++) {
    if (str[i] == str[i+1]) {
      cout << "Bad" << endl;
      return 0;
    }
  }

  cout << "Good" << endl;
  return 0;
}
