#include <iostream>

using namespace std;

int main()
{
  int n, max1, max1_i, max2;

  //cin >> n >> max1 >> max2;
  cin >> n;
  max1 = max2 = 0;

  //if (max1 < max2) {
  //  int tmp;
  //  max1_i = 1;
  //  tmp = max1;
  //  max1 = max2;
  //  max2 = tmp;
  //} else {
  //  max1_i = 0;
  //}

  //for (int i = 2; i < n; i++) {
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (max1 <= a) {
      max1_i = i;
      max2 = max1;
      max1 = a;
    } else if (max2 <= a) {
      max2 = a;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i == max1_i) {
      cout << max2 << endl;
    } else {
      cout << max1 << endl;
    }
  }

  return 0;
}
