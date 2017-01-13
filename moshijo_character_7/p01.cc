#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, m;
  vector<int> p, s, d;

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x; p.push_back(x);
    cin >> x; s.push_back(x);
    cin >> x; d.push_back(x);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int c, a;
    cin >> c; c--;
    cin >> a;
    cout << p[c]*a - a/s[c] * d[c] << endl;
  }
  return 0;
}
