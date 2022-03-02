IF (WIN32)
    MESSAGE(STATUS "building collection on windows")
    add_library(collection dict.c mt19937-64.c siphash.c)
ELSEIF (APPLE)
    MESSAGE(STATUS "building collection on Apple systems.")
    add_library(collection dict.c mt19937-64.c siphash.c)
ELSEIF (UNIX)
    MESSAGE(STATUS "building collection on UNIX-like OS's.")
    add_library(collection dict.c mt19937-64.c siphash.c)
ENDIF ()






