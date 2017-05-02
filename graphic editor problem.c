/*
test.c
author:mendel
*/
#include <stdio.h>
#include <time.h>
/*
swap x and y's value
*/
#define swap(x,y)\
(x)=(x)+(y);\
(y)=(x)-(y);\
(x)=(x)-(y);
/*
max bmp 
better method:
#define maxm 250
#define maxn 250
use defined variable instead of constant value.
*/
char bmp[250][250] = {'0'};
int m = 0;
int n = 0;
/*
check whether operation is ou of range.
*/
int rangeCheck(int x,int y)
{
    if(x<1||y<1||x>m||y>n)
        return 1;
    return 0;
}
/*
print the piture array on the screen.
*/
void printMatrix()
{
    int i,j;
      if (m == 0 && n == 0)
    {
        printf("Error:There is no bmp has been created.\n");
        return;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
          printf("%c ",bmp[j][i]);
        printf("\n");
    }

}
/*
create a new bmp.
that is:
change the value of m and n.
*/
void createBmp()
{
    scanf("%d %d", &m, &n);
}
/*
make bmp to '0'
*/
void clearBmp()
{
    int i, j;
    if (m == 0 && n == 0)
        printf("Error:There is no bmp has been created.\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            bmp[i][j] = '0';
}
/*
draw a point 
*/
void point()
{
    int x, y;
    char c;
    scanf("%d %d %c", &x, &y, &c);
    if (m == 0 && n == 0)
    {
        printf("Error:There is no bmp has been created.\n");
        return;
    }
    if (x < 1 || y < 1 || x > m || y > n)
    {
        printf("Error:out of range.picture scale:%d x %d\n", m, n);
        return;
    }
    bmp[x - 1][y - 1] = c;
}
/*
draw a veritical line
*/
void vLine()
{
    int x, y1, y2,tmp,i;
    char c;
    scanf("%d %d %d %c", &x, &y1, &y2, &c);
    if (m == 0 && n == 0)
    {
        printf("Error:There is no bmp has been created.\n");
        return;
    }
    if (rangeCheck(x,y1)||rangeCheck(x,y2))
    {
         printf("Error:out of range.picture scale:%d x %d\n", m, n);
        return;
    }
    if(y1>y2)
    {
        swap(y1,y2)
    }  
    for(i=y1-1;i<y2;i++)
        bmp[x-1][i]=c;
}
/*
draw horrizen line.
*/
void hLine()
{
    int y, x1, x2,tmp,i;
    char c;
    scanf("%d %d %d %c", &x1, &x2, &y, &c);
    if (m == 0 && n == 0)
    {
        printf("Error:There is no bmp has been created.\n");
        return;
    }
    if (rangeCheck(x1,y)||rangeCheck(x2,y))
    {
        printf("Error:out of range.picture scale:%d x %d\n", m, n);
        return;
    }
    if(x1>x2)
     {
        swap(x1,x2)
     }   
    for(i=x1-1;i<x2;i++)
        bmp[i][y-1]=c;
}
/*
fill a rectangle.
*/
void rectangle()
{
    int x1,y1,x2,y2;
    int i,j;
    char c;
    scanf("%d %d %d %d %c",&x1,&y1,&x2,&y2,&c);
    if (m == 0 && n == 0)
        printf("Error:There is no bmp has been created.\n");
    if(rangeCheck(x1,y1)||rangeCheck(x2,y2))
    {
        printf("Error:out of range.picture scale:%d x %d\n", m, n);
        return;
    }
      if(x1>x2)
       {
            swap(x1,x2)
       } 
     if(y1>y2)
       {
           swap(y1,y2)
       }
    for(i=x1-1;i<x2;i++)
        for(j=y1-1;j<y2;j++)
            bmp[i][j]=c;
}
/*
fill area with color c
recursion way.
*/
void fillaround(int x,int y,char oldc,char newc)
{
    if(oldc==newc)
        return;
    bmp[x][y]=newc;
    if(x>0)
        if(bmp[x-1][y]==oldc)
            fillaround(x-1,y,oldc,newc);
    if(x<m-1)
        if(bmp[x+1][y]==oldc)
            fillaround(x+1,y,oldc,newc);
    if(y>0)
           if(bmp[x][y-1]==oldc)
            fillaround(x,y-1,oldc,newc);
    if(y<n-1)
         if(bmp[x][y+1]==oldc)
            fillaround(x,y+1,oldc,newc); 
}
void fill()
{
    int x,y;
    char c;
    scanf("%d %d %c",&x,&y,&c);
      if (m == 0 && n == 0)
        printf("Error:There is no bmp has been created.\n");
    fillaround(x-1,y-1,bmp[x-1][y-1],c);
}
void printBmp()
{
    char name[20];
    scanf("%s",name);
    printf("%s\n",name);
    printMatrix();
}
int main()
{
    int starttime = 0;
    int endtime = 0;
    char command;
    starttime = clock();
    m=250;
    n=250;
    clearBmp();
    m=0;
    n=0;
    while (scanf("%c", &command) && command != 'X')
    {
        switch (command)
        {
        case 'I':
            createBmp();
            break;
        case 'C':
            clearBmp();
            break;
        case 'L':
            point();
            break;
        case 'V':
            vLine();
            break;
        case 'H':
            hLine();
            break;
        case 'K':
            rectangle();
            break;
        case 'F':
            fill();
            break;
        case 'S':
            printBmp();
            break;
        default:
            break;
        }
    }
    endtime = clock();
    printf("excute time is %d ms.", endtime - starttime);
    getchar();
    return 0;
}