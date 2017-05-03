/*
test.c
author:mendel
*/
#include <stdio.h>
#include <time.h>
#include <string.h>

#define col 8
#define row 8
char board[row][col];
struct point
{
	int x;
	int y;
};
struct point findKing(int flag)
{
	char finded;
	int i, j;
	struct point tmp;
	if (flag == 0)
		finded = 'k';
	else
		finded = 'K';
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			if (board[i][j] == finded)
			{
				tmp.x = i;
				tmp.y = j;
				break;
			}
	}
	return tmp;
}
int checkR(int x, int y, char ch)
{
	int i;
	for (i = y - 1; i >= 0; i++)
	{
		if (board[x][i] == ch)
			return 1;
		if (board[x][i] != '.' && board[x][i] != ch)
			break;
	}
	for (i = y + 1; i < col; i++)
	{
		if (board[x][i] == ch)
			return 1;
		if (board[x][i] != '.' && board[x][i] != ch)
			break;
	}
	for (i = x - 1; i >= 0; i++)
	{
		if (board[i][y] == ch)
			return 1;
		if (board[i][y] != '.' && board[i][y] != ch)
			break;
	}

	for (i = x + 1; i < row; i++)
	{
		if (board[i][y] == ch)
			return 1;
		if (board[i][y] != '.' && board[i][y] != ch)
			break;
	}
	return 0;
}
int checkB(int x, int y, char ch)
{
	int i, j, xt, yt;
	int a[4][2] = { { -1, -1 },{ -1, 1 },{ 1, 1 },{ 1, -1 } };
	for (i = 0; i < 4; i++)
	{
		for (j = 1;; j++)
		{
			xt = x + a[i][0] * j;
			yt = y + a[i][1] * j;
			if (xt >= row || xt < 0 || yt < 0 || yt >= col)
				break;
			if (board[xt][yt] == ch)
				return 1;
			if (board[xt][yt] != '.' && board[xt][yt] != ch)
				break;
		}
	}
	return 0;
}
int checkN(int x, int y, char ch)
{
	int i, xt, yt;
	struct point p[8] = { { -1, -2 },{ -1, 2 },{ 1, 2 },{ 1, -2 },{ -2, 1 },{ -2, -1 },{ 2, 1 },{ 2, -1 } };
	for (i = 0; i < 8; i++)
	{
		xt = p[i].x + x;
		yt = p[i].y + y;
		if (xt >= row || xt < 0 || yt < 0 || yt >= col)
			continue;
		if (board[xt][yt] == ch)
			return 1;
	}
	return 0;
}
/*
return
1 in check
0 not
*/
int checkKing(int flag, int x, int y)
{
	char chess[6];
	int s;
	int i, j;
	if (flag)
	{
		chess[0] = 'p';
		chess[1] = 'r';
		chess[2] = 'b';
		chess[3] = 'q';
		chess[4] = 'k';
		chess[5] = 'n';
		s = -1;
	}
	else
	{
		chess[0] = 'P';
		chess[1] = 'R';
		chess[2] = 'B';
		chess[3] = 'Q';
		chess[4] = 'K';
		chess[5] = 'N';
		s = 1;
	}
	//check soldiers
	if (x + s < row && x + s >= 0)
	{
		if (y > 0)
			if (board[x + s][y - 1] == chess[0])
				return 1;
		if (y < col)
			if (board[x + s][y + 1] == chess[0])
				return 1;
	}
	//check r
	if (checkR(x, y, chess[1]))
		return 1;
	//check b
	if (checkB(x, y, chess[2]))
		return 1;
	//check Q
	if (checkR(x, y, chess[3]) || checkB(x, y, chess[3]))
		return 1;
	if (checkN(x, y, chess[5]))
		return 1;
	return 0;
}
void checkWinner(int round)
{
	int state = 0; //0 none 1 black 2 white
	struct point bking = findKing(0);
	struct point wking = findKing(1);
	if (checkKing(0, bking.x, bking.y))
		state = 1;
	else if (checkKing(1, wking.x, wking.y))
		state = 2;
	if (state == 1)
		printf("Game #%d: black king is in check.\n", round);
	else if (state== 2)
		printf("Game #%d: white king is in check.\n", round);
	else
		printf("Game #%d: no king is in check.\n", round);
}
/*
check if the game is over
1 game over
0 continue
*/
int CheckGame()
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] != '.')
				return 0;
		}
	}
    return 1;
}
int main()
{
	int starttime = 0;
	int endtime = 0;
	int i, j;
	char ch;
	int round = 0;
	starttime = clock();
	while (1)
	{
		round++;
		memset(board, 0, col * row);
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				scanf("%c", &ch);
				if (ch != '\n')
				{
					board[i][j] = ch;
				}
				else
					j--;
			}
		}
		if (CheckGame())
			break;
		checkWinner(round);
	}
	endtime = clock();
	printf("excute time is %d ms.", endtime - starttime);
	getchar();
	return 0;
}

