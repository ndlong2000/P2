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
    int k = 4;
    unsigned long end = 1;
    char fileName[20] = "NO FILE NAME";
    int bias = 0;
    unsigned long long t = 0;

    //gan gia tri cho cac tham so neu phan tu dau khong co '=' va 's'
    if ( (getPos(argv[1],'=')==-1) && (getPos(argv[1],'s')==-1) ) {
        k = atoi(argv[1]);
        end = strtoul(argv[2],NULL,0);
        strcpy(fileName,argv[3]);
        bias = atoi(argv[4]);
    }
    //gan gia tri cho t neu input co dang Xs
    else if ( (getPos(argv[1],'=')==-1) && (getPos(argv[1],'s')>0) ) {
        char time[50];
        memset(time,'\0',50);
        strncpy(time,argv[1],getPos(argv[1],'s'));
        long double t1 = strtold(time,NULL);
        t = 1000000*t1;
    }
    //gan gia tri cho t neu input co dang t=MWDh (mac dinh 1 Month=30days)
    else if ( (getPos(argv[1],'=')==1) && (getPos(argv[1],'t')==0) ){
        //tim vi tri cac ki tu thoi gian
        int pM,pw,pd,ph,pm; //vi tri cua M,w,d,h,m
        pM=pw=pd=ph=pm=0;
        //tim so thang, so tuan,so ngay,so gio, so phut
        int nM,nw,nd,nh,nm,ns;//so thang,so tuan,so ngay,so gio,so phut,so giay
        nM=nw=nd=nh=nm=ns=0;
        char temp[50],a[10];
        strcpy(temp,argv[1]+2);
        if(getPos(temp,'M')>0) pM=getPos(temp,'M');
        if(pM>0){
            memset(a,'\0',10);
            strncpy(a,temp,pM);
            nM=atoi(a);
            strcpy(temp,temp+pM+1);
        }
        if (getPos(temp,'W')>0) pw=getPos(temp,'W');
            else if (getPos(temp,'w')>0) pw=getPos(temp,'w');
        if(pw>0){
            memset(a,'\0',10);
            strncpy(a,temp,pw);
            nw=atoi(a);
            strcpy(temp,temp+pw+1);
        }
        if (getPos(temp,'D')>0) pd=getPos(temp,'D');
            else if (getPos(temp,'d')>0) pd=getPos(temp,'d');
        if(pd>0){
            memset(a,'\0',10);
            strncpy(a,temp,pd);
            nd=atoi(a);
            strcpy(temp,temp+pd+1);
        }
        if (getPos(temp,'H')>0) ph=getPos(temp,'H');
            else if (getPos(temp,'h')>0) ph=getPos(temp,'h');
        if(ph>0){
            memset(a,'\0',10);
            strncpy(a,temp,ph);
            nh=atoi(a);
            strcpy(temp,temp+ph+1);
        }
        if(getPos(temp,'m')>0) pm=getPos(temp,'m');
        if(pm>0){
            memset(a,'\0',10);
            strncpy(a,temp,pm);
            nm=atoi(a);
            strcpy(temp,temp+pm+1);
        }
        ns=atoi(temp);
        t=(2592000*nM+604800*nw+86400*nd+3600*nh+60*nm+ns);
        t=t*1000000;
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
    printf("t=%lu\n",t);
}
