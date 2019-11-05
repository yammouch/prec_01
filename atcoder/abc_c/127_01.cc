#include <iostream>

using namespace std;

int main()
{
  int n, m, lmax = 0, rmin = 100001;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    if (lmax < l) {
      lmax = l;
    }
    if (r < rmin) {
      rmin = r;
    }
  }
  if (lmax > rmin) {
    cout << 0 << endl;
  }
  else {
    cout << rmin - lmax + 1 << endl;
  }
  return 0;
}
