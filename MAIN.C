#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>


#define ROW 9//行数
#define COL 8//列数
#define WIDE 23//半个格子的宽度
#define STARTX 30//棋盘右上角交点x坐标
#define STARTY 30//棋盘右上角交点y坐标


//int a[9][10];/*记录棋盘状态*/
int runninggame=1;//runninggame为1说明游戏未退出；为0则已经退出；
void dishz(int x0,int y0,int kind,int color);

#include"judge.c"
#include"drawall.c"
#include"saveload.c"
#include"mouse.c"


int main()
{
	restart();
	initmouse();
	return 0;
}