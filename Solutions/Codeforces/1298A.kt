fun main() {
  val x = readLine()!!.split(' ').map(String::toInt).sorted()
  for (i in 0..2) print("${x[3] - x[i]} ")
}
