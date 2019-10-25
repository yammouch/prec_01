#include <iostream>
#include <queue>

using namespace std;

int main()
{
  int n, m;
  priority_queue<int64_t> a;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int64_t a1;
    cin >> a1;
    a.push(a1);
  }

  for (int i = 0; i < m; i++) {
    int64_t a1 = a.top();
    a.pop();
    a.push(a1 >> 1);
  }

  int64_t acc = 0;
  for (int i = 0; i < n; i++) {
    acc += a.top();
    a.pop();
  }

  cout << acc << endl;
  return 0;
}
