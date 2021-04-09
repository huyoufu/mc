/**
 * Created by huyoufu on 2021/4/9 22:07.
 * contact me -->https://www.jk1123.com
 */


#ifndef MC_REPOFILE_H
#define MC_REPOFILE_H

typedef struct FileInfo_{
    long last_modify_time;
    long create_time;
    char *name;
    enum FileType fileType;
} FileInfo;

enum FileType{
    PNG,
    JPG,
    TXT,
    HTML,
    XML,
    ZIP,
    RAR,
    EXE,
} ;
#endif //MC_REPOFILE_H
