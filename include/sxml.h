//
// Created by Administrator on 2021/4/8.
//

#ifndef MC_SXML_H
#define MC_SXML_H

#include <stdlib.h>
#include <stdio.h>

typedef struct sxml_document_{
    char * file;
} sxml_document_t;


void sxml_init(sxml_document_t *sd);





char * get_ele_attr_val(const char * ele_name,const char *attr_key);

#endif //MC_SXML_H
