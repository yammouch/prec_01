#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, din, sum, flag, diff;
  vector<int> v;

  cin >> n;

  sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> din;
    sum += din;
    v.push_back(din);
  }

  //cout << sum << endl;
  flag = 1;
  for (int i = 0; i < n; i++) {
    diff = sum - v[i];
    if (diff <= v[i]) {
      flag = 0;
    }
  }

  if (flag) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  cout << endl;

  return 0;
}
