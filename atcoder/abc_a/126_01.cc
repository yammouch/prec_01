#include <iostream>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (i == k-1) {
      cout << (char)(c | 0x60);
    } else {
      cout << c;
    }
  }

  cout << endl;
  return 0;
}
