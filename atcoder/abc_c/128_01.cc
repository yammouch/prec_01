#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> s(n+1);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    int sw_one_hot = 1 << i;
    for (int j = 0; j < k; j++) {
      int s1;
      cin >> s1;
      //cout << s1 << ' ' << sw_one_hot << endl;
      s[s1-1] |= sw_one_hot;
    }
  }

  for (int i = 0; i < m; i++) {
    int p;
    cin >> p;
    s[n] |= p << i;
  }

  //for (auto it = s.begin(); it != s.end(); it++) {
  //  cout << *it << endl;
  //}

  int loop_size = 1 << n;
  int cnt = 0;
  for (int i = 0; i < loop_size; i++) {
    int sw_xor = s[n];
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        sw_xor ^= s[j];
      }
    }
    //cout << i << ' ' << sw_xor << endl;
    if (!sw_xor) {
      cnt++;
    }
  }

  cout << cnt << endl;
  return 0;
}
