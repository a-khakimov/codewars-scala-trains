import org.http4s._
import org.http4s.implicits._
import zio._
import zio.interop.catz.taskConcurrentInstance
import zio.test.Assertion._
import zio.test.TestAspect.sequential
import zio.test._

object TestHelloService extends DefaultRunnableSpec {
  override def spec: Spec[_root_.zio.test.environment.TestEnvironment, TestFailure[Throwable], TestSuccess]
    = suite("routes suite") {
    testM("[testM] root request returns Ok") {
      for {
        response <- HelloService.service.run(Request[Task](Method.GET, uri"/"))
      } yield assert(response.status)(equalTo(Status.Ok))
    }
    testM("[assertM] root request returns Ok") {
      assertM(HelloService.service.run(Request[Task](Method.GET, uri"/")).map(_.status))(
        equalTo(Status.Ok)
      )
    }
    testM("[assertM] root request returns Ok") {
      assertM(HelloService.service.run(Request[Task](Method.GET, uri"/a")).map(_.status))(
        equalTo(Status.NotFound)
      )
    }
    testM("root request body returns 'hello'") {
      val io = for {
        response <- HelloService.service.run(Request[Task](Method.GET, uri"/"))
        body <- response.body.compile.toVector.map(x => x.map(_.toChar).mkString)
      } yield body
      assertM(io)(equalTo("Hello!"))
    }
  } @@ sequential
}
