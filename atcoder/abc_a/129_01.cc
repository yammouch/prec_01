#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  vector<int> v;

  for (int i = 0; i < 3; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());

  cout << v[0] + v[1] << endl;
  return 0;
}
