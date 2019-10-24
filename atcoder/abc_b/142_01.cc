#include <iostream>

int main()
{
  using namespace std;
  int n, k, cnt = 0;

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    if (k <= h) cnt++;
  }

  cout << cnt << endl;

  return 0;
}
