

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")

message("building repofileops~~~~~~~~~~~~~~~~~~")

IF (WIN32)
    MESSAGE(STATUS "Now is windows")
    add_library(repofileops repofile-list.c ./windows/repofile-ops.c)
ELSEIF (APPLE)
    MESSAGE(STATUS "Now is Apple systems.")
    add_library(repofileops repofile-list.c ./unix/repofile-ops.c)
ELSEIF (UNIX)
    MESSAGE(STATUS "Now is UNIX-like OS's.")
    add_library(repofileops repofile-list.c ./linux/repofile-ops.c)
ENDIF ()






