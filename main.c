#include <stdlib.h>
#include <stdint.h>
#include <windows.h>
#include <dirent.h>
#include <stdio.h>
#include <time.h>
//在windows平台上 每隔100ns就会计时器加1 而一秒等于10的9此方法 所有 直接除于10的7次方就可以获得秒值
#define WINDOWS_TICK 10000000  //10的7次方
#define SEC_TO_UNIX_EPOCH 11644473600LL //1601与1970的时间间隔
#define TickFrom1601to1970 SEC_TO_UNIX_EPOCH*WINDOWS_TICK
char * time2localString(const time_t t,char *result){
    // yyyy-MM-dd HH:mm:ss
    struct tm *utcTime=gmtime(&t);

    sprintf(result,"%d-%d-%d %d:%d:%d",utcTime->tm_year+1900, utcTime->tm_mon+1, utcTime->tm_mday, utcTime->tm_hour, utcTime->tm_min, utcTime->tm_sec);
    return result;
}


void  FileTimeToTime_t(FILETIME  ft,  time_t  *t  )
{
    LONGLONG  ll=0;
    ULARGE_INTEGER            ui;
    ui.LowPart            =  ft.dwLowDateTime;
    ui.HighPart            =  ft.dwHighDateTime;
    //ll            =  ft.dwHighDateTime  <<  32  |  ft.dwLowDateTime;
    //必须必须先赋值再左移 因为直接左移 是在32位的基础左移的  我们先改变成64位单元 再左移
    //ll|=ft.dwHighDateTime;
    //ll=ll<<32|ft.dwLowDateTime;
    //ULARGE_INTEGER 则是利用了共用体的特性
    *t            =  ((LONGLONG)(ui.QuadPart  -  TickFrom1601to1970)  /  WINDOWS_TICK);
}

char *getMavenHome() {
    char *m2_home = getenv("M2_HOME");
    char *maven_home = getenv("MAVEN_HOME");
    char *home = maven_home == NULL ? m2_home : maven_home;

    return home;
}

void listFiles(const char *dir) {


    HANDLE hFind;
    WIN32_FIND_DATA findData;
    LARGE_INTEGER size;
    char dirNew[260];
    char delFile[260];


    // 向目录加通配符，用于搜索第一个文件
    strcpy(dirNew, dir);
    strcat(dirNew, "/*.*");

    hFind = FindFirstFile(dirNew, &findData);
    do {
        //printf("%d",findData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY);

        if ((strcmp(findData.cFileName, ".") != 0
             && strcmp(findData.cFileName, "..") != 0)){


            // 是否是文件夹，并且名称不为"."或".."
            if (findData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY) {
                // 将dirNew设置为搜索到的目录，并进行下一轮搜索
                //printf("正在遍历文件夹: name---:%s\n",findData.cFileName);
                strcpy(dirNew, dir);
                strcat(dirNew, "\\");
                strcat(dirNew, findData.cFileName);
                listFiles(dirNew);
            } else {

                time_t t;
                FileTimeToTime_t(findData.ftLastWriteTime,&t);
                //直接在栈上分配 18的空间 使用完毕之后 自动回收!!! 如果使用malloc 需要手动释放麻烦了
                char result[18];

                //printf("正在遍历文件: name:%s~~~ mtime:%s\n",findData.cFileName,time2localString(t,result));
                if (strstr(findData.cFileName,".lastUpdated")){
                    //只要存在最后一个.lastUpdated 则认为该文件有问题

                    sprintf(delFile,"%s\\%s",dir,findData.cFileName);
                    printf("删除文件::::%s---结果:%s\n",delFile,remove(delFile)==0?"成功":"失败了");

                }


            }




        }

    } while (FindNextFile(hFind, &findData));

    FindClose(hFind);
}

int main() {

    char *home = getMavenHome();
    printf("准备清理%s目录下无用的文件!!!\n",home);

    listFiles(home);
    printf("清理完成!\n");
    system("pause");

    return 0;


}
