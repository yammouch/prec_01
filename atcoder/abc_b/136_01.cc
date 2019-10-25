#include <iostream>

using namespace std;

int main()
{
  int n, x, acc;

  cin >> n;

  x = 1;
  acc = 0;
  do {
    if (n < x*10) {
      acc += n - x + 1;
    } else {
      acc += x*9;
    }
    x *= 100;
  } while (x <= n);

  cout << acc << endl;
}
