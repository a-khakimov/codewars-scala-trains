import kata.Pile

import scala.annotation.tailrec


object CodeWars extends App {
  println(Pile.minDiff(List(0, 1, 2, 8, 9, 3)))
}


object Multiplication extends App {

  def persistence(n: Int): Int = {
    @tailrec def go(d: Int, count: Int): Int = {
      val k = d.toString.map(_.asDigit)
      k.size match {
        case 1 => count
        case _ => go(k.product, count + 1)
      }
    }
    go(n, 0)
  }

  println(persistence(4)) // 0
  println(persistence(25)) // 2
  println(persistence(39)) // 3
  println(persistence(999)) // 4
}

object RangeExtraction extends App {

  def solution(xs: List[Int]): String = {

    val offsets = 0 +: xs.zip(xs.tail).map(n => n._2 - n._1)
    val pods = xs.zip(offsets).foldLeft(List[(Int, Int)]()) {
      case (Nil, elem) => List(elem)
      case (acc, elem) => acc.lastOption match {
        case Some(v) if v._2 == 1 && elem._2 != 1 => {
          val last = acc.last
          acc.dropRight(1) :+ (last._1, last._2 + 1) :+ elem
        }
        case _ => acc :+ elem
      }
    }

    val last = pods.last

    (pods.dropRight(1) :+ (last._1, last._2 + 1)).map(n => {
      n._2 match {
        case 1 => "*"
        case _ => s"${n._1},"
      }
    }).mkString
      .dropRight(1)
      .replace(",*", "-")
      .filter(_ != '*')
  }

  println(solution(List(-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20)))
  println(solution(List(4)))
  println(solution(List()))
}