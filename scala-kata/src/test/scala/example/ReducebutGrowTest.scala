// You can test using ScalaTest (http://www.scalatest.org/).
import org.scalatest._
import kata.ReduceButGrow

class ReducebutGrowTest extends FlatSpec with Matchers {
  "ReducebutGrow " should "pass" in {
    assert(ReduceButGrow.grow(List(1, 2, 3)) === 6)
    assert(ReduceButGrow.grow(List(4, 1, 1, 1, 4)) === 16)
    assert(ReduceButGrow.grow(List(2, 2, 2, 2, 2, 2)) === 64)
  }
}