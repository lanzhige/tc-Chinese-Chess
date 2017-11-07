#define RED_SHUAI 16
#define RED_SHI1 17
#define RED_SHI2 18
#define RED_XIANG1 19
#define RED_XIANG2 20
#define RED_MA1 21
#define RED_MA2 22
#define RED_JU1 23
#define RED_JU2 24
#define RED_PAO1 25
#define RED_PAO2 26
#define RED_BIN1 27
#define RED_BIN2 28
#define RED_BIN3 29
#define RED_BIN4 30
#define RED_BIN5 31

#define BLACK_JIANG 32
#define BLACK_SHI1 33
#define BLACK_SHI2 34
#define BLACK_XIANG1 35
#define BLACK_XIANG2 36
#define BLACK_MA1 37
#define BLACK_MA2 38
#define BLACK_JU1 39
#define BLACK_JU2 40
#define BLACK_PAO1 41
#define BLACK_PAO2 42
#define BLACK_ZU1 43
#define BLACK_ZU2 44
#define BLACK_ZU3 45
#define BLACK_ZU4 46
#define BLACK_ZU5 47         /*   红方棋子&16=1      黑方棋子&32=1         */

			      /*   side为0或1   Sidetag=side*16+16;   棋子&Sidetag==1   为本方棋子 */
int side;
char board[256]={
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 39,37,35,33,32,34,36,38,40,0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 41,0, 0, 0, 0, 0, 42,0, 0, 0, 0, 0,
    0, 0, 0, 43,0, 44,0, 45,0, 46,0, 47,0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 27,0, 28,0, 29,0, 30,0, 31,0, 0, 0, 0,
    0, 0, 0, 0, 25,0, 0, 0, 0, 0, 26,0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 23,21,19,17,16,18,20,22,24,0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};                                    
short piece[48];



                                                     	  /*  LegalPosition[k]!=0 则在棋盘上   */
                                                          /*  [51,59]    [67,75]   [83,91]   [99,107]   [115,123]  */
                                                          /*  [131,139]  [147,155] [163,171] [179,187]  [195,203] */





short LegalPosition[2][256]={
{   /*RED*/
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
    0, 0, 0, 9, 1, 25,1, 9, 1, 25,1, 9, 0, 0, 0, 0,
    0, 0, 0, 9, 1, 9, 1, 9, 1, 9, 1, 9, 0, 0, 0, 0,
    0, 0, 0, 17,1, 1, 7, 19,7, 1, 1, 17,0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 3, 7, 3, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 17,7, 3, 7, 17,1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    },
    {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 17,7, 3, 7, 17,1, 1, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 3, 7, 3, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 17,1, 1, 7, 19,7, 1, 1, 17,0, 0, 0, 0,
    0, 0, 0, 9, 1, 9, 1, 9, 1, 9, 1, 9, 0, 0, 0, 0,
    0, 0, 0, 9, 1, 25,1, 9, 1, 25,1, 9, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    }
};
short PositionMask[7]={2,4,16,1,1,1,8};   /*将、士、象、车、马、炮、卒*/
    

const char MaDir[8]={+0x0e, -0x12, -0x21, -0x1f, -0x0e, +0x12, +0x1f, +0x21};
const char MaCheck[8]={-0x01, -0x01, -0x10, -0x10, +0x01, +0x01, +0x10, +0x10};

const char KingDir[8]={-0x10, +0x01, +0x10, -0x01, 0, 0, 0, 0};

const char ShiDir[8]={-0x11, -0x0f, +0x11, +0x0f, 0, 0, 0, 0};

const char XiangDir[8]={-0x22, -0x1e, +0x22, +0x1e, 0, 0, 0 ,0};
const char XiangCheck[8]={-0x11, -0x0f, +0x11, +0x0f, 0, 0, 0, 0};

const char JuDir[8]={-0x01, -0x10, +0x01, +0x10, 0, 0, 0, 0};

const char PaoDir[8]={-0x01, -0x10, +0x01, +0x10, 0, 0, 0, 0};

const char BinDir[2][8]={{-0x01,+0x01,-0x10,0,0,0,0,0},{-0x01,+0x01,+0x10,0,0,0,0,0}};

void ClearBoard()
{
    int k;
    side=0;
    for (k=0;k<256;k++)
		board[k]=0;
	for(k=0;k<48;k++)
	piece[k]=0;
}






void Initchessmap()
{
	int k;
	for (k=0;k<256;k++)
		board[k]=0;

	board[51]=BLACK_JU1;
	board[52]=BLACK_MA1;
	board[53]=BLACK_XIANG1;
	board[54]=BLACK_SHI1;
	board[55]=BLACK_JIANG;
	board[56]=BLACK_SHI2;
	board[57]=BLACK_XIANG2;
	board[58]=BLACK_MA2;
	board[59]=BLACK_JU2;
	board[84]=BLACK_PAO1;
	board[90]=BLACK_PAO2;
	board[99]=BLACK_ZU1;
	board[101]=BLACK_ZU2;
	board[103]=BLACK_ZU3;
	board[105]=BLACK_ZU4;
	board[107]=BLACK_ZU5;

	board[195]=RED_JU1;
	board[196]=RED_MA1;
	board[197]=RED_XIANG1;
	board[198]=RED_SHI1;
	board[199]=RED_SHUAI;
	board[200]=RED_SHI2;
	board[201]=RED_XIANG2;
	board[202]=RED_MA2;
	board[203]=RED_JU2;
	board[164]=RED_PAO1;
	board[170]=RED_PAO2;
	board[147]=RED_BIN1;
	board[149]=RED_BIN2;
	board[151]=RED_BIN3;
	board[153]=RED_BIN4;
	board[155]=RED_BIN5;



	for (k=0;k<16;k++)
		piece[k]=0;

	piece[16]=199;
	piece[17]=198;
	piece[18]=200;
	piece[19]=197;
	piece[20]=201;
	piece[21]=196;
	piece[22]=202;
	piece[23]=195;
	piece[24]=203;
	piece[25]=164;
	piece[26]=170;
	piece[27]=147;
	piece[28]=149;
	piece[29]=151;
	piece[30]=153;
	piece[31]=155;

	piece[32]=55;
	piece[33]=54;
	piece[34]=56;
	piece[35]=53;
	piece[36]=57;
	piece[37]=52;
	piece[38]=58;
	piece[39]=51;
	piece[40]=59;
	piece[41]=84;
	piece[42]=90;
	piece[43]=99;
	piece[44]=101;
	piece[45]=103;
	piece[46]=105;
	piece[47]=107;
}



typedef struct{
	unsigned char from,to;
		unsigned char capture;
}move;
move Movearray[128];  /*走法数组*/
int MoveNum;          /*走法总数*/

move MoveStack[128];  /*走法栈*/

int StackTop;    /*等于0表示栈空*/


void InitGen()      /*清空走法*/
{
    MoveNum=0;
}

int SaveMove(unsigned char from, unsigned char to)   /*保存走法*/
{
    
	unsigned char p;
    int r;

    p=board[to];
	piece[board[from]]=to;
    if(p)
        piece[p]=0;
    board[to]=board[from];
    board[from]=0;

	r=Check(side);

    
    board[from]=board[to];
    board[to]=p;
	piece[board[from]]=from;
    if(p)
        piece[p]=to;

    if(!r)
    {
		Movearray[MoveNum].from = from;
		Movearray[MoveNum].to = to;
		MoveNum++;
        return 1;
    }
    return 0;
}


void MaMove(unsigned char p)
{
    int k;
    unsigned char n;     /*下一步可能行走的位置*/
    unsigned char m;     /*马腿位置*/
    int SideTag = 16+side*16;
    for (k=0;k<8;k++)
    {
        n=p+MaDir[k];
        if(LegalPosition[side][n]&PositionMask[3])
        {
            m=p+MaCheck[k];
            if(!board[m])
            {
                if(!(board[n]&SideTag))
                    SaveMove(p,n);
             }
         }
     }
}

void KingMove(unsigned char p)
{
    int k;
    unsigned char n;
    int SideTag=16+side*16;
    for(k=0;k<4;k++)
    {
        n=p+KingDir[k];
        if(LegalPosition[side][n]&PositionMask[0])
	{
            if(!(board[n]&SideTag))
		SaveMove(p,n);
	}
    }
}


void ShiMove(unsigned char p)
{
    int k;
    unsigned char n;
    int SideTag=16+side*16;
    for(k=0;k<4;k++)
    {
        n=p+ShiDir[k];
        if(LegalPosition[side][n]&PositionMask[1])
	{
            if(!(board[n]&SideTag))
		SaveMove(p,n);
	}
    }
}
	
void XiangMove(unsigned char p)
{
    int k;
    unsigned char n;     
    unsigned char m;     
    int SideTag = 16+side*16;
    for (k=0;k<4;k++)
    {
        n=p+XiangDir[k];
        if(LegalPosition[side][n]&PositionMask[2])
        {
            m=p+XiangCheck[k];
            if(!board[m])
            {
                if(!(board[n]&SideTag))
                    SaveMove(p,n);
             }
         }
     }
}

void JuMove(unsigned char p)
{
    int k,j;
    unsigned char n;
    int SideTag = 16+side*16;
    for (k=0;k<4;k++)
    {
        for (j=1;j<10;j++)
	{
	    n=p+j*JuDir[k];
	    if(!(LegalPosition[side][n]&PositionMask[4]))
		break;
	    if(!board[n])
		SaveMove(p,n);
	    else if(board[n]&SideTag)
		break;
	    else
            {
		SaveMove(p,n);
		break;
	    }
	}
    }
}

void PaoMove(unsigned char p)
{
    int k,j;
    unsigned char n;
    int SideTag = 16+side*16;
    int OverFlag;

    for (k=0;k<4;k++)
    {
	OverFlag=0;
        for (j=1;j<10;j++)
	{
	    n=p+j*PaoDir[k];
	    if(!(LegalPosition[side][n]&PositionMask[5]))
		break;
	    if(!board[n])
	    {
		if(!OverFlag)
		    SaveMove(p,n);
	    }
	    else
            {
                if(!OverFlag)
		    OverFlag=1;
		else
		{
		    if(!(board[n]&SideTag))
			SaveMove(p,n);
		    break;
		}
	    }
	}
    }
}


void BinMove(unsigned char p)
{
    int k;
    unsigned char n;
    int SideTag=16+side*16;
    for(k=0;k<3;k++)
    {
	n=p+BinDir[side][k];
	if(LegalPosition[side][n]&PositionMask[6])
	{
	    if(!(board[n]&SideTag))
		SaveMove(p,n);
	}
    }
}

void AllMove()
{
    short i;
    unsigned char p; /*棋子位置*/
    int SideTag;     /*走棋方*/
    int pc;          /*棋子*/
	
    SideTag=16+side*16;

    for(i=0;i<16;i++)
    {
	pc=SideTag+i;
	p=piece[pc];
	if(p==0)
	    continue;

	switch(i)
	{
	    case 0:
		KingMove(p);
		break;
            case 1:
	    case 2:
		ShiMove(p);
		break;
	    case 3:
	    case 4:
		XiangMove(p);
		break;
	    case 5:
	    case 6:
		MaMove(p);
		break;
	    case 7:
	    case 8:
		JuMove(p);
		break;
	    case 9:
	    case 10:
		PaoMove(p);
		break;
	    case 11:
	    case 12:
	    case 13:
	    case 14:
	    case 15:
		BinMove(p);
		break;
	    
	}
    }
}





int Check(int lSide)        /*检测lSide一方是否被将军，是被将军返回1，否则返回0*/
{
	unsigned char rKing,bKing;  /*双方将的位置*/
	unsigned char p,q;
	int r;                      /*r=1表示将军，否则为0*/
	int SideTag=32-lSide*16;    /*lSide对方的将的值*/
	int fSide=1-lSide;          /* 对方标志*/
	int i;
	int PosAdd;               /*位置增量*/

	int k;
	unsigned char n;
	unsigned char m;

	int OverFlag=0;


	rKing=piece[16];
	bKing=piece[32];
	if (!rKing  ||  !bKing)
		return 0;

	r=1;                                  /*将帅是否照面*/
	if(rKing%16 ==  bKing%16)
	{
	for(rKing=rKing-16;rKing!=bKing;rKing-=16)
	{
		if(board[rKing])
		{
		r=0;
		break;
		}
	}
	if(r)
		return r;   /*将帅照面*/
	}

	q=piece[48-SideTag];     /*lSide方将的位置*/

	for(i=5;i<6;i++)          /*检测是否被马攻击*/
	{
	p=piece[SideTag+i];
	if(!p)
		continue;
	for(k=0;k<8;k++)
	{
		n=p+MaDir[k];
		if(n!=q)
		continue;

		if(LegalPosition[fSide][n]&PositionMask[3])
		{
		m=p+MaCheck[k];
		if(!board[m])
		{
			return 1;
		}
		}
	}
	}

	r=1;
	for(i=7;i<=8;i++)              /*检测是否被车攻击*/
	{
	p=piece[SideTag+i];
	if (!p)
		continue;
	if(p%16==q%16)
	{
		PosAdd=(p>q? -16:16);
		for(p=p+PosAdd;p!=q;p+=PosAdd)
		{
		if(board[p])
		{
			r=0;
			break;
		}
		}
		if(r)
		return r;
	}
	else if(p/16==q/16)
	{
		PosAdd=(p>q? -1:1);
		for (p=p+PosAdd;p!=q;p+=PosAdd)
		{
		if(board[p])
		{
			r=0;
			break;
		}
		}
		if(r)
		return r;
	}
	}

	for (i=9;i<=10;i++)    /*检测是否被炮攻击*/
	{
	p=piece[SideTag+i];
	if(!p)
		continue;
	if(p%16==q%16)
	{
		PosAdd=(p>q?-16:16);
		for (p=p+PosAdd;p!=q;p+=PosAdd)
		{
		if(board[p])
		{
			if(!OverFlag)
			OverFlag=1;
			else
			{
			OverFlag=2;
			break;
			}
		}
		}
		if(OverFlag==1)
		return 1;
	}
	else if(p/16==q/16)
	{
		PosAdd=(p>q? -1:1);
		for(p=p+PosAdd;p!=q;p+=PosAdd)
		{
		if(board[p])
		{
			if(!OverFlag)
			OverFlag=1;
			else
			{
			OverFlag=2;
			break;
			}
		}
		}
		if(OverFlag==1)
		return 1;
	}
	}

	for(i=11;i<=15;i++)           /*检测是否被兵攻击*/
	{
	p=piece[SideTag+i];
	if(!p)
		continue;
	for(k=0;k<3;k++)
	{
		n=p+BinDir[fSide][k];
	    if((n==q) && (LegalPosition[fSide][n] & PositionMask[6]))
		return 1;
	}
    }
    return 0;
}




int CheckJu1(int lSide)        /*检测lSide一方是否将被吃车，是返回1，否则返回0*/
{
    unsigned char rJu1,bJu1;  /*双方车的位置*/
    unsigned char p,q;
    int r;                      /*r=1表示吃车，否则为0*/
    int SideTag=32-lSide*16;    /*lSide对方的将的值*/
    int fSide=1-lSide;          /* 对方标志*/
    int i,j;
    int PosAdd;               /*位置增量*/
    
    int k;
    unsigned char n;
    unsigned char m;

    int OverFlag=0;


    rJu1=piece[23];
  
    bJu1=piece[39];


    if (!rJu1   &&   !bJu1 )
        return 0;

    


    q=piece[48+7-SideTag];
                                /*lSide方车的位置*/

    for(i=5;i<6;i++)          /*检测是否被马攻击*/
    {
	p=piece[SideTag+i];
	if(!p)
	    continue;
	for(k=0;k<8;k++)
	{
	    n=p+MaDir[k];
  
	    if( n!=q )
		continue;

	    if(LegalPosition[fSide][n]&PositionMask[3])
	    {
		m=p+MaCheck[k];
		if(!board[m])
		{
		    return 1;
		}
	    }
	}
    }

    r=1;
    for(i=7;i<=8;i++)              /*检测是否被车攻击*/
    {
	p=piece[SideTag+i];
	if(!p)
	    continue;

     
           
	    if(p%16==q%16)
	    {
	        PosAdd=(p>q? -16:16);
	        for(p=p+PosAdd;p!=q;p+=PosAdd)
	        {
		    if(board[p])
		    {
		        r=0;
		        break;
		    }
	        }
	        if(r)
		    return r;
	    }
	    else if(p/16==q/16)
	    {
     
	        PosAdd=(p>q? -1:1);
	        for (p=p+PosAdd;p!=q;p+=PosAdd)
	        {
		    if(board[p])
		    {
		        r=0;
		        break;
		    }
	        }
	        if(r)
		    return r;
	    }      

    }



    for (i=9;i<=10;i++)    /*检测是否被炮攻击*/
    {
	p=piece[SideTag+i];
	if(!p)
	    continue;

     
	    if(p%16==q%16)
	    {
	        PosAdd=(p>q?-16:16);
	        for (p=p+PosAdd;p!=q;p+=PosAdd)
	        {
		    if(board[p])
		    {
		        if(!OverFlag)
			    OverFlag=1;
		        else
		        {
			    OverFlag=2;
			    break;
		        }
		    }
	        }
	        if(OverFlag==1)
		    return 1;
	    }
	    else if(p/16==q/16)
	    {
	        PosAdd=(p>q? -1:1);
	        for(p=p+PosAdd;p!=q;p+=PosAdd)
	        {
		    if(board[p])
		    {
		        if(!OverFlag)
			    OverFlag=1;
		        else
		        {
			    OverFlag=2;
			    break;
		        }
		    }
	        }
	        if(OverFlag==1)
		    return 1;
	    }
        

    }


    for(i=11;i<=15;i++)           /*检测是否被兵攻击*/
    {
	p=piece[SideTag+i];
	if(!p)
	    continue;
	for(k=0;k<3;k++)
	{
	    n=p+BinDir[fSide][k];
	    if((n==q ||  n==q) && (LegalPosition[fSide][n] & PositionMask[6]))
		return 1;
	}
    }


    for(i=1;i<=2;i++)               /*检测是否被士攻击*/
    {                     
        p=piece[SideTag+i];
	if(!p)
	    continue;

        for (k=0;k<4;k++)
        {  
            n=p+ShiDir[k];
            if(   (n==q)  &&  (LegalPosition[fSide][n]&PositionMask[1])  )
            {
                return 1;

             }
         }   
    }       

    for (i=3;i<=4;i++)              /*检测是否被象攻击*/
    {                     
        p=piece[SideTag+i];
	if(!p)
	    continue;

        for (k=0;k<4;k++)
        {  
            n=p+XiangDir[k];
            if( n!=q )
		continue;

            if(LegalPosition[fSide][n]&PositionMask[2])
	    {
		m=p+XiangCheck[k];
		if(!board[m])
		{
		    return 1;
		}
	    }
	}
    }
    return 0;


}
	



int CheckJu2(int lSide)        /*检测lSide一方是否将被吃车，是返回1，否则返回0*/
{
    unsigned char rJu2,bJu2;  /*双方车的位置*/
    unsigned char p,q;
    int r;                      /*r=1表示吃车，否则为0*/
    int SideTag=32-lSide*16;    /*lSide对方的将的值*/
    int fSide=1-lSide;          /* 对方标志*/
    int i,j;
    int PosAdd;               /*位置增量*/
    
    int k;
    unsigned char n;
    unsigned char m;

    int OverFlag=0;


    rJu2=piece[24];
  
    bJu2=piece[40];


    if (!rJu2   &&   !bJu2 )
        return 0;

    


    q=piece[48+8-SideTag];
                                /*lSide方车的位置*/

    for(i=5;i<6;i++)          /*检测是否被马攻击*/
    {
	p=piece[SideTag+i];
	if(!p)
	    continue;
	for(k=0;k<8;k++)
	{
	    n=p+MaDir[k];
  
	    if( n!=q )
		continue;

	    if(LegalPosition[fSide][n]&PositionMask[3])
	    {
		m=p+MaCheck[k];
		if(!board[m])
		{
		    return 1;
		}
	    }
	}
    }

    
    r=1;   
    for(i=7;i<=8;i++)              /*检测是否被车攻击*/
    {
	p=piece[SideTag+i];
	if(!p)
	    continue;

     
	    if(p%16==q%16)
	    {
	        PosAdd=(p>q? -16:16);
	        for(p=p+PosAdd;p!=q;p+=PosAdd)
	        {
		    if(board[p])
		    {
		        r=0;
		        break;
		    }
	        }
	        if(r)
		    return r;
	    }
	    else if(p/16==q/16)
	    {
     
	        PosAdd=(p>q? -1:1);
	        for (p=p+PosAdd;p!=q;p+=PosAdd)
	        {
		    if(board[p])
		    {
		        r=0;
		        break;
		    }
	        }
	        if(r)
		    return r;
	    }      

    }



    for (i=9;i<=10;i++)    /*检测是否被炮攻击*/
    {
	p=piece[SideTag+i];
	if(!p)
	    continue;

     
	    if(p%16==q%16)
	    {
	        PosAdd=(p>q?-16:16);
	        for (p=p+PosAdd;p!=q;p+=PosAdd)
	        {
		    if(board[p])
		    {
		        if(!OverFlag)
			    OverFlag=1;
		        else
		        {
			    OverFlag=2;
			    break;
		        }
		    }
	        }
	        if(OverFlag==1)
		    return 1;
	    }
	    else if(p/16==q/16)
	    {
	        PosAdd=(p>q? -1:1);
	        for(p=p+PosAdd;p!=q;p+=PosAdd)
	        {
		    if(board[p])
		    {
		        if(!OverFlag)
			    OverFlag=1;
		        else
		        {
			    OverFlag=2;
			    break;
		        }
		    }
	        }
	        if(OverFlag==1)
		    return 1;
	    }
        

    }


    for(i=11;i<=15;i++)           /*检测是否被兵攻击*/
    {
	p=piece[SideTag+i];
	if(!p)
	    continue;
	for(k=0;k<3;k++)
	{
	    n=p+BinDir[fSide][k];
	    if((n==q ||  n==q) && (LegalPosition[fSide][n] & PositionMask[6]))
		return 1;
	}
    }


    for(i=1;i<=2;i++)               /*检测是否被士攻击*/
    {                     
        p=piece[SideTag+i];
	if(!p)
	    continue;

        for (k=0;k<4;k++)
        {  
            n=p+ShiDir[k];
            if(   (n==q)  &&  (LegalPosition[fSide][n]&PositionMask[1])  )
            {
                return 1;

             }
         }   
    }       

    for (i=3;i<=4;i++)              /*检测是否被象攻击*/
    {                     
        p=piece[SideTag+i];
	if(!p)
	    continue;

        for (k=0;k<4;k++)
        {  
            n=p+XiangDir[k];
            if( n!=q )
		continue;

            if(LegalPosition[fSide][n]&PositionMask[2])
	    {
		m=p+XiangCheck[k];
		if(!board[m])
		{
		    return 1;
		}
	    }
	}
    }
    return 0;


}



int CheckJu(int lSide)  
{
    int a,b;
    a=CheckJu1(lSide);
    b=CheckJu2(lSide);
    if( a||b )
        return 1;
    else
        return 0;
}

int LegalMove(move mv)
{
	int i;
	InitGen();
	AllMove();

	for (i=0;i<MoveNum;i++)
	{
		if(mv.from==Movearray[i].from  &&  mv.to==Movearray[i].to)
			return 1;
	}
	return 0;
}



void ChangeSide()
{
	side=1-side;
	setfillstyle(1,14);
	if (side)
	{
		bar(500,330,610,355);
		dishz(520,335,23,4);
		dishz(540,335,25,4);
		dishz(560,335,26,4);
		dishz(580,335,27,4);
	}
	else
	{
		bar(500,330,610,355);
		dishz(520,335,24,4);
		dishz(540,335,25,4);
		dishz(560,335,26,4);
		dishz(580,335,27,4);
	}
}


void MakeMove(move m)
{
	unsigned char from,dest,p;
	//int SideTag=(side==0 ? 32:16);       /*对方将的值*/

	from=m.from;
	dest=m.to;

	MoveStack[StackTop].from=from;
	MoveStack[StackTop].to=dest;
	MoveStack[StackTop].capture=p=board[dest];
	StackTop++;

	if(p>0)
		piece[p]=0;

	piece[board[from]]=dest;
	board[dest]=board[from];
	board[from]=0;

	//ChangeSide();

	return;
}