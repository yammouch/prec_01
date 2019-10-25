#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, k, q;

  cin >> n >> k >> q;

  vector<int> player(k, 0);

  for (int i = 0; i < q; i++) {
    int a;
    cin >> a;
    player[a-1]++;
  }

  for (int i = 0; i < n; i++) {
    if (0 < player[i] + k - q) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
