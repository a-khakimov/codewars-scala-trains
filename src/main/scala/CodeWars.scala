import kata.NbrList

object CodeWars extends App {
  var intsList = List(11, 1, 2, 3, 1, 2, 3, 4)
  println("> " + intsList.mkString)

  var digitsList = List(1, 3)
  println(NbrList.countSpecDigits(intsList, digitsList))

  intsList = List(-18, -31, 81, -19, 111, -888)
  digitsList = List(1, 8, 4)
  println(NbrList.countSpecDigits(intsList, digitsList))

  intsList = List()
  digitsList = List(1, 8, 4)
  println(NbrList.countSpecDigits(intsList, digitsList))
}
