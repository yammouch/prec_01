#include <iostream>

using namespace std;

int main()
{
  int n, x, l, d = 0, cnt = 1;
  cin >> n >> x;

  for (int i = 0; i < n; i++) {
    cin >> l;
    d += l;
    if (d <= x) {
      cnt++;
    } else {
      break;
    }
    //cout << d << endl;
  }

  cout << cnt << endl;

  return 0;
}
