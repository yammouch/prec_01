#include <iostream>

using namespace std;

int main()
{
  int exists[2019];
  int l, r, min;

  cin >> l >> r;
  for (int i = 0; i < 2019; i++) {
    exists[i] = 0;
  }
  for (int i = l; i <= r; i++) {
    exists[i%2019] = 1;
  }

  min = 2019;
  for (int i = 0; i < 2018; i++) {
    if (exists[i]) {
      for (int j = i+1; j < 2019; j++) {
        if (exists[j]) {
          int rem = (i*j) % 2019;
          if (rem < min) {
            min = rem;
          }
        }
      }
    }
  }

  cout << min << endl;
  return 0;
}
