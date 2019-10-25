#include <iostream>

using namespace std;

template <class T> T gcd(T n1, T n2)
{
  if (n1 < n2) {
    T tmp;
    tmp = n1; n1 = n2; n2 = tmp;
  }

  while (n2 != 0) {
    T r;
    r = n1 % n2;
    n1 = n2;
    n2 = r;
    //cout << n1 << ' ' << n2 << endl;
  }
  return n1;
}

int main()
{
  int64_t a, b, c, d, cd, div_c, div_d, div_cd;
  cin >> a >> b >> c >> d;

  div_c = b/c - (a-1)/c;
  div_d = b/d - (a-1)/d;
  cd = c * d / gcd<int64_t>(c, d);
  div_cd = b/cd - (a-1)/cd;

  //cout << div_c << ' ' << div_d << ' ' << cd << ' ' << div_cd << endl;
  cout << b - a + 1 - (div_c + div_d - div_cd) << endl;

  return 0;
}
