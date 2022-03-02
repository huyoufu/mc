/**
 * Created by huyoufu on 2021/4/9 23:38.
 * contact me -->https://www.jk1123.com
 */


#ifndef MC_REPOINDEX_OPS_H
#define MC_REPOINDEX_OPS_H
#include "repoindex.h"
extern int init_index();
extern int save_repo(RepoFileInfo *repoFileInfo);
extern int save_repo_list(RepoFileInfoList *repoFileInfoList);
#endif //MC_REPOINDEX_OPS_H
