
add_rules("mode.debug")
add_rules("mode.release")

set_targetdir("lib")
set_objectdir("bin-int")

set_rundir(".")

set_warnings("all", "error")

add_links("kernel32", "user32", "gdi32", "opengl32")

add_includedirs("include")

add_requires("glad")

target("pixy")
    set_kind("static")
    add_files("src/**.c")

target("test")
    set_kind("binary")
    add_files("test.c")

    set_targetdir("bin")

    add_deps("pixy")

    add_packages("glad")
