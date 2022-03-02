//
// Created by 户有福 on 2022/3/3.
//
#include <stdio.h>
void _mcAssert(const char *estr, const char *file, int line){
    printf("%s---%s---%d\n",estr,file,line);
}
