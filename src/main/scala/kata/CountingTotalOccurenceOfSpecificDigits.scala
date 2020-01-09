/* https://www.codewars.com/kata/56311e4fdd811616810000ce/
 */

package kata

object NbrList {
  def countSpecDigits(intsList: List[Int], digitsList: List[Int]): List[(Int, Int)] = {
    digitsList.map(digit => {
      val d = digit.toString.last
      (digit, intsList.mkString.count(_ == d))
    })
  }
}
