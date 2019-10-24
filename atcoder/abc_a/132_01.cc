#include <iostream>

int main()
{
  using namespace std;

  int cnt[26];
  int sum;

  for (int i = 0; i < 26; i++) {
    cnt[i] = 0;
  }

  for (int i = 0; i < 4; i++) {
    char c;
    cin >> c;
    cnt[c - 'A']++;
  }

  sum = 0;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] != 0 && cnt[i] != 2) {
      cout << "No" << endl;
      return 0;
    }
    sum += cnt[i];
  }

  if (sum == 4) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
