#include <iostream>

int main()
{
  using namespace std;

  int n, acc;
  char c1, c2;

  cin >> n;

  cin >> c1;
  acc = 1;

  for (int i = 1; i < n; i++) {
    cin >> c2;
    if (c1 != c2) acc++;
    c1 = c2;
  }

  cout << acc << endl;

  return 0;
}
