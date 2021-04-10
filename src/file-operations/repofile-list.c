/**
 * Created by huyoufu on 2021/4/10 0:07.
 * contact me -->https://www.jk1123.com
 */
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "repofile.h"
#include "repofile-ops.h"
RepoFileInfoList* rfil_init(int size){
    RepoFileInfoList* list=malloc(sizeof(RepoFileInfoList)+sizeof(RepoFileInfo*)*size);
    list->size=size;
    list->pos=0;
    return list;
}
void rfil_add(RepoFileInfoList* repoFileInfoList,RepoFileInfo* repoFileInfo){
    int i=repoFileInfoList->pos;
    //&repoFileInfoList->arr[i] 获取当前位置的内存地址
    //&repoFileInfo 拷贝的是repoFileInfo内存地址
    memcpy(&repoFileInfoList->arr[i],&repoFileInfo, sizeof(RepoFileInfo*));
    repoFileInfoList->pos++;
}
RepoFileInfo* rfil_get(RepoFileInfoList* repoFileInfoList,int index){
    if (index>repoFileInfoList->pos){

        //_set_errno(ERANGE);
        exit(1);
    }else{

        //RepoFileInfo *ptr=repoFileInfoList+sizeof(int)*2+index*sizeof(RepoFileInfo*);
        RepoFileInfo *ptr=repoFileInfoList->arr[index];
        return ptr;

    }


}
//销毁仓库文件列表
void rfil_destroy(RepoFileInfoList* repoFileInfoList){

}
void rfil_handle(RepoFileInfoList* repoFileInfoList,void (*handle)(RepoFileInfo* repoFileInfo)){

    assert(repoFileInfoList!=NULL);
    for (int i = 0; i < repoFileInfoList->size; ++i) {
        RepoFileInfo* rfi=repoFileInfoList->arr[i];
        handle(rfi);
    }
}