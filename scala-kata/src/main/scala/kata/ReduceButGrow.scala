/* https://www.codewars.com/kata/beginner-reduce-but-grow/train/scala
 */

package kata

object ReduceButGrow {
    def grow(xs: List[Long]): Long = {
      xs.reduceLeft((a, b) => a * b)
    }
}
