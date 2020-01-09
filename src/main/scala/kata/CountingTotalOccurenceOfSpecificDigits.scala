package kata

object NbrList {
  def countSpecDigits(intsList: List[Int], digitsList: List[Int]): List[(Int, Int)] = {
    digitsList.zip(digitsList.map(
      digit => {
        val d = digit.toString.last
        if (intsList.isEmpty) 0 else
          intsList.flatMap(_.toString).count(_ == d)
      })
    )
  }
}
