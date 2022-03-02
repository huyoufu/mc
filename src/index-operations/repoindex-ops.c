/**
 * Created by huyoufu on 2021/4/9 23:40.
 * contact me -->https://www.jk1123.com
 */

#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>
#include "repoindex-ops.h"


sqlite3 *db;

static int callback_insert(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
char * get_db_path(){

    //先获取家目录

    char *home=getenv("HOME");
    int len_path= strlen(home)+strlen(DB_NAME)+1;
    char * path= malloc(sizeof(char)*len_path);
    memset(path, 0, len_path);
    strcat(path,home);
    strcat(path,"/");
    strcat(path,DB_NAME);;
    return path;
}


int save_repo(RepoFileInfo *repoFileInfo){

    char * sql="insert into mc_index values(NULL,:name,:file_type,:created,:modify)";
    sqlite3_stmt *stmt;
    int result=sqlite3_prepare_v2(db,sql, strlen(sql),&stmt,NULL);
    if (result){
        fprintf(stderr, "prepare failed: %s\n", sqlite3_errmsg(db));
        exit(0);
    }else{
        //printf("prepare successfully!!!\n");
    }
    //绑定参数
    //printf("max_parameter_count = %d\n", sqlite3_bind_parameter_count(stmt));
    /* 只有上面指定了:name这个名字才可以用 */
    //printf("name parameter index = %d\n", sqlite3_bind_parameter_index(stmt, ":name"));
    //printf("file_type parameter index = %d\n", sqlite3_bind_parameter_index(stmt, ":file_type"));
    //printf("created parameter index = %d\n", sqlite3_bind_parameter_index(stmt, ":created"));
    //printf("modify parameter index = %d\n", sqlite3_bind_parameter_index(stmt, ":modify"));

    sqlite3_bind_text(stmt,1,"测试数据", -1,NULL);
    sqlite3_bind_int(stmt,2,1);
    sqlite3_bind_text(stmt,3,"2020-12-13 10:22:10", -1,NULL);
    //如果是字符串参数 最后一个参数你给你一个传递一个函数的机会 用来释放字符串用的 一般我们不用
    sqlite3_bind_text(stmt,4,"2020-12-13 14:22:10", -1,NULL);
    result=sqlite3_step(stmt);
    if (result!=SQLITE_DONE){
        fprintf(stderr, "insert failed: %s\n", sqlite3_errmsg(db));
        exit(0);
    }else{
        //printf("insert successfully!!!\n");
    }
    return EXIT_SUCCESS;
}
int save_repo_list(RepoFileInfoList *repoFileInfoList) {
    //批量保存
    char * sql="insert into mc_index values(NULL,:name,:file_type,:created,:modify)";
    sqlite3_stmt *stmt;
    int result=sqlite3_prepare_v2(db,sql, strlen(sql),&stmt,NULL);
    if (result){
        fprintf(stderr, "prepare failed: %s\n", sqlite3_errmsg(db));
        exit(0);
    }else{
        //printf("prepare successfully!!!\n");
    }
    sqlite3_exec(db,"begin;",0,0,0);
    for (int i = 0; i <1000000; ++i) {
        sqlite3_reset(stmt);
        //绑定参数
        sqlite3_bind_text(stmt,1,"测试数据", -1,NULL);
        sqlite3_bind_int(stmt,2,1);
        //
        sqlite3_bind_text(stmt,3,"2020-12-13 10:22:10", -1,NULL);
        sqlite3_bind_text(stmt,4,"2020-12-13 14:22:10", -1,NULL);
        sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    sqlite3_exec(db,"commit;",0,0,0);
    return EXIT_SUCCESS;
}

//初始化仓库
int init_index(){
    mcAssert(0);
    char* errmsg;
    char *db_path=get_db_path();
    int rc=sqlite3_open(db_path,&db);
    if (rc){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    }else{
        printf("open sqlite3 db mc.db successfully!!!\n");
    }
    free(db_path);
    //如果打开成功了 检查是否存在某个数据库

    char * sql="CREATE TABLE IF NOT EXISTS \"mc_index\"\n"
               "(\n"
               "    \"id\"   INTEGER PRIMARY KEY AUTOINCREMENT,\n"
               "    \"name\" VARCHAR(255) NULL ,\n"
               "    \"file_type\" INTEGER NULL ,\n"
               "    \"created\"  TIMESTAMP default (datetime('now', 'localtime')),\n"
               "    \"modify\"  TIMESTAMP default (datetime('now', 'localtime'))\n"
               ");";

    int result=sqlite3_exec(db,sql,NULL,0,&errmsg);
    if (result){
        fprintf(stderr, "create table failed: %s\n", sqlite3_errmsg(db));
        exit(0);
    }else{
        printf("create table successfully");
    }
    return EXIT_SUCCESS;
}


