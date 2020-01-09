package kata

object Pile {
  private def toBin(n: Int, len: Int): List[Int] = {
    if (len == 0) Nil else
      (n % 2) :: toBin(n / 2, len - 1)
  }

  def minDiff(a: List[Int]): Int = {
    (1 until Math.pow(2, a.size).toInt - 1).map(
      toBin(_, a.size)
    ).map(_.zip(a)).map(item => {
      val first = item.filter(_._1 == 0).unzip._2.sum
      val second = item.filter(_._1 == 1).unzip._2.sum
      Math.abs(first - second)
    }).min
  }
}
