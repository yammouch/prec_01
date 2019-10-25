#include <iostream>

using namespace std;

int main()
{
  int n;
  double sum;

  cin >> n;

  sum = 0.0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    sum += 1.0/a;
  }

  cout << 1.0/sum << endl;

  return 0;
}
