// https://www.codewars.com/kata/5813084c6858b6ba7b00006a/train/cpp
// Fun with operators

#include <iostream>

/*
#include <tuple>
using Person = std::tuple<int>;
*/

class Person
{
public:
  Person(int age) : m_age(age) {}

  bool operator==(const Person& other) const
  {
    return m_age == other.m_age;
  }

  bool operator!=(const Person& other) const
  {
    return m_age != other.m_age;
  }

  bool operator<=(const Person& other) const
  {
    return m_age <= other.m_age;
  }

  bool operator>=(const Person& other) const
  {
    return m_age >= other.m_age;
  }

  bool operator<(const Person& other) const
  {
    return m_age < other.m_age;
  }

  bool operator>(const Person& other) const
  {
    return m_age > other.m_age;
  }

private:
  const int m_age;
};

#if false
int main(int argc, char *argv[])
{
  Person p1(17);
  Person p2(17);
  std::cout << (p1 == p2) << std::endl;
  return 0;
}
#endif
