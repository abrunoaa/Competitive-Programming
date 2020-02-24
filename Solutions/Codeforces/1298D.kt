import java.lang.Integer.min
import java.lang.Integer.max

fun main() {
  var sum = 0
  var mx = 0
  var mi = 2e9.toInt()
  val (n, w) = readLine()!!.split(' ').map(String::toInt)
  readLine()!!.split(' ').map(String::toInt).forEach{ x ->
    sum += x
    mi = min(mi, sum)
    mx = max(mx, sum)
  }
  if (mi < 0) {
    mx += -mi
  }
  print(max(0, w - mx + 1))
}
