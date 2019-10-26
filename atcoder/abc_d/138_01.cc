#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, q;
  cin >> n >> q;

  vector<vector<int> > g(n);
  vector<int> cnt(n);

  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    g[a-1].push_back(b-1);
  }
  //for (int i = 0; i < g.size(); i++) {
  //  for (int j = 0; j < g[i].size(); j++) {
  //    cout << ' ' << g[i][j];
  //  }
  //  cout << endl;
  //}
  //cout << endl;

  for (int i = 0; i < q; i++) {
    int p, x;
    cin >> p >> x;
    vector<int> stack;
    stack.push_back(p-1);

    while (!stack.empty()) {
      //for (int j = 0; j < stack.size(); j++) {
      //  cout << ' ' << stack[j];
      //}
      //cout << endl;
      int node = stack.back();
      stack.pop_back();
      cnt[node] += x;
      for (auto it = g[node].begin(); it != g[node].end(); it++) {
        stack.push_back(*it);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << cnt[i] << ' ';
  }
  cout << endl;

  return 0;
}
