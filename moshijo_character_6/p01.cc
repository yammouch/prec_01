#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, x;
  vector<int> col, row;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    col.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    cin >> x;
    row.push_back(x);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << row[i]+col[j];
      if (j == n-1) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }

  return 0;
}
