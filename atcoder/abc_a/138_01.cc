#include <iostream>

int main()
{
  using namespace std;

  int a;
  string s;

  cin >> a >> s;

  if (3200 <= a) {
    cout << s << endl;
  } else {
    cout << "red" << endl;
  }

  return 0;
}
