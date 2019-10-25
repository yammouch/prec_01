#include <iostream>

using namespace std;

int main()
{
  int n, cnt;

  cin >> n;
  cnt = 0;
  for (int i = 0; i < n; i++) {
    int p1;
    cin >> p1;
    if (p1 != i+1) {
      cnt++;
    }
  }

  if (cnt <= 2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
