/**
 * Created by huyoufu on 2021/4/9 23:06.
 * contact me -->https://www.jk1123.com
 */


#ifndef MC_REPOFILE_OPS_H
#define MC_REPOFILE_OPS_H
#include "repofile.h"
//初始化 仓库文件列表 给定长度
RepoFileInfoList* rfil_init(int size);
void rfil_add(RepoFileInfoList* repoFileInfoList,RepoFileInfo* repoFileInfo);
RepoFileInfo* rfil_get(RepoFileInfoList* repoFileInfoList,int index);
//销毁仓库文件列表
void rfil_destroy(RepoFileInfoList* repoFileInfoList);

void rfil_collect(char* repo_dir,RepoFileInfoList* repoFileInfoList);

void rfil_handle(RepoFileInfoList* repoFileInfoList,void (*handle)(RepoFileInfo* repoFileInfo));

#endif //MC_REPOFILE_OPS_H
