#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n, *d;
  cin >> n;
  d = new int[n];

  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }

  sort(d, d+n);

  cout << d[n/2] - d[n/2 - 1] << endl;

  delete [] d;

  return 0;
}
