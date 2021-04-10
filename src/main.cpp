#include <stdlib.h>
extern "C"{
    //这里放C的头文件
    #include "repofile.h"
    #include "repofile-ops.h"
}


char *getMavenHome() {
    char *m2_home = getenv("M2_HOME");
    char *maven_home = getenv("MAVEN_HOME");
    char *home = maven_home == NULL ? m2_home : maven_home;

    return home;
}

int main(int argc, char ** argv) {

}


