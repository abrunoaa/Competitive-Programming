fun main() {
  readLine()!!
  val ans = readLine()!!.split(' ').map(String::toInt).reversed().distinct().reversed()
  print("${ans.size}\n${ans.joinToString(" ")}\n")
}
