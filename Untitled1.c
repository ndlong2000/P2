#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getPos(char *s, char c)
{
    int i;
    for(i=0; s[i] != NULL;i++){
        if(s[i]==c) {
            return i;
        }
    };
    return -1;
}

int main(int argc, char *argv[])
{
    int k;
    unsigned long end;
    char fileName[20];
    int bias;
    if (getPos(argv[1],'=')==-1) {
        k = atoi(argv[1]);
        end = strtoul(argv[2],NULL,0);
        strcpy(fileName,argv[3]);
        bias = atoi(argv[4]);
    }
    else{
        for(int i=1;i<argc;i++){
        int d = getPos(argv[i],'=');
        char key[20];
        char value[20];
        memset(key,'\0',20);
        memset(value,'\0',20);
        strncpy(key,argv[i],d);
        strcpy(value,argv[i]+d+1);
        if(strcmp(key,"k")==0) k = atoi(value);
        else if(strcmp(key,"end")==0) end = strtoul(value,NULL,0);
        else if(strcmp(key,"fileName")==0) strcpy(fileName,value);
        else if(strcmp(key,"bias")==0) bias = atoi(value);
        }
    };
    printf("k=%d\n",k);
    printf("end=%lu\n",end);
    printf("fileName=%s\n",fileName);
    printf("bias=%d\n",bias);
}
