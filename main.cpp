#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "gtest/gtest.h"
using namespace std;
int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *sd;
    dir-opendir(".");
    
    if (dir == NULL)
    {
        printf("Err!");
        exit(1);
    }
    
    while ( ( sd=readdir(dir)) !=NULL )
    {
        printf(">> %s\n", sd->d_name);
    }
    
    closedir(dir);
    
    return 0;  
}
