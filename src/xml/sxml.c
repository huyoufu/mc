//
// Created by Administrator on 2021/4/8.
//

#include "sxml.h"
void sxml_init(sxml_document_t *sd){
    FILE *file=fopen("D:\\software\\maven-3.2.1\\conf\\settings.xml","r");
    if (file==NULL){
        perror("���ļ�xml�����ļ�ʧ��!");
    }
    char buff[1024];

    // ��ȡ�ı���ֱ�������µ�һ�п�ʼ
    fscanf(file,"%[^\n]", buff);

    printf("��ȡ����:\n%s", buff);

    //�ر��ļ�
    fclose(file);
}
char * get_ele_attr_val(const char * ele_name,const char *attr_key){
    return NULL;
}