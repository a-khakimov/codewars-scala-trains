// https://www.codewars.com/kata/5a8c1b06fd5777d4c00000dd/train/cpp
// Principal Diagonal | VS | Secondary Diagonal

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <functional>

using namespace std;

#include <string>
#include <vector>

std::string diagonal(std::vector<std::vector<int>> matrix)
{
  int p = 0, s = 0;
  for (size_t i = 0; i < matrix.size(); ++i) {
    p += matrix.at(i).at(i);
    s += matrix.at(i).at(matrix.size() - i - 1);
  }
  return (p > s) ? "Principal Diagonal win!"
                 : (p < s) ? "Secondary Diagonal win!"
                           : "Draw!";
};

using V1 = std::vector<int>;
using V2 = std::vector<V1>;

#if true
int main()
{
  std::cout << diagonal(V2{
                 V1{2,2,2},
                 V1{4,2,6},
                 V1{8,8,2}
               }) << std::endl;

  return 0;
}
#endif
