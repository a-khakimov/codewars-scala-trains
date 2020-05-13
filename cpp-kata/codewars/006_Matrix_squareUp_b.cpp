// https://www.codewars.com/kata/5a972f30ba1bb5a2590000a0/train/cpp
// Matrix Square Up, B!

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <functional>

using namespace std;

vector<vector<string>> matrixSquareUp(int b)
{
  vector<vector<int>> vvi;
  for (int i = b - 1; i >= 0; --i) {
    vector<int> part(b);
    iota(part.rbegin(), part.rend() - i, 1);
    vvi.push_back(part);
  }
  vector<vector<string>> vvs;
  transform(vvi.begin(), vvi.end(), back_inserter(vvs), [](auto vi) {
    vector<string> vs;
    std::transform(vi.begin(), vi.end(), std::back_inserter(vs), [](auto i) {
      return (i > 0) ? std::to_string(i) : "x"s;
    });
    return vs;
  });
  return vvs;
}

#if true
int main()
{
  auto result = matrixSquareUp(10);
  for (auto p : result) {
    for (auto s : p) {
      std::cout << s << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
#endif
