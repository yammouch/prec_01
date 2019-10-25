#include <iostream>

using namespace std;

int main()
{
  int n, k, toggle = 0, happy;
  char c, c_prev;
  cin >> n >> k >> c_prev;

  for (int i = 1; i < n; i++) {
    cin >> c;
    if (c != c_prev) {
      toggle++;
    }
    c_prev = c;
  }
  //cout << toggle << endl;

  happy = n - 1 - toggle;
  if (k*2 <= toggle) {
    cout << happy + 2*k << endl;
  } else {
    cout << n - 1 << endl;
  }

  return 0;
}
