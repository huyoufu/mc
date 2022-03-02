/**
 * Created by huyoufu on 2021/4/10 3:00.
 * contact me -->https://www.jk1123.com
 */

#include <stdlib.h>
#include <stdio.h>

#include "gtest/gtest.h"
extern "C"{
#include "repofile.h"
#include "repofile-ops.h"
}



int add1(){
    RepoFileInfoList* list=rfil_init(10);
    for (int i = 0; i < 10; ++i) {
        RepoFileInfo *rfi=(RepoFileInfo *)malloc(sizeof(RepoFileInfo));
        char is[2];
        //itoa(i,is,10);
        sprintf(is,"%d",i);
        char* name=(char *)malloc(sizeof(char)*2+sizeof(char)*15);
        sprintf(name, "%s%s", "文件编号是", is);
        rfi->name=name;
        rfi->repoFileType=XML;
        rfi->create_time=i;
        rfi->last_modify_time=i;
        rfil_add(list,rfi);
    }

    for (int i = 0; i < 10; ++i) {
        RepoFileInfo *rfi=rfil_get(list,i);
        char* name=rfi->name;
        printf("第%d号文件的名字是 %s\n",i,name);
    }
    return 1;

}

TEST(repofile_list_test,add1){

    //int i=add1()
    ASSERT_EQ(1, add1()+2);
}
