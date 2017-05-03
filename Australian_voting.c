/*
test.c
author:mendel
*/
#include <stdio.h>
#include <time.h>
#include <string.h>

char name[20][80];
int votes[20];
int statics[1000][20];
void process(char* str, int index,int members)
{
	int a1, j, i;
	j = 0;
	a1 = 0;
	for (i = 0; str[i]!='\n'&&i < 100&&j<20; i++)
	{
		if (str[i]<'9'&&str[i]>'0')
			a1 += a1 * 10 + str[i] - '0';
		if (str[i] == ' '&&a1>0&&a1<=members)
		{
			statics[index][j] = a1;
			j++;
			a1 = 0;
		}
	}
	if(a1!=0)
		statics[index][j] = a1;
}
void voting(int members, int voters)
{
	int half = voters / 2;
	int min;
	int i, j;
	while (1)
	{
		min = 1000;
		//统计
		for (i = 0; i < voters; i++)
			for (j = 0; j < members; j++)
			{
				if(statics[i][j]>0)
					if (votes[statics[i][j] - 1] >= 0)
					{
						votes[statics[i][j] - 1]++;
						break;
					}
			}
		//more than 50% ,win
		for (i = 0; i < members; i++)
			if (votes[i] > half)
			{
				printf("%s", name[i]);
				return;
			}
		//get the min votes
		for (i = 0; i < members; i++)
			if (votes[i] < min)
				min = votes[i];
		for (i = 0; i < members; i++)
			if (votes[i]>=0&&votes[i] != min)
				break;
		if (i == members)
		{
			for (i = 0; i < members; i++)
				if (votes[i] >= 0)
					printf("%s", name[i]);
			return;
		}
		//
		for (i = 0; i < members; i++)
		{
			if (votes[i] == min)
				votes[i] = -1;
			else
				votes[i] = 0;
		}
	}
}
int main()
{
	int n,i;//组数
	//
	int members;
	int starttime = 0;
	int endtime = 0;
	char tmp[100];
	starttime = clock();
	//
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &members);
		getchar();
		for (i = 0; i < members; i++)
		{
			fgets(name[i], 80, stdin);
			if (name[i][0] == '\n')
				i--;
		}
		//important tips to clear newline symbol.
		i = 0;
		while (i<1000)
		{
			fgets(tmp, 100, stdin);
			if (tmp[0] == '\n' || tmp[0] == '\r')
				break;
			process(tmp, i,members);
			i++;
		}
		voting(members,i);
	}
	endtime = clock();
	printf("excute time is %d ms.", endtime - starttime);
	getchar();
	return 0;
}

