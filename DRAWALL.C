/*----------棋盘绘制及初始化-----------*/
#define REDCOLOR 4
#define BLACKCOLOR 0

int linecolor1=15;
int linecolor2=0;
int bkgroundcolor=0;
int chesscolor=14;

void drawblock(int x,int y)//以每个交点为中心画棋盘
{
	int x1,y1;
	setcolor(linecolor1);
	if (x<0||y<0||x>COL||y>ROW) return;
	x1=STARTX+2*WIDE*x;
	y1=STARTY+2*WIDE*y;
	switch(x)
	{
		case 0: switch(y)
			{
				case 0:
					line(x1,y1,x1,y1+WIDE);
					line(x1,y1,x1+WIDE,y1);
					break;
				case 9:
					line(x1,y1,x1+WIDE,y1);
					line(x1,y1,x1,y1-WIDE);
					break;
				default:
					line(x1,y1,x1+WIDE,y1);
					line(x1,y1-WIDE,x1,y1+WIDE);
					break;
			}
			break;
		case 8: switch(y)
			{
				case 0:
					line(x1,y1,x1,y1+WIDE);
					line(x1,y1,x1-WIDE,y1);
					break;
				case 9:
					line(x1,y1,x1-WIDE,y1);
					line(x1,y1,x1,y1-WIDE);
					break;
				default:
					line(x1,y1,x1-WIDE,y1);
					line(x1,y1-WIDE,x1,y1+WIDE);
					break;
			}
			break;
		default:
			switch (y)
			{
				case 0: case 5:
					line(x1,y1,x1,y1+WIDE);
					line(x1-WIDE,y1,x1+WIDE,y1);
					break;
				case 4: case 9:
					line(x1-WIDE,y1,x1+WIDE,y1);
					line(x1,y1,x1,y1-WIDE);
					break;
				default:
					line(x1-WIDE,y1,x1+WIDE,y1);
					line(x1,y1-WIDE,x1,y1+WIDE);
					break;
			}
			break;
	}
	switch (x)
	{
		case 3:
			switch (y)
			{
				case 0: case 7:
					line(x1,y1,x1+WIDE,y1+WIDE);
					break;
				case 2: case 9:
					line(x1,y1,x1+WIDE,y1-WIDE);
					break;
			}
			break;
		case 4:
			if (y==1||y==8)
			{
				line(x1-WIDE,y1-WIDE,x1+WIDE,y1+WIDE);
				line(x1-WIDE,y1+WIDE,x1+WIDE,y1-WIDE);
			}
			break;
		case 5:
			switch(y)
			{
				case 0: case 7:
					line(x1,y1,x1-WIDE,y1+WIDE);
					break;
				case 2: case 9:
					line(x1,y1,x1-WIDE,y1-WIDE);
					break;
			}
			break;
	}
}

void dishz(int x0,int y0,int kind,int color)
{
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
		/*屏蔽点阵每行各位的数组*/
	int i,j,x,y,pos;
	char mat[35][32]={{2,0,2,8,127,-4,4,0,9,0,17,0,33,32,63,-16,1,0,1,4,-1,-2,1,0,1,0,1,0,1,0,1,0},
					{0,32,63,-16,0,32,8,32,8,32,8,32,8,32,8,36,15,-2,0,4,0,36,-1,-12,0,4,0,4,0,40,0,16},
					{16,-128,16,-124,16,-2,21,4,89,36,83,-12,85,36,-111,36,17,36,17,-28,17,20,41,8,37,2,69,2,-128,-2,0,0},
					{1,0,1,0,1,0,1,0,1,0,1,4,-1,-2,1,0,1,0,1,0,1,0,1,0,1,0,1,16,63,-8,0,0},
					{8,0,15,-32,16,72,63,-4,97,8,-95,8,63,-8,6,16,25,32,98,-64,12,-64,49,-96,6,-112,24,-114,98,-124,1,0},
					{16,-128,16,-128,17,-8,-111,8,115,16,52,-96,16,64,16,-108,31,-2,48,16,82,16,-47,-112,16,-112,16,16,16,80,16,32},
					{2,0,1,8,127,-4,8,32,8,32,8,32,20,80,34,-120,1,0,1,4,-1,-2,1,0,1,0,1,0,1,0,1,0},
					{0,32,0,-16,15,0,8,0,8,0,8,16,15,-8,8,64,8,64,8,68,-1,-2,0,0,4,64,12,48,16,24,32,8},
					{8,32,8,32,72,36,73,-2,73,36,73,36,73,36,73,36,73,36,73,36,73,36,9,36,17,52,17,40,32,32,64,32},
					{0,56,63,-64,1,4,-1,-2,1,16,31,-8,17,16,31,-16,17,16,31,-16,1,0,63,-8,1,0,1,4,-1,-2,0,0},
					{16,8,10,28,127,96,0,64,34,64,20,68,-1,-2,10,72,127,72,8,72,10,72,41,-120,72,-120,-119,8,40,8,16,8},
					{0,8,127,-4,8,32,8,32,8,32,8,32,8,36,-1,-2,8,32,8,32,8,32,8,32,16,32,16,32,32,32,64,32},
					{16,64,16,64,16,64,16,-128,-4,-120,37,4,39,-2,36,2,36,4,73,-2,41,4,17,4,41,4,69,4,-123,-4,1,4},
					{17,0,17,8,17,-4,26,0,85,-8,81,8,81,72,-111,40,31,-2,18,8,18,-120,18,72,19,-4,16,8,16,40,16,16},
					{17,8,17,8,19,-4,17,8,-3,8,17,-8,49,8,57,8,85,-8,81,8,-111,8,23,-2,16,0,17,8,19,6,20,2},
					{2,0,2,4,-1,-2,4,0,8,0,11,-8,16,16,16,32,48,68,95,-2,-112,64,16,64,16,64,16,64,17,64,16,-128},
					{16,64,16,64,18,68,17,76,-3,80,16,68,55,-2,56,4,84,4,80,4,-109,-4,16,4,16,4,16,4,23,-4,16,4},
					{0,32,32,40,19,-4,16,32,0,32,7,-2,-16,-110,16,84,17,16,16,-108,23,-2,16,32,20,32,24,80,16,-116,3,4},
					{2,16,31,-8,16,16,18,16,17,20,-1,-2,16,16,18,16,33,80,64,32,63,-8,36,72,36,72,36,72,-1,-2,0,0},
					{0,64,64,64,48,64,16,64,0,64,0,64,-16,-96,16,-96,16,-96,17,16,17,16,21,16,26,8,18,8,4,6,8,4},
					{32,64,32,-96,40,-96,-3,16,34,14,69,-12,80,0,-109,-60,-6,84,19,-44,58,84,-45,-44,18,84,18,68,18,68,18,-52},
					{3,-8,66,8,50,8,19,-8,2,8,2,8,-13,-4,18,8,18,-48,18,32,18,-112,19,12,18,4,40,0,68,6,3,-4},
					{1,0,1,0,33,8,33,8,33,8,33,8,63,-8,33,8,1,0,65,4,65,4,65,4,65,4,65,4,127,-4,64,4},
					{0,8,63,-4,33,8,49,40,45,56,37,72,33,8,63,-8,1,0,127,-4,1,0,-1,-2,0,0,40,-112,36,76,68,68},
					{16,0,16,8,35,-4,32,32,68,32,-8,32,16,32,32,32,64,32,-4,32,64,32,0,32,28,32,-32,36,71,-2,0,0},
					{4,0,3,0,1,0,0,4,-1,-2,4,0,4,16,7,-8,4,16,4,16,4,16,8,16,8,16,16,16,32,-96,64,64},
					{16,-128,16,-128,16,-128,16,-112,-1,-8,16,-112,20,-112,24,-112,49,-112,-48,-112,17,80,17,82,17,18,18,18,84,14,40,0},
					{17,8,17,8,19,-4,17,8,-3,8,17,-8,49,8,57,8,85,-8,81,8,-111,8,23,-2,16,0,17,8,19,6,20,2},
					{32,32,16,32,16,32,5,-2,-3,34,9,36,17,32,53,32,89,-4,-107,4,17,-120,18,80,18,32,20,80,24,-114,19,4},
					{16,-128,16,-128,17,-8,-111,8,115,16,52,-96,16,64,16,-108,31,-2,48,16,82,16,-47,-112,16,-112,16,16,16,80,16,32},
					{0,0,127,-2,66,2,-126,20,63,-8,4,0,9,0,17,16,63,-8,1,0,1,4,-1,-2,1,0,1,0,1,0,1,0},
					{32,32,16,32,16,32,5,-2,-3,34,9,36,17,32,53,32,89,-4,-107,4,17,-120,18,80,18,32,20,80,24,-114,19,4},
					{0,-128,8,-128,124,-120,72,-4,73,0,74,0,77,-8,72,16,72,32,72,64,72,-128,121,0,74,2,2,2,1,-2,0,0},
					{2,0,2,8,127,-4,4,0,9,0,17,0,33,32,63,-16,1,0,1,4,-1,-2,1,0,1,0,1,0,1,0,1,0},
					{8,32,124,32,73,32,73,32,73,40,121,-4,74,32,76,32,72,40,121,-4,72,32,72,32,72,32,72,36,75,-2,-104,0}
};
			//车马炮士象将卒兵帅 重新开始 悔棋 存档读盘认输退出 黑红方执棋 被将军被吃车 胜的汉字 由字库提取
	y=y0;
	for (i=0;i<16;++i)
	{
		x=x0;
		pos=2*i;
		for(j=0;j<16;++j)
		{
				 /*屏蔽出汉字点阵的一个位，即一个点是1则显示，否则不显示该点*/
			if ((mask[j%8]&mat[kind][pos+j/8])!=NULL)
				putpixel(x,y,color);
			++x;
		}
		++y;
	}
}

void chessdraw(int x,int y, int z)
{
	int color;
	int chessname;
	setfillstyle(1,14);
	fillellipse(x,y,20,20);
	switch (z)
	{
	case 16: color=REDCOLOR; chessname=8; break;
	case 17: case 18: color=REDCOLOR; chessname=3; break;
	case 19: case 20: color=REDCOLOR; chessname=4; break;
	case 21: case 22: color=REDCOLOR; chessname=1; break;
	case 23: case 24: color=REDCOLOR; chessname=0; break;
	case 25: case 26: color=REDCOLOR; chessname=2; break;
	case 27: case 28: case 29: case 30: case 31: color=REDCOLOR; chessname=7; break;
	case 32: color=BLACKCOLOR; chessname=5; break;
	case 33: case 34: color=BLACKCOLOR; chessname=3; break;
	case 35: case 36: color=BLACKCOLOR; chessname=4; break;
	case 37: case 38: color=BLACKCOLOR; chessname=1; break;
	case 39: case 40: color=BLACKCOLOR; chessname=0; break;
	case 41: case 42: color=BLACKCOLOR; chessname=2; break;
	case 43: case 44: case 45: case 46: case 47: color=BLACKCOLOR; chessname=6; break;
}
	dishz(x-8,y-8,chessname,color);

}

void transformxy(int z,int *x,int *y)/*z表示棋子，xy返回z棋子在a中坐标*/
{
	*y=(piece[z]-51)/16;
	*x=(piece[z]-51)%16;
}

int transform(int x,int y)
{
	return x+y*16+51;
}

void startgame()
{
	int x,y,z;

	setfillstyle(1,bkgroundcolor);
	bar(7,7,467,467);
	for (x=0;x<=COL ;x++ )
	for (y=0;y<=ROW ;y++ )
		drawblock(x,y);
	for (x=0;x<=COL ;x++ )
	for (y=0;y<=ROW ;y++ )
	{
		z=transform(x,y);
		if (board[z])
		chessdraw(STARTX+2*WIDE*x,STARTY+2*WIDE*y,board[z]);
	}
}

/*游戏初始化*/
void restart()
{
	int x,y,z;

	int graphdriver=VGA;
	int graphmode=VGAHI;
	initgraph(&graphdriver,&graphmode,"c:\\tc30\\bgi");
	setbkcolor(bkgroundcolor);
	setlinestyle(0,0,2);

	StackTop=0;

	for (x=0;x<=COL ;x++ )
	for (y=0;y<=ROW ;y++ )
	drawblock(x,y);
	setfillstyle(1,14);
	bar(500,30,610,55);
	y=34;
	z=9;
	for (x=510;x<600;x+=25 )
	{
	dishz(x,y,z,4);
	z++;
	}
	bar(500,80,610,105);
	dishz(525,85,13,4);
	dishz(575,85,14,4);
	bar(500,130,610,155);
	dishz(525,135,15,4);
	dishz(575,135,16,4);
	bar(500,180,610,205);
	dishz(525,185,17,4);
	dishz(575,185,18,4);
	bar(500,230,610,255);
	dishz(525,235,19,4);
	dishz(575,235,20,4);
	bar(500,280,610,305);
	dishz(525,285,21,4);
	dishz(575,285,22,4);
}

void clearchess(int x,int y)
{
	setfillstyle(1,bkgroundcolor);
	setcolor(linecolor2);
	fillellipse(x,y,21,21);
}

int findnearest(int *x,int *y,int mode)
{
	int x1,y1,quadrant;
	if (mode==0)
	{
		x1=(*x-STARTX)/(2*WIDE);
		y1=(*y-STARTY)/(2*WIDE);
		if (x1<0) x1++;
		if (y1<0) y1++;
		*x=x1;
		*y=y1;
		return 1;
	}
	else
	{
		x1=(*x-STARTX)/WIDE;
		y1=(*y-STARTY)/WIDE;
		if (x1<0) x1++;
		if (y1<0) y1++;
		x1=x1/2+x1%2;
		y1=y1/2+y1%2;
		if (*x>(STARTX+2*WIDE*x1-12)&&*y>(STARTY+2*WIDE*y1-12)&&*x<(STARTX+2*WIDE*x1+12)&&*y<(STARTY+2*WIDE*y1+12))
		{
			*x=x1;
			*y=y1;
			return 2;
		}
		else return 0;
	}
}

void repairmap(int x,int y,int mode,int samename)
{
	int chessname;
	if (mode==2)
	{
		drawblock(x,y);
		chessname=board[transform(x,y)];
		if (chessname&&chessname!=samename) chessdraw(STARTX+2*WIDE*x,STARTY+2*WIDE*y,chessname);
	}
	if (mode==1)
	{
		drawblock(x,y);
		chessname=board[transform(x,y)];
		if (chessname&&chessname!=samename) chessdraw(STARTX+2*WIDE*x,STARTY+2*WIDE*y,chessname);
		if (x<COL) 
		{	
			drawblock(x+1,y);
			chessname=board[transform(x+1,y)];
			if (chessname&&chessname!=samename) chessdraw(STARTX+2*WIDE*(x+1),STARTY+2*WIDE*y,chessname);
		}
		if (y<ROW)
		{
			drawblock(x,y+1);
			chessname=board[transform(x,y+1)];
			if (chessname&&chessname!=samename) chessdraw(STARTX+2*WIDE*x,STARTY+2*WIDE*(y+1),chessname);
		}
		if (x<COL&&y<ROW)
		{
			 drawblock(x+1,y+1);
			 chessname=board[transform(x+1,y+1)];
			 if (chessname&&chessname!=samename) chessdraw(STARTX+2*WIDE*(x+1),STARTY+2*WIDE*(y+1),chessname);
		}
	}
}

void movechess(int x1,int y1, int x2, int y2)
{
	move z;
	z.from=transform(x1,y1);
	z.to=transform(x2,y2);
	z.capture=board[z.to];
	MakeMove(z);
	/*clearchess(STARTX+2*WIDE*x1,STARTY+2*WIDE*y1);
	drawblock(x1,y1);
	chessdraw(STARTX+2*WIDE*x1,STARTY+2*WIDE*y1,board[z.to]);
*/
	startgame();
}