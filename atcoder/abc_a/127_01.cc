#include <iostream>

using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  if (13 <= a) {
    cout << b;
  } else if (6 <= a) {
    cout << (b >> 1);
  } else {
    cout << 0;
  }
  cout << endl;
  return 0;
}
