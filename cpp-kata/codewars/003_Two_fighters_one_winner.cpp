// https://www.codewars.com/kata/577bd8d4ae2807c64b00045b/train/cpp
// Two fighters, one winner.

#include <string>
#include <iostream>

class Fighter
{
private:
  std::string name;
  int health;
  int damagePerAttack;

public:
  Fighter(std::string name, int health, int damagePerAttack) {
    this->name = name;
    this->health = health;
    this->damagePerAttack = damagePerAttack;
  }

  ~Fighter() { };
  std::string getName()                  { return name;            }
  int         getHealth()                { return health;          }
  int         getDamagePerAttack()       { return damagePerAttack; }
  void        setHealth(int value)       { health = value;         }
};

/* Clever solution
std::string declareWinner(Fighter* fighter1, Fighter* fighter2, std::string firstAttacker)
{
 // Number of blows each fighter can survive:
 int n1 = (fighter1->getHealth() - 1) / fighter2->getDamagePerAttack();
 int n2 = (fighter2->getHealth() - 1) / fighter1->getDamagePerAttack();

return n1 > n2 ? fighter1->getName()
               : n1 < n2 ? fighter2->getName()
                         :           firstAttacker;
}
*/


std::string declareWinner(Fighter* fighter1, Fighter* fighter2, const std::string& firstAttacker)
{
  auto attack = [](Fighter& fighter, Fighter& enemy) {
    const auto enemyHealth = enemy.getHealth();
    enemy.setHealth(enemyHealth - fighter.getDamagePerAttack());
  };

  auto fight = [&](Fighter& f1, Fighter& f2) {
    while (true) {
      attack(f1, f2);
      if (f2.getHealth() <= 0) {
        return f1.getName();
      }
      attack(f2, f1);
      if (f1.getHealth() <= 0) {
        return f2.getName();
      }
    }
  };

  return (fighter1->getName() == firstAttacker)
           ? fight(*fighter1, *fighter2)
           : fight(*fighter2, *fighter1);
}


int main()
{
  Fighter fighter1("Lew", 10, 2);
  Fighter fighter2("Harry", 5, 4);

  std::string expected = "Harry";
  std::string actual = declareWinner(&fighter1, &fighter2, "Harry");
  std::cout << "expected: " << expected << ", actual: " << actual << std::endl;

}
