#include <iostream>

using namespace std;

int main()
{
  int w, h, x, y;

  cin >> w >> h >> x >> y;

  cout << 0.5 * w * h << endl;
  if (2*x == w && 2*y == h) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}
