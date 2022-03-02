/**
 * Created by huyoufu on 2021/4/9 23:40.
 * contact me -->https://www.jk1123.com
 */


#include <gtest/gtest.h>
extern "C"{
    #include "repoindex-ops.h"
}
TEST(repo_index_test,init_index){
    init_index();

    //printf("测试啊");
}
TEST(repo_index_test, save_repo){
    init_index();
    save_repo(NULL);
    //printf("测试啊");
}

TEST(repo_index_test, save_repo_list){
    init_index();
    save_repo_list(NULL);

    //printf("测试啊");
}