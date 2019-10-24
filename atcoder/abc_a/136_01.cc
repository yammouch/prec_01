#include <iostream>

int main()
{
  using namespace std;

  int a, b, c, room;
  cin >> a >> b >> c;
  room = a - b;

  if (c < room) {
    cout << 0 << endl;
  } else {
    cout << c - room << endl;
  }

  return 0;
}
