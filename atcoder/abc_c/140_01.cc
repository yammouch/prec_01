#include <iostream>

using namespace std;

int main()
{
  int n, sum, b1;

  cin >> n;
  cin >> b1;
  sum = b1;
  for (int i = 0; i < n-2; i++) {
    int b2;
    cin >> b2;
    if (b1 < b2) {
      sum += b1;
    } else {
      sum += b2;
    }
    b1 = b2;
  }
  cin >> b1;
  sum += b1;

  cout << sum << endl;
  return 0;
}
