/*------------------鼠标----------------------*/
void initmouse()
{
	int mousekey,mousex,mousey,mouseflag,chessname,chessplace,quadrant,formalchessx,formalchessy,checkflag,checkflag2;
	move ft;
	/*chessplace记录鼠标选中的格子；formalchessx/y记录之前棋子所在像素点的横纵坐标；mouseflag记录是否已经选中棋子*/
	/*ft.from为开始位置，ft.to为目的位置，ft.capture为棋子名*/
	union REGS r;
	struct SREGS s;
	int retcode;
	r.x.ax=0;
	int86x(0x33,&r,&r,&s);
	retcode=r.x.ax;
	if (retcode==0)
	{
		printf("Failed to Setup a Mouse");
		delay(10000);
		return;
	}
	r.x.ax=1;
	int86x(0x33,&r,&r,&s);
	mousekey=0;
	mouseflag=0;
	while (runninggame)
	{
		r.x.ax=3;
		int86x(0x33,&r,&r,&s);	
		if (r.x.bx!=mousekey||mouseflag&&!mousekey)
		{
			mousekey=r.x.bx;
			if (r.x.cx<440)
			{
				mousex=r.x.cx;
				mousey=r.x.dx;
				if (mousekey==2&&mouseflag)
				{
					r.x.ax=2;
					int86x(0x33,&r,&r,&s);
					clearchess(formalchessx,formalchessy);
					quadrant=findnearest(&formalchessx,&formalchessy,0);
					repairmap(formalchessx,formalchessy,quadrant,chessname);
					transformxy(chessname,&formalchessx,&formalchessy);
					chessdraw(STARTX+2*WIDE*formalchessx,STARTY+2*WIDE*formalchessy,chessname);
					r.x.ax=1;
					int86x(0x33,&r,&r,&s);
					mouseflag=0;
				}
				if (mousekey==0&&mouseflag==1&&(mousex!=formalchessx||mousey!=formalchessy))
				{
					r.x.ax=2;
					int86x(0x33,&r,&r,&s);
					clearchess(formalchessx,formalchessy);
					quadrant=findnearest(&formalchessx,&formalchessy,0);
					repairmap(formalchessx,formalchessy,quadrant,chessname);
					chessdraw(mousex,mousey,chessname);
					formalchessx=mousex;
					formalchessy=mousey;
					r.x.ax=1;
					int86x(0x33,&r,&r,&s);
				}
				if (mousekey==1&&mouseflag==1)
				{
					r.x.ax=2;
					int86x(0x33,&r,&r,&s);
					quadrant=findnearest(&mousex,&mousey,1);
					if (quadrant==0) { r.x.ax=1;	int86x(0x33,&r,&r,&s); continue;}
					clearchess(formalchessx,formalchessy);
					quadrant=findnearest(&formalchessx,&formalchessy,0);
					repairmap(formalchessx,formalchessy,quadrant,chessname);
					ft.from=piece[chessname];
					ft.to=transform(mousex,mousey);
					ft.capture=board[ft.to];
					if (LegalMove(ft))
					{
					chessdraw(STARTX+2*mousex*WIDE,STARTY+2*mousey*WIDE,chessname);
					transformxy(chessname,&formalchessx,&formalchessy);
					steps[step_count].sx=formalchessx;
					steps[step_count].sy=formalchessy;
					steps[step_count].tx=mousex;
					steps[step_count].ty=mousey;
					step_count++;
					sound(262);
					delay(80);
					sound(523);
					delay(80);
					nosound();
					//piece[chessname]=ft.to;
					//board[ft.to]=chessname;
					//board[ft.from]=0;
					MakeMove(ft);
					chessname=0;
					formalchessx=0;
					formalchessy=0;

					ChangeSide();
					MoveNum=0;
					AllMove();
					if (MoveNum==0)
					{
						if (side==0)
					{
						setfillstyle(1,14);
						bar(500,430,610,455);
						dishz(525,435,23,4);
						dishz(575,435,34,4);
					}
					else
					{
						setfillstyle(1,14);
						bar(500,430,610,455);
						dishz(525,435,24,4);
						dishz(575,435,34,4);
					}
					}

					checkflag=CheckJu(side);
					if (checkflag)
					{
						if (side==1)
						{
							setfillstyle(1,14);
							bar(500,380,610,405);
							dishz(516,385,23,4);
							dishz(532,385,25,4);
							dishz(548,385,30,4);
							dishz(564,385,31,4);
							dishz(580,385,32,4);
						}
						else
						{
							
							setfillstyle(1,14);
							bar(500,380,610,405);
							dishz(516,385,24,4);
							dishz(532,385,25,4);
							dishz(548,385,30,4);
							dishz(564,385,31,4);
							dishz(580,385,32,4);
						}
					}
					else
					{
					setfillstyle(1,0);
					bar(499,379,611,406);
					}

					
						
					checkflag=Check(side);
					if (checkflag)
					{
						if (side==1)
						{	
							setfillstyle(1,14);
							bar(500,380,610,405);
							dishz(516,385,23,4);
							dishz(532,385,25,4);
							dishz(548,385,28,4);
							dishz(564,385,29,4);
							dishz(580,385,30,4);
						}
						else
						{
							setfillstyle(1,14);
							bar(500,380,610,405);
							dishz(516,385,24,4);
							dishz(532,385,25,4);
							dishz(548,385,28,4);
							dishz(564,385,29,4);
							dishz(580,385,30,4);
						}
					}
					/*else
					{
					setfillstyle(1,0);
					bar(499,379,611,406);
					}*/
					r.x.ax=1;
					int86x(0x33,&r,&r,&s);
					}
					else
					{
					r.x.ax=1;
					int86x(0x33,&r,&r,&s);
					continue;
					}
					mouseflag=0;
					continue;
				}
				if (mousekey==1&&mouseflag==0)
				{
					quadrant=findnearest(&mousex,&mousey,1);
					if (quadrant==0) continue;
					chessplace=transform(mousex,mousey);
					if (board[chessplace]==0)	continue;
					if (side==0&&(board[chessplace]>31)||side==1&&(board[chessplace]<32))
					{
						sound(523);
						delay(80);
						sound(262);
						delay(80);
						nosound();
						continue;
					}
					chessname=board[chessplace];
					//printf("%d\n",timer());
					mouseflag=1;
					formalchessx=STARTX+mousex*2*WIDE;
					formalchessy=STARTY+mousey*2*WIDE;
				}
			}
		
			else
			if (r.x.bx==1&&r.x.cx>=500&&r.x.cx<=610)
			{
				if (r.x.dx>=30&&r.x.dx<=55) 
				{
					setfillstyle(1,14);
					bar(500,330,610,355);
					dishz(520,335,24,4);
					dishz(540,335,25,4);
					dishz(560,335,26,4);
					dishz(580,335,27,4);
					setfillstyle(1,0);
					bar(490,370,630,470);
					StackTop=0;
					ClearBoard();
					Initchessmap();
					startgame();
				}
				if (r.x.dx>=80&&r.x.dx<=105) 
				{
				    if(StackTop>0)
					{
                    UnMakeMove();
					startgame();
					checkflag=CheckJu(side);
					if (checkflag)
					{
						if (side==1)
						{
							setfillstyle(1,14);
							bar(500,380,610,405);
							dishz(516,385,23,4);
							dishz(532,385,25,4);
							dishz(548,385,30,4);
							dishz(564,385,31,4);
							dishz(580,385,32,4);
						}
						else
						{
							
							setfillstyle(1,14);
							bar(500,380,610,405);
							dishz(516,385,24,4);
							dishz(532,385,25,4);
							dishz(548,385,30,4);
							dishz(564,385,31,4);
							dishz(580,385,32,4);
						}
					}
					else
					{
					setfillstyle(1,0);
					bar(499,379,611,406);
					}

					
						
					checkflag=Check(side);
					if (checkflag)
					{
						if (side==1)
						{	
							setfillstyle(1,14);
							bar(500,380,610,405);
							dishz(516,385,23,4);
							dishz(532,385,25,4);
							dishz(548,385,28,4);
							dishz(564,385,29,4);
							dishz(580,385,30,4);
						}
						else
						{
							setfillstyle(1,14);
							bar(500,380,610,405);
							dishz(516,385,24,4);
							dishz(532,385,25,4);
							dishz(548,385,28,4);
							dishz(564,385,29,4);
							dishz(580,385,30,4);
						}
					}
					}
  
                }
				if (r.x.dx>=130&&r.x.dx<=155) SAVE();
				if (r.x.dx>=180&&r.x.dx<=205) WATCH();
				if (r.x.dx>=230&&r.x.dx<=255)
				{
					if (side==0)
					{
						setfillstyle(1,14);
						bar(500,430,610,455);
						dishz(525,435,23,4);
						dishz(575,435,34,4);
					}
					else
					{
						setfillstyle(1,14);
						bar(500,430,610,455);
						dishz(525,435,24,4);
						dishz(575,435,34,4);
					}
				}
				if (r.x.dx>=280&&r.x.dx<=305) runninggame=0;
			}
		}
	}
}

