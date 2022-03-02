IF (WIN32)
    MESSAGE(STATUS "building repofileops on windows")
    add_library(repoindex repoindex-ops.c)
ELSEIF (APPLE)
    MESSAGE(STATUS "building repofileops on Apple systems.")
    add_library(repoindex repoindex-ops.c)
ELSEIF (UNIX)
    MESSAGE(STATUS "building repofileops on UNIX-like OS's.")
    add_library(repoindex repoindex-ops.c)
ENDIF ()






