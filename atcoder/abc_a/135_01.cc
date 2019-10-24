#include <iostream>

int main()
{
  using namespace std;
  unsigned int a, b;

  cin >> a >> b;
  a += b;

  if (a & 1) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << (a >> 1) << endl;
  }

  return 0;
}
