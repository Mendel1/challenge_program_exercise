/*
test.c
author:mendel
*/
#include <stdio.h>
#include <time.h>
#include <string.h>

int reg[10]={0};
int mem[1000]={0};

int process()
{
    int a,b,c;
   int pointer=0;
   int count=0;
   int i=0;
   pointer=mem[0];
   while(pointer!=100&&i<1000)
   {
        a=pointer/100;
        b=(pointer/10)%10;
        c=pointer%10;
        switch(a)
        {
            case 0:
             if(reg[c]!=0)
                i=reg[b]-1;break;
            case 2:
              reg[b]=c;break;
            case 3:
              reg[b]+=c;break;
            case 4:
              reg[b]*=c;break;
            case 5:reg[b]=reg[c];break;
            case 6:reg[b]+=reg[c];break;
            case 7:reg[b]*=reg[c];break;
            case 8:reg[b]=mem[reg[c]];break;
            case 9:mem[reg[c]]=reg[b];break;
            default:break;
        }
        reg[b]%=1000;
        i++;
        count++;
        pointer=mem[i];
   }
   return count+1;
}
int main()
{
    int starttime = 0;
    int endtime = 0;
    int groups;
    int code;
    int i=0;
    starttime = clock();
    scanf("%d",&groups);
    while (groups)
    {
        i=0;
       memset(reg,0,10);
       memset(mem,0,1000);
       while(scanf("%d",&code)&&code!=100)
       {
           mem[i]=code;
            i++;
       }
       mem[i]=code;
       printf("%d\n",process());
       groups--;
    }
    endtime = clock();
    printf("excute time is %d ms.", endtime - starttime);
    getchar();
    return 0;
}