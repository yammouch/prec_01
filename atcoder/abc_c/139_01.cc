#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  vector<int> h;
  int move_max, move_cnt;

  cin >> n;
  for (int i = 0; i < n; i++) {
    int h1;
    cin >> h1;
    h.push_back(h1);
  }

  move_max = 0;
  move_cnt = 0;
  for (int i = n-2; 0 <= i; i--) {
    if (h[i] >= h[i+1]) {
      move_cnt++;
    } else {
      if (move_max < move_cnt) {
        move_max = move_cnt;
      }
      move_cnt = 0;
    }
  }
  if (move_max < move_cnt) {
    move_max = move_cnt;
  }
  cout << move_max << endl;
  return 0;
}
