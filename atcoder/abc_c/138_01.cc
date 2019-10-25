#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  vector<int> v;
  double acc;

  cin >> n;
  for (int i = 0; i < n; i++) {
    int v1;
    cin >> v1;
    v.push_back(v1);
  }

  sort(v.begin(), v.end());

  acc = v[0];
  for (int i = 1; i < n; i++) {
    acc = 0.5*(acc + v[i]);
  }

  cout << acc << endl;

  return 0;
}
