#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

bool lt(const tuple<string, int, int> &x1, const tuple<string, int, int> &x2)
{
  if (get<0>(x1) == get<0>(x2)) {
    return get<1>(x1) > get<1>(x2);
  } else {
    return get<0>(x1) < get<0>(x2);
  }
}

int main()
{
  int n;
  cin >> n;

  vector<tuple<string, int, int> > v;

  for (int i = 0; i < n; i++) {
    string s;
    int p;
    cin >> s >> p;
    v.push_back(make_tuple(s, p, i+1));
  }
  sort(v.begin(), v.end(), lt);

  for (int i = 0; i < n; i++) {
    cout << get<2>(v[i]) << endl;
  } 

  return 0;
}
