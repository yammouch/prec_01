#include <iostream>
#include <set>

using namespace std;

int main()
{
  int n, m, prev2 = 0, prev1 = 0, prev0 = 1;
  set<int> a;

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a1;
    cin >> a1;
    a.insert(a1);
  }

  for (int i = 1; i <= n; i++) {
    //cout << prev0 << endl;
    prev2 = prev1; prev1 = prev0;
    if (a.find(i) != a.end()) {
      prev0 = 0;
    } else {
      prev0 = (prev1 + prev2)%1000000007;
    }
  }

  cout << prev0 << endl;

  return 0;
}
