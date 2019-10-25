#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
  int n, d, acc;
  vector<vector<int> > x;
  set<int> sq;

  for (int i = 0; i < 200; i++) {
    sq.insert(i*i);
  }

  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    vector<int> v;
    for (int j = 0; j < d; j++) {
      int v1;
      cin >> v1;
      v.push_back(v1);
    }
    x.push_back(v);
  }

  acc = 0;
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      int dist_sq = 0;
      for (int k = 0; k < d; k++) {
        int diff;
        diff = x[i][k] - x[j][k];
        dist_sq += diff * diff;
      }
      if (sq.find(dist_sq) != sq.end()) {
        acc++;
      }
    }
  }

  cout << acc << endl;
  return 0;
}
