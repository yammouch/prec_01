#include <iostream>

using namespace std;

int main()
{
  int a, b, d;
  cin >> a >> b;
  d = a - b*2;
  if (d < 0) d = 0;
  cout << d << endl;
  return 0;
}
