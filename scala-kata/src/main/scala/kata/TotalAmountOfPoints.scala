package kata

object TotalAmountOfPoints {
  def points(games: Vector[String]): Int = {
    games.map(i => {
      val s = i.split(':')
      if (s.head.toInt > s.last.toInt) 3
      else if (s.head.toInt < s.last.toInt) 0
      else 1
    }).sum
  }
}

