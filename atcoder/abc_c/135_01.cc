#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int64_t n, acc;
  vector<int64_t> a, b;

  cin >> n;
  for (int64_t i = 0; i < n+1; i++) {
    int64_t a1;
    cin >> a1;
    a.push_back(a1);
  }
  for (int64_t i = 0; i < n; i++) {
    int64_t b1;
    cin >> b1;
    b.push_back(b1);
  }

  acc = 0;
  for (int64_t i = 0; i < n; i++) {
    if (a[i] < b[i]) {
      acc += a[i];
      b[i] -= a[i];
    } else {
      acc += b[i];
      b[i] = 0;
    }
    if (b[i] < a[i+1]) {
      acc += b[i];
      a[i+1] -= b[i];
    } else {
      acc += a[i+1];
      a[i+1] = 0;
    }
  }

  //for (int64_t i = 0; i < n+1; i++) {
  //  cout << a[i] << ' ';
  //}
  //cout << endl;
  //for (int64_t i = 0; i < n; i++) {
  //  cout << b[i] << ' ';
  //}
  //cout << endl;

  cout << acc << endl;
  return 0;
}
