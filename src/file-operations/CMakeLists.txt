IF (WIN32)
    MESSAGE(STATUS "building repofileops on windows")
    add_library(repofileops repofile-list.c ./windows/repofile-ops.c)
ELSEIF (APPLE)
    MESSAGE(STATUS "building repofileops on Apple systems.")
    add_library(repofileops repofile-list.c ./unix/repofile-ops.c)
ELSEIF (UNIX)
    MESSAGE(STATUS "building repofileops on UNIX-like OS's.")
    add_library(repofileops repofile-list.c ./linux/repofile-ops.c)
ENDIF ()






