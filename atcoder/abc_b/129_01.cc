#include <iostream>

using namespace std;

int main()
{
  int n, *w, *sum1, *sum2, min;
  cin >> n;
  w = new int[n];
  sum1 = new int[n-1];
  sum2 = new int[n-1];

  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }

  sum1[0] = w[0];
  for (int i = 1; i < n-1; i++) {
    sum1[i] = sum1[i-1] + w[i];
  }
  sum2[n-2] = w[n-1];
  for (int i = n-3; 0 <= i; i--) {
    sum2[i] = sum2[i+1] + w[i+1];
  }

  //for (int i = 0; i < n-1; i++) {
  //  cout << ' ' << sum1[i];
  //}
  //cout << endl;
  //for (int i = 0; i < n-1; i++) {
  //  cout << ' ' << sum2[i];
  //}
  //cout << endl;

  min = 9999999;
  for (int i = 0; i < n-1; i++) {
    int diff;
    diff = sum1[i] - sum2[i];
    if (diff < 0) {
      diff = -diff;
    }
    if (diff < min) {
      min = diff;
    }
  }

  cout << min << endl;

  delete [] w;
  delete [] sum1;
  delete [] sum2;
}
