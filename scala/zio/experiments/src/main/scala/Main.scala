import org.http4s.HttpRoutes
import org.http4s.dsl.Http4sDsl
import org.http4s.server.blaze._
import org.http4s.implicits._
import zio.{Task, ZIO}
import zio.interop.catz._
import zio.interop.catz.implicits._

object HelloService {
  private val dsl = Http4sDsl[Task]
  import dsl._

  val service = HttpRoutes.of[Task] {
    case GET -> Root => Ok("Hello!")
  }.orNotFound
}

object Main extends zio.App {

  val server = ZIO.runtime[zio.ZEnv]
    .flatMap {
      implicit rts => BlazeServerBuilder[Task]
        .bindHttp(8080, "localhost")
        .withHttpApp(HelloService.service)
        .serve
        .compile
        .drain
    }

  def run(args: List[String]) =
    server.fold(_ => zio.ExitCode.failure, _ => zio.ExitCode.success)
}

