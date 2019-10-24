#include <iostream>
#include <vector>

int main()
{
  using namespace std;
  vector<int> d;
  int n, sum = 0;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int d1;
    cin >> d1;
    d.push_back(d1);
  }

  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      sum += d[i] * d[j];
    }
  }

  cout << sum << endl;

  return 0;
}
