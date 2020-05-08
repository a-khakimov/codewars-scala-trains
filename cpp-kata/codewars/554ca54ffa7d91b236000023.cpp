/* https://www.codewars.com/kata/554ca54ffa7d91b236000023
 * Delete occurrences of an element if it occurs more than n times
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
    arr.erase(std::remove_if(arr.begin(), arr.end(), [n, &count, &uniq](int i) {
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

/* Unnamed */
std::vector<int> deleteNth2(const std::vector<int>& arr, const size_t n)
{
  std::vector<int> resut;
  std::unordered_map<int, size_t> uniq_numbers;
  for (const auto& i : arr) {
    if (uniq_numbers[i]++ < n) {
      resut.push_back(i);
    }
  }
  return resut;
}

/* typec */
std::vector<int> deleteNth3(std::vector<int> const& arr, int n) {
  std::unordered_map<int, int> counts;
  std::vector<int> result;
  std::copy_if(arr.begin(), arr.end(), std::back_inserter(result), [&](auto val) mutable {
    return ++counts[val] <= n;
  });
  return result;
}

#ifdef false
int main()
{
  auto result = deleteNth({20,37,20,21}, 1);
  for (auto i : result) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;

  auto result2 = deleteNth2({20,37,20,21}, 1);
  for (auto i : result2) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;

  auto result3 = deleteNth3({20,37,20,21}, 1);
  for (auto i : result3) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;
}
#endif
