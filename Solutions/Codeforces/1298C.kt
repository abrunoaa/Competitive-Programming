fun main() {
  readLine()
  println(readLine()!!.windowed(3).count { it == "xxx" })
}
