import Dependencies._

lazy val root = (project in file("."))
  .settings(
    name := "CodeWars",
    libraryDependencies += scalaTest % Test
  )

libraryDependencies += "com.novocode" % "junit-interface" % "0.11" % "test"
