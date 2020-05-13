// https://www.codewars.com/kata/5a8bcd980025e99381000099/train/cpp
// Array - squareUp b!

#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> squareUp(int n)
{
  std::vector<int> result;
  for (int i = n - 1; i >= 0; --i) {
    std::vector<int> part(n);
    std::iota(part.rbegin(), part.rend() - i, 1);
    std::move(part.begin(), part.end(), std::back_inserter(result));
  }
  return result;
}

#if false
int main()
{
  auto result = squareUp(9);
  for (auto p : result) std::cout << p << ", ";
  std::cout << std::endl;
  return 0;
}
#endif
