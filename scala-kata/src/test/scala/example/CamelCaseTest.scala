// You can test using ScalaTest (http://www.scalatest.org/).
import org.scalatest._
import kata.CamelCase

class SolutionTest extends FlatSpec with Matchers {
  "the_Stealth_Warrior underscore lower start" should "theStealthWarrior" in {
    assert(CamelCase.toCamelCase("the_Stealth_Warrior") === "theStealthWarrior")
  }

  "the-Stealth-Warrior test dash " should "theStealthWarrior" in {
    assert(CamelCase.toCamelCase("the-Stealth-Warrior") === "theStealthWarrior")
  }
}