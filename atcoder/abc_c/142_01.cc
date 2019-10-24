#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool comp(const tuple<int, int> &t1, const tuple<int, int> &t2)
{
  return get<1>(t1) < get<1>(t2);
}

int main()
{
  int n;
  vector<tuple<int, int> > a;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int a1;
    cin >> a1;
    a.push_back(make_tuple(i+1, a1));
  }

  sort(a.begin(), a.end(), comp);

  for (int i = 0; i < n; i++) {
    cout << get<0>(a[i]) << ' ';
  }

  cout << endl;

  return 0;
}
