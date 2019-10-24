#include <iostream>

int main()
{
  int n, a, b, prod;
  std::cin >> n >> a >> b;

  prod = n*a;

  if (prod < b) {
    std::cout << prod;
  } else {
    std::cout << b;
  }
  std::cout << std::endl;

  return 0;
}
