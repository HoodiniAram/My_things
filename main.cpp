#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
//#include <gtest/gtest.h>
using namespace std;
int linecounter(string filen)
{
    int numberlines=0;
    string line;
    ifstream myfile(filen);
    
    while (getline(myfile, line))
        {++numberlines;}

    myfile.close();
    
    return numberlines;
}
int main(int argc, char *argv[])
{
    int numberoffile=0, numberoflines=0;
    string file;
    DIR *dir;
    struct dirent *sd;
    dir=opendir(".");
    /*
        unfortunately i don't know how to use Gtest
    TEST(TestDirrectory, Test1)
    {
        EXPECT_EQ(NULL)
    }
    */
    if (dir == NULL)
    {
        printf("Err!");
        exit(1);
    }
    
    while ( ( sd=readdir(dir)) !=NULL )
    {
        file.clear();
        numberoffile++;
        file=sd->d_name;
        numberoflines=numberoflines+linecounter(file);
    }
    
    closedir(dir);
    cout<<"number of files "<<numberoffile<<"\n number of lines: "<<numberoflines;
    return 0;  
}
