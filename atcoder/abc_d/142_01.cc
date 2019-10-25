#include <iostream>
#include <map>

using namespace std;

template <class T> T gcd(T a, T b)
{
  if (a < b) {
    T tmp;
    tmp = a; a = b; b = tmp;
  }
  while (b != 0) {
    T r = a % b, q = a / b;
    a = b; b = r;
  }
  return a;
}

template <class T> map<T, int> prime_factor(T n)
{
  map<T, int> ret;
  for (T i = 2; i*i <= n; i++) {
    while (n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if (n != 1) ret[n] = 1;
  return ret;
}

int main()
{
  int64_t a, b;
  cin >> a >> b;

  int64_t g = gcd<int64_t>(a, b);
  map<int64_t, int> p = prime_factor<int64_t>(g);

  cout << p.size() + 1 << endl;
  return 0;
}
