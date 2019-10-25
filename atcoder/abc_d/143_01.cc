#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n, *l, acc;
  cin >> n;

  l = new int[n];

  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }

  sort(l, l+n);

  acc = 0;
  for (int i = 0; i < n-2; i++) {
    for (int j = i+1; j < n-1; j++) {
      for (int k = j+1; k < n && l[k] < l[i] + l[j]; k++) {
        //cout << l[i] << ' ' << l[j] << ' ' << l[k] << endl;
        if (l[i] < l[j] + l[k] && l[j] < l[k] + l[i]) {
          acc++;
        }
      }
    }
  }

  delete [] l;

  cout << acc << endl;
  return 0;
}
