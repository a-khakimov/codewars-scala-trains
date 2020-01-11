import kata.NbrList


object Pile {
  def toBin(n: Int, len: Int): IndexedSeq[Int] = {
    (0 until len).map(b => {
      ((n >> b) & 0x01)
    })
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

object CodeWars extends App {
  println((2 >> 1) & 1)
  println(Pile.toBin(0, 4))
  println(Pile.toBin(1, 4))
  println(Pile.toBin(2, 4))
  println(Pile.toBin(3, 4))
  println(Pile.toBin(4, 4))
  println(Pile.minDiff(List(0, 1, 2, 8, 9, 3)))
}
