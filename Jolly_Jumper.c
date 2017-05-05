#include <stdio.h>
#include <time.h>


#define maxs 1000
int data[maxs];
int abs(int a)
{
	return a > 0 ? a : -1 * a;
}
int function2()
{
	int i, n, pre, current;
	int flag = 0;
	/*
	i counter;
	n total
	pre previous data.
	current current data read in
	*/
	memset(data, 0, maxs);
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &current);
		if (i >= 1)
		{
			if (abs(current - pre) >= n)
				flag=1;
			else
				data[abs(current - pre)] = 1;
		}
		pre = current;
	}
	for(i=1;i<n;i++)
		if (data[i] == 0)
		{
			flag = 1;
			break;
		}
	if (n == 1)
		flag = 1;
	return flag;
}
int main()
{
	while (1)
	{
		if (function2())
			printf("Not jolly\n");
		else
			printf("Jolly\n");
	}
	return 0;
}