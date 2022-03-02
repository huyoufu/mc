/**
 * Created by huyoufu on 2021/4/9 23:40.
 * contact me -->https://www.jk1123.com
 */


#include <gtest/gtest.h>
extern "C"{
    #include "dict.h"
    #include "stdlib.h"
}
TEST(dict_test, dictCreat){

    dictType commandTableDictType = {
            NULL,            /* hash function */
            NULL,                       /* key dup */
            NULL,                       /* val dup */
            NULL,      /* key compare */
            NULL,          /* key destructor */
            NULL,                       /* val destructor */
            NULL                        /* allow to expand */
    };
    dict *d=dictCreate(&commandTableDictType,NULL);
    printf("测试啊%p\n",d);
}


