
#define TIMELIM 60
int step_count;
int turn;
int mtime;
int newx, newy;




/*储存*/
typedef int datatype;
#define maxsize 1000

typedef struct 
{
	int sx, sy;
	int tx, ty;
	int flag;
	int diedtx, diedty;
}node;                    /*flag==0时，没有吃子，flag!=0,吃子，diedtx,diedty表示被吃的棋子所放的位置*/

node steps[maxsize];
int top;






/*悔棋*/

void UnMakeMove(void)
{
    unsigned char from,dest,p;

    StackTop--;

    ChangeSide();

    from=MoveStack[StackTop].from;
    dest=MoveStack[StackTop].to;
    p=MoveStack[StackTop].capture;

    board[from]=board[dest];
    board[dest]=p;

    if(p>0)
        piece[p]=dest;
    piece[board[from]]=from;
}
    









void load_data()					/*载入存在硬盘中的棋盘save.dat*/
{
    FILE *fp;
    int i;
    if ((fp=fopen("save.dat", "r"))==NULL)			/*文件打开错误*/
    {
        printf("Error! Can't open savedata file!");
        return;
	}
    fscanf(fp, "%d", &step_count);					/*开始加载棋盘*/
    for (i=0; i<step_count; i++)
        fscanf(fp, "%d%d%d%d%d%d%d", &steps[i].sx, &steps[i].sy, &steps[i].tx, &steps[i].ty,&steps[i].flag,&steps[i].diedtx, &steps[i].diedty);
}


				/*SAVE*/
			   void  SAVE( )
				{
					int i;
					freopen("save.dat", "w+", stdout);
					printf("%d\n", step_count);
					for (i=0; i<step_count; i++)
						printf("%d %d %d %d %d %d %d ", steps[i].sx, steps[i].sy, steps[i].tx, steps[i].ty,steps[i].flag,steps[i].diedtx, steps[i].diedty); 
					
fclose(stdout);
                    
                    step_count=0;
				}
				
/*LOAD*/
		   void  LOAD(  )
				{   int i;
					load_data();
					StackTop=0;
					ClearBoard();
					Initchessmap();
					startgame();
					turn=1;
					for (i=0; i<step_count; i++)
					{
						movechess(steps[i].sx, steps[i].sy, steps[i].tx, steps[i].ty);
											
												}
					}

				

/*Watch*/
			void WATCH(  )
				{   int i;
					load_data("save.dat");
					StackTop=0;
					ClearBoard();
					Initchessmap();
					startgame();      /*初始化棋盘*/

					for (i=0; i<step_count; i++)
					{
						delay(3000);
						movechess(steps[i].sx, steps[i].sy, steps[i].tx, steps[i].ty);
					}
				}
				



int timer()
{
	struct time t, t1;
    char msg_time[10];
	gettime(&t1);
	do
	{
		gettime(&t);
		if (t1.ti_sec>t.ti_sec)
			t1.ti_sec=t.ti_sec;
		if (turn!=-1)
		{
			if(t.ti_sec-t1.ti_sec==1)
			{
				mtime-=1;
				sprintf(msg_time, "%d", mtime);
                                setcolor(6);
                                setlinestyle(0,1,3);
                                line(580,0,640,0);
                                line(580,3,640,3);
				line(580,6,640,6);				
				line(580,9,640,9);
    			line(580,12,640,12);
				line(580,15,640,15);
    			line(580,18,640,18);
    			line(580,21,640,21);
				setcolor(GREEN);
				outtextxy(600, 12, msg_time);
				/*drawtime(msg_time);*/
				t1.ti_sec=t.ti_sec;
				if(mtime==0)
				{
					
					mtime=TIMELIM;
					
					break;
				}

                       }
              }     
		}while (1);
            return 0;
      }