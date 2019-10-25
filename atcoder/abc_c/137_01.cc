#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int64_t n, cnt, sum;
  char s1[11];
  vector<string> s;

  cin >> n;

  for (int64_t i = 0; i < n; i++) {
    cin >> s1;
    sort(s1, s1+10);
    string s1_s(s1);
    s.push_back(s1_s);
  }
  sort(s.begin(), s.end());

  //for (auto it = s.begin(); it != s.end(); it++) {
  //  cout << *it << endl;
  //}

  sum = 0; cnt = 1;
  for (int64_t i = 1; i < n; i++) {
    if (s[i-1] == s[i]) {
      cnt++;
    } else {
      sum += cnt*(cnt-1)/2;
      cnt = 1;
    }
  }
  sum += cnt*(cnt-1)/2;

  cout << sum << endl;
  return 0;
}
