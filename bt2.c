#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char line[30][255];
int i = 1;
char fileName[50];
FILE* f;

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

void funLine1 (char *s1)
{
    memset(fileName,'\0',50);
    strncpy(fileName,s1,getPos(s1,'.'));
    strcat(fileName,".csv");
    f = fopen(fileName,"r");
    if(f!=NULL)
    while(fgets(line[i],255,f))    {
        i++;
    };
    fclose(f);
    char s0[255] = "Load file ";
    char* s2 = ",,,,,\n";
    strcat(s0,s1);
    strcat(s0,s2);
    strcpy(line[1],s0);
}

void funLine2 (char *s1)
{
    char s0[255] = "Thpt,";
    char* s2 = ",,,,\n";
    strcat(s0,s1);
    strcat(s0,s2);
    strcpy(line[2],s0);
}

void funLine3(char* algo)
{
    char s0[255] = ",Transferring Time,";
    char* s2 = ",,,\n";
    strcat(s0,algo);
    strcat(s0,s2);
    strcpy(line[3],s0);
}

void funLine4()
{
    strcpy(line[4],",,so su kien,time(s),Memory (MiB),badness\n");
}

void funLine5p(float thpt, long ts, unsigned long count, float t, float mem, float bn)
{
    if(i>4) {
    sprintf(line[i],"%f,%ld,%lu,%f,%f,%f\n",thpt,ts,count,t,mem,bn);
    i++;
    printf("%d",i);
    if (i>6){
    long ts[100];
    for(int j=5;j<i;j++){
        char temp[255];         //luu "luu lai line[j]"
        char temp2[50];         //luu chuoi "ts=abc"
        strcpy(temp,line[j]);
        strcpy(temp,temp+getPos(temp,',')+1);   //bo di "thpt,"
        memset(temp2,'\0',20);
        strncpy(temp2,temp,getPos(temp,','));    //lay ra "ts"
        ts[j] = strtol(temp2,NULL,0);
    }
    int j=5;
    while((ts[i-1] >= ts[j])&&(j != i-1)){
        j++;
    }
    if (j!= i-1) {
        char s[255];
        strcpy(s,line[i-1]);
        int k;
        for(k=i-2;k>=j;k--){
            strcpy(line[k+1],line[k]);
            k--;
        }
        strcpy(line[j],s);
        }
    }
    }
    if(i<5) {
        sprintf(line[5],"%f,%ld,%lu,%f,%f,%f\n",thpt,ts,count,t,mem,bn);
        i=6;
    }
}


int main()  {
    funLine1("long1.txt");
    funLine2("Intel(R) Core(TM) i7-3610QM CPU @ 2.30GHz RAM 8GB Ubuntu 20.4");
    funLine3("Array Calendar Queue");
    funLine4();
    funLine5p(62.23,8,96668767,28.6,19.23,4.6);
    f = fopen(fileName,"w+");
    for(int j=1;j<i;j++) fprintf(f,"%s",line[j]);
    fclose(f);
}
