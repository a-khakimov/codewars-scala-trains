/* https://www.codewars.com/kata/554ca54ffa7d91b236000023
 * Delete occurrences of an element if it occurs more than n times
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> deleteNth(std::vector<int> arr, size_t n)
{
  std::vector<int> uniqs;
  std::copy(arr.begin(), arr.end(), std::back_inserter(uniqs));

  std::sort(uniqs.begin(), uniqs.end());
  uniqs.resize(
    std::distance(uniqs.begin(),
      std::unique(uniqs.begin(), uniqs.end())));

  for (const auto& uniq : uniqs) {
    size_t count = 0;
    arr.erase(std::remove_if(arr.begin(), arr.end(), [n, &count, &uniq](int i){
      if (i == uniq) {
        ++count;
        if (count > n) {
          return true;
        }
      }
      return false;
    }), arr.end());
  }

  return arr;
}

int main()
{
  auto result = deleteNth({20,37,20,21}, 1);
  for (auto i : result) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;
}
