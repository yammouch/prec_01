#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, lo;
  vector<int> h;

  cin >> n;
  for (int i = 0; i < n; i++) {
    int h1;
    cin >> h1;
    h.push_back(h1);
  }

  lo = h[n-1];
  for (int i = n-2; 0 <= i; i--) {
    if (h[i] <= lo) {
      lo = h[i];
    } else if (h[i] > lo+1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}
