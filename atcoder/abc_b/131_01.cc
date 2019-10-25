#include <iostream>

using namespace std;

int main()
{
  int n, l, sum;
  cin >> n >> l;

  sum = n*(l + l + n - 1)/2;

  if (l + n - 1 < 0) {
    sum -= l + n - 1;
  } else if (0 < l ) {
    sum -= l;
  }

  cout << sum << endl;

  return 0;
}
