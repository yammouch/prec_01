#include <iostream>
#include <queue>

using namespace std;

int main()
{
  int n, m;
  priority_queue<int> a;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int a1;
    cin >> a1;
    a.push(a1);
  }

  for (int i = 0; i < m; i++) {
    int a1 = a.top();
    a.pop();
    a.push(a1 >> 1);
  }

  int acc = 0;
  for (int i = 0; i < n; i++) {
    acc += a.top();
    a.pop();
  }

  cout << acc << endl;
  return 0;
}
