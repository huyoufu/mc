/**
 * Created by huyoufu on 2021/4/9 22:07.
 * contact me -->https://www.jk1123.com
 */


#ifndef MC_REPOFILE_H
#define MC_REPOFILE_H

enum RepoFileType{
    ZIP,
    XML,
};
typedef struct RepoFileInfo_{
    long last_modify_time;
    long create_time;
    char *name;
    enum RepoFileType repoFileType;
} RepoFileInfo;
typedef struct RepoFileInfoList_{
    int pos;
    int size;
    RepoFileInfo* arr[];
}RepoFileInfoList;



#endif //MC_REPOFILE_H
