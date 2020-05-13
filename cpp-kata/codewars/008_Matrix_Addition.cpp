// https://www.codewars.com/kata/526233aefd4764272800036f/train/cpp
// Matrix Addition

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <functional>

using namespace std;

vector<vector<int>> matrixAddition(vector<vector<int>> a, vector<vector<int>> b)
{
  transform(a.begin(), a.end(), b.begin(), begin(a), [](auto a, auto b) {
    transform(a.begin(), a.end(), b.begin(), begin(a), plus<int>());
    return a;
  });
  return a;
}

vector<vector<int>> matrixAddition2(vector<vector<int>> a, vector<vector<int>> b)
{
  auto ait = a.begin();
  auto bit = b.begin();
  for (; ait != a.end(); ++ait, ++bit) {
    std::transform(begin(*ait), end(*ait), begin(*bit), begin(*ait), std::plus<int>());
  }
  return a;
}

#if true
int main()
{
  std::vector<std::vector<int> > expected;
  expected = {{3, 4, 4}, {6, 4, 4}, {2, 2, 4}};
  auto matrix = matrixAddition({{1, 2, 3}, {3, 2 , 1}, {1, 1, 1}} , {{2, 2, 1}, {3, 2, 3}, {1, 1, 3}});

  for (auto m : matrix) {
    for (auto i : m) {
      std::cout << i << ", ";
    }
    std::cout << std::endl;
  }

  return 0;
}
#endif
