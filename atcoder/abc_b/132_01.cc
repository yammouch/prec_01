#include <iostream>

using namespace std;

int main()
{
  int n, a2, a1, a0, cnt = 0;
  cin >> n >> a2 >> a1;

  for (int i = 2; i < n; i++) {
    cin >> a0;
    if ((a2 < a1 && a1 < a0) || (a0 < a1 && a1 < a2)) {
      cnt++;
    }
    a2 = a1; a1 = a0;
  }

  cout << cnt << endl;
  return 0;
}
