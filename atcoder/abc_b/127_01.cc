#include <iostream>

using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  if (13 <= a) {
    cout << b << endl;
  } else if (6 <= a) {
    cout << (b >> 1) << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
