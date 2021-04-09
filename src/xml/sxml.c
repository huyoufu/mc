//
// Created by Administrator on 2021/4/8.
//

#include "sxml.h"
void sxml_init(sxml_document_t *sd){
    FILE *file=fopen("D:\\software\\maven-3.2.1\\conf\\settings.xml","r");
    if (file==NULL){
        perror("打开文件xml配置文件失败!");
    }
    char buff[1024];

    // 读取文本，直到碰到新的一行开始
    fscanf(file,"%[^\n]", buff);

    printf("读取内容:\n%s", buff);

    //关闭文件
    fclose(file);
}
char * get_ele_attr_val(const char * ele_name,const char *attr_key){
    return NULL;
}