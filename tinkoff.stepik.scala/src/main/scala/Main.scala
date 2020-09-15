import scala.annotation.tailrec
import scala.io.StdIn._

object Main {
  //----------------------------------------------------//
  def isSnakeCase(string: String) : Boolean = {
    !string.contains(" ") &&
      !string.contains("__") &&
      !string.matches(".*()[A-Z0-9].*") &&
      !string.matches("^_.*") &&
      !string.matches(".*_$")
  }

  //----------------------------------------------------//
  def fibs1(num: Int) : Long = {
    @tailrec def go(prev : Int, cur : Int, pos: Int, acc: Long) : Long = {
      if (pos > num) acc
      else go(cur, prev + cur, pos + 1, acc + cur)
    }

    if (num == 1) 1
    else if (num == 2) 1
    else go(0, 1, 3, 1)
  }

  //----------------------------------------------------//
  @tailrec def fibs(num: BigInt, cur: BigInt = 1, f1: BigInt = 0, f2: BigInt = 1) : BigInt = {
    if (num == cur) f2
    else fibs(num, cur + 1, f2, f1 + f2)
  }

  //----------------------------------------------------//
  def sendGift(currentAmount: Int, gift: => Int) = {
    if (currentAmount >= 500)
      currentAmount + gift
    else
      currentAmount
  }

  val getGift = () => {
    println("The gift is received")
    100//readLine.toInt
  }

  val accountAmounts = List(100, 200, 500, 300, 700)

  //----------------------------------------------------//
  val mul3 = 3*(_: Double)
  val pow2 = (x: Double) => x*x
  val result = (pow2.andThen[Double] _)(mul3)(5)

  //----------------------------------------------------//
  object LessonData{
    def searchInArray(cond: Int => Boolean, array: List[Int]): List[Int] = {
      array.filter(cond)
    }
  }
  val searchOdd: List[Int] => List[Int] = array => LessonData.searchInArray(_ % 2 != 0, array)

  //----------------------------------------------------//
  def middle[A](data: Iterable[A]) : A = {
    data.splitAt(data.size / 2)._2.head
  }

  def main(args: Array[String]) : Unit = {
    println(middle("Scala"))
    println(middle(Seq(1, 7, 5, 9)))
  }
}
