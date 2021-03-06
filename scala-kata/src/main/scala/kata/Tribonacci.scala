/* https://www.codewars.com/kata/556deca17c58da83c00002db
 */

package kata

object Tribonacci {
  def tribonacci[T : Numeric](signature: List[T], n: Int): List[T] = {
    if (n <= 3)
      signature.take(n)
    else if (n > signature.size) {
      tribonacci(signature ++ List(signature.takeRight(3).sum), n)
    } else {
      signature
    }
  }
}
