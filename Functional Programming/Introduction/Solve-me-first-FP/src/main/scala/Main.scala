/**
 * Created by zhangyang on 14/10/31.
 */
object Main {
  def main(args: Array[String]) {
    println(io.Source.stdin.getLines().take(2).map(_.toInt).sum)
  }
}
