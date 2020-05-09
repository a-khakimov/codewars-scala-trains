/* https://www.codewars.com/kata/59eb1e4a0863c7ff7e000008
 * The boolean order
 *
 * NOT RESOLVED
 *
 * https://www.geeksforgeeks.org/dyck-path/
 * https://ru.wikipedia.org/wiki/%D0%AF%D0%B7%D1%8B%D0%BA_%D0%94%D0%B8%D0%BA%D0%B0
 * https://ru.wikipedia.org/wiki/%D0%A7%D0%B8%D1%81%D0%BB%D0%B0_%D0%9A%D0%B0%D1%82%D0%B0%D0%BB%D0%B0%D0%BD%D0%B0
 * https://ru.wikipedia.org/wiki/%D0%93%D1%80%D0%B0%D1%84_%D0%94%D0%B8%D0%BA%D0%B0
 * https://sahandsaba.com/interview-question-generating-all-balanced-parentheses.html
 * https://en.wikipedia.org/wiki/Dyck_language
 */

#include <iostream>
#include <vector>

/*************************
  ((⊛ ⊛) ⊛)
 ____________
| ⊛ → ⊙ → ⊙ |
|     ↑   ↑ |
|     ⊛   ⊙ |
|         ↑ |
|         ⊛ |
|___________|

  (⊛ (⊛ ⊛))
 ____________
| ⊛ → ⊙ → ⊙ |
|         ↑ |
|     ⊛ → ⊙ |
|         ↑ |
|         ⊛ |
|___________|

************************
  (((⊛ ⊛) ⊛) ⊛)
 _______________
| ⊛ → ⊙ → ⊙ → ⊙ |
|     ↑   ↑   ↑ |
|     ⊛   ⊙   ⊙ |
|         ↑   ↑ |
|         ⊛   ⊙ |
|             ↑ |
|             ⊛ |
|_______________|

  (⊛ (⊛ (⊛ ⊛)))
 _______________
| ⊛ → ⊙ → ⊙ → ⊙ |
|             ↑ |
|     ⊛ → ⊙   ⊙ |
|             ↑ |
|         ⊛ → ⊙ |
|             ↑ |
|             ⊛ |
|_______________|

  (⊛ ⊛) (⊛ ⊛)
 _______________
| ⊛ → ⊙ → ⊙ → ⊙ |
|     ↑       ↑ |
|     ⊛       ⊙ |
|             ↑ |
|         ⊛ → ⊙ |
|             ↑ |
|             ⊛ |
|_______________|

  (⊛ ((⊛ ⊛) ⊛))
 _______________
| ⊛ → ⊙ → ⊙ → ⊙ |
|             ↑ |
|     ⊛ → ⊙ → ⊙ |
|         ↑   ↑ |
|         ⊛   ⊙ |
|             ↑ |
|             ⊛ |
|_______________|

  ((⊛ (⊛ ⊛)) ⊛)
 _______________
| ⊛ → ⊙ → ⊙ → ⊙ |
|         ↑   ↑ |
|     ⊛ → ⊙   ⊙ |
|         ↑   ↑ |
|         ⊛   ⊙ |
|             ↑ |
|             ⊛ |
|_______________|

*************************/


// Returns count of all possible parenthesizations that lead to
// result true for a boolean expression with symbols like true
// and false and operators like &, | and ^ filled between symbols
int countParenth(char symb[], char oper[], const int n)
{
  std::vector<std::vector<int>> F, T;
  F.resize(n);
  T.resize(n);

  for (auto& f : F) f.resize(n);
  for (auto& t : T) t.resize(n);

  // Fill diaginal entries first
  // All diagonal entries in T[i][i] are 1 if symbol[i]
  // is T (true).  Similarly, all F[i][i] entries are 1 if
  // symbol[i] is F (False)
  for (int i = 0; i < n; i++)
  {
    F[i][i] = (symb[i] == 'F')? 1: 0;
    T[i][i] = (symb[i] == 'T')? 1: 0;
  }

  auto print = [&]() {
    for (int ii = 0; ii < n; ++ii) {
      for (const int& jj : T[ii]) { std::cout << jj << " "; }
      std::cout << " - ";
      for (const int& jj : F[ii]) { std::cout << jj << " "; }
      std::cout << std::endl;
    }
  };

  print();

  // Now fill T[i][i+1], T[i][i+2], T[i][i+3]... in order
  // And F[i][i+1], F[i][i+2], F[i][i+3]... in order
  for (int gap=1; gap<n; ++gap)
  {
    for (int i = 0, j = gap; j < n; ++i, ++j)
    {
      T[i][j] = F[i][j] = 0;
      for (int g = 0; g < gap; g++)
      {
        // Find place of parenthesization using current value
        // of gap
        int k = i + g;

        // Store Total[i][k] and Total[k+1][j]
        int tik = T[i][k] + F[i][k];
        int tkj = T[k+1][j] + F[k+1][j];

        std::cout << "gap=" << gap
                  << ", i=" << i
                  << ", k=" << k
                  << ", j=" << j
                  << ", g=" << g
                  << ", oper[k]=" << oper[k]
                  << std::endl;

        // Follow the recursive formulas according to the current
        // operator
        if (oper[k] == '&') {
          T[i][j] += T[i][k] * T[k+1][j];
          F[i][j] += tik * tkj - T[i][k] * T[k+1][j];
        }
        if (oper[k] == '|') {
          F[i][j] += F[i][k] * F[k+1][j];
          T[i][j] += tik * tkj - F[i][k] * F[k+1][j];
        }
        if (oper[k] == '^') {
          T[i][j] += F[i][k] * T[k+1][j] + T[i][k] * F[k+1][j];
          F[i][j] += T[i][k] * T[k+1][j] + F[i][k] * F[k+1][j];
        }
        std::cout << "T[i][j]=" << T[i][j]
                  << ", F[i][j]=" << F[i][j]
                  << std::endl;
        print();
      }
    }
  }
  std::cout << "sum = " <<  T[0][n-1] + F[0][n-1] << std::endl;
  return T[0][n-1];
}

#include <string.h>

/*
 *
void _printParenthesis(int pos, int n, int open, int close);

// Wrapper over _printParenthesis()
void printParenthesis(int n)
{
  if(n > 0)
    _printParenthesis(0, n, 0, 0);
  return;
}

void _printParenthesis(int pos, int n, int open, int close)
{
  static char str[100];

  if (close == n) {
    printf("%s \n", str);
    return;
  } else {
    if(open > close) {
      str[pos] = ')';
      _printParenthesis(pos+1, n, open, close + 1);
    }

    if(open < n) {
      str[pos] = '(';
      _printParenthesis(pos+1, n, open+1, close);
    }
  }
}
*/

#if false
int main(int argc, char *argv[])
{
  char symbols[] = "TTTTTTTTT";
  char operators[] = "||||||||";
  int n = strlen(symbols);

  std::cout << countParenth(symbols, operators, n) << std::endl;
  return 0;
}
#endif

