#include <iostream>
#include <vector>

int main()
{
  using namespace std;
  int a, b, max;
  vector<int> v;

  cin >> a >> b;
  v.push_back(a+b);
  v.push_back(a-b);
  v.push_back(a*b);

  max = -99999;	
  for (auto it = v.begin(); it != v.end(); it++) {
    if (max < *it) max = *it;
  }

  cout << max << endl;

  return 0;
}
