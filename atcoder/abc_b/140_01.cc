#include <iostream>
#include <vector>

int main()
{
  using namespace std;

  int i, n;
  vector<int> a, b, c;
  int score = 0;

  cin >> n;

  for (i = 0; i < n; i++) {
    int a1;
    cin >> a1;
    a.push_back(a1);
  }

  for (i = 0; i < n; i++) {
    int b1;
    cin >> b1;
    b.push_back(b1);
  }

  for (i = 0; i < n-1; i++) {
    int c1;
    cin >> c1;
    c.push_back(c1);
  }

  for (i = 0; i < n; i++) {
    score += b[a[i]-1];
  }

  for (i = 0; i < n-1; i++) {
    if (a[i+1] - a[i] == 1) {
      score += c[a[i]-1];
    }
  }

  cout << score << endl;

  return 0;
}
