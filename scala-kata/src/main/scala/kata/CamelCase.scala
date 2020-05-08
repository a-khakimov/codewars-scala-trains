/* https://www.codewars.com/kata/517abf86da9663f1d2000003/train/scala
 */

package kata

object CamelCase {
  def toCamelCase(str: String): String = {
    str.scanLeft(' ')((a, b) => {
      if(a == '-' || a == '_') b.toUpper else b
    }).drop(1).toString().filterNot((a) => a == '-' || a == '_')
  }
}
