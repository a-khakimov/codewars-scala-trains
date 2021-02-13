name := "experiments"

version := "0.1"

scalaVersion := "2.13.4"

val http4sVersion = "0.21.3"

// Only necessary for SNAPSHOT releases
resolvers += Resolver.sonatypeRepo("snapshots")

libraryDependencies ++= Seq(
  "org.http4s" %% "http4s-dsl" % http4sVersion,
  "org.http4s" %% "http4s-blaze-server" % http4sVersion,
  "org.http4s" %% "http4s-blaze-client" % http4sVersion,
  "dev.zio" %% "zio" % "1.0.1",
  "dev.zio" %% "zio-interop-cats" % "2.2.0.1",
  "dev.zio" %% "zio-test"          % "1.0.1" % "test",
  "dev.zio" %% "zio-test-sbt"      % "1.0.1" % "test",
)

