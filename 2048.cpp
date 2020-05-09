/*2048*/
#include<mystyle.h>


class class2048
{
public:
	int code[4][4];	//16个格子
	int temp[5];	//中间变量
	int move;	//移动次数
	int score;

	class2048::class2048()
	{
		MEMCLR(code);
		MEMCLR(temp);
		move=0;
		score=0;
	}

	class2048 operator =(class2048 b)
	{
		int i,j;
		for(i=0;i<=3;i++)
		for(j=0;j<=3;j++)
			code[i][j]=b.code[i][j];
		move=b.move;
		score=b.score;
		return b;
	}

	int add(int *StartEndList=NULL)		//对中间变量数组进行处理
	{
		int i,j,p,t=0,change=0,bottom=-1;	
		//bottom以左（不含）的元素（因为是通过合并而新生成的）不能和别的元素合并。之后的元素最多可以移动到temp[bottom]，不能再往左了。
		// change 判断数组是否有改变，0不变，1变化；
		CString cs,tmp;

		//AHYMX("037");
		if (StartEndList)
			for(p=0;StartEndList[p]!=-1;p++);
		i=0;
		if (StartEndList)
		{	//没有变化的元素也加入StartEndList
			StartEndList[p]=i;
			StartEndList[p+1]=i;
			p+=2;
		}

		for (i=1;i<4;i++)
		if (temp[i])
		{
			if (temp[i]==temp[i-1] && temp[i]!=17 && temp[i]!=52)
			{	//两个相同的元素（不是氨、氰），需要合并
				if (StartEndList)
				{
					StartEndList[p]=i;
					StartEndList[p+1]=i-1;
					p+=2;
				}
				score+=(temp[i]*2);	//加分
				temp[i-1]*=2;
				temp[i]=0;
				change=1;
				bottom=i;
			}
			else if (temp[i-1]==0)
			{
				for(j=i-1;temp[j]==0 && j>=0;j--);	//j到达最左边的非0的元素，也可能是-1
				if (j==-1)
				{
					if (StartEndList)
					{
						StartEndList[p]=i;
						StartEndList[p+1]=0;
						p+=2;
					}
					temp[0]=temp[i];
					temp[i]=0;
					bottom=0;
					change=1;
				}
				else 
				{
					if (temp[i]==temp[j] && j>=bottom && temp[i]!=17 && temp[i]!=52)
					{	//两个相同的元素，需要合并
						if (StartEndList)
						{
							StartEndList[p]=i;
							StartEndList[p+1]=j;
							p+=2;
						}
						score+=(temp[i]*2);	//加分
						temp[j]*=2;
						temp[i]=0;
					}
					else
					{
						if (StartEndList)
						{
							StartEndList[p]=i;
							StartEndList[p+1]=j+1;
							p+=2;
						}
						temp[j+1]=temp[i];
						temp[i]=0;
					}
					bottom=j+1;
					change=1;
				}
			}
			else // to line 60
			{
				if (StartEndList)
				{	//没有变化的元素也加入StartEndList
					StartEndList[p]=i;
					StartEndList[p+1]=i;
					p+=2;
				}
			}
		}
		//cs="111, StartEndList= ";
		//for (i=0;i<10;i++) {tmp.Format("%d ",StartEndList[i]); cs+=tmp;}
		//AHYMX(cs);
		return change;
	}

	void AddTo()
	{
		int i,j,n=0,k;
		for(i=0;i<=3;i++)
		for(j=0;j<=3;j++)
		if (code[i][j]==0) n++;	//count the empties
		k=random(1,n);
		n=0;
		for(i=0;i<=3;i++)
		for(j=0;j<=3;j++)
		{
			if (code[i][j]==0) n++;
			if (n==k) goto out;	//choose an empty
		}
out:
		/*
		do
		{
			i=random(0,3);
			j=random(0,3);
		}while(code[i][j]!=0);
		*/

		move++;
		switch (random(0,50))
		{
		case 0:
			code[i][j]=17;
			break;
		case 1:
			code[i][j]=52;
			break;
		default:
			if(random(0,3)==0)
			{
				code[i][j]=4;
			}
			else
			{
				code[i][j]=2;
			}
		}
	}

	int Move(char input,int *StartEndList=NULL)
	{
		int change=0;
		int i,j,p=0;
		if (StartEndList) memset(StartEndList,-1,35*sizeof(int));
		int LineList[25]; //之前这里设为20，导致了越界
		//CString cs;
		//编号i(0<=i<=15)的图片对应class2048::code[x][y]，其中x=i/4,y=i%4。反过来，i=x*4+y。参见CMyDlg::OnLButtonDblClk的函数体。
		switch(input)
		{				//	******当前debug进度：按上下(W/S)的时候会发生死循环，但按左右(A/D)的时候不会，原因不明******
			case 'W':
			case 'w':	//上
				for(j=0;j<=3;j++)
				{
					memset(LineList,-1,20*sizeof(int));	//每处理一行或一列，先清空一下LineList，但p和StartEndList不能清空
					//cs.Format("188,i=%d,j=%d",i,j);
					//AHYMX(cs);
					for(i=0;i<=3;i++)
					{
						temp[i]=code[i][j];	//把一列数移到中间变量
					}
					temp[4]=0;
					change=change+add(LineList);
					for(i=0;i<=3;i++)
					{
						code[i][j]=temp[i];	//把处理好的中间变量移回来
					}
					for(i=0;LineList[i]!=-1;i++)
					{
						StartEndList[p++]=LineList[i]*4+j;	//将code[LineList[i]][j]记入
					}
					//AHYMX("203");
				}
				break;

			case 'A':
			case 'a':	//左
				for(i=0;i<=3;i++)
				{
					memset(LineList,-1,20*sizeof(int));
					for(j=0;j<=3;j++)
					{
						temp[j]=code[i][j];	//把一行数移到中间变量
					}
					temp[4]=0;
					change=change+add(LineList);
					for(j=0;j<=3;j++)
					{
						code[i][j]=temp[j];	//把处理好的中间变量移回来
					}
					for(j=0;LineList[j]!=-1;j++)
					{
						StartEndList[p++]=4*i+LineList[j];	//将code[j][LineList[i]]记入
					}
				}

				break;

			case 'S':
			case 's':	//下
				for(j=0;j<=3;j++)
				{
					memset(LineList,-1,20*sizeof(int));
					for(i=0;i<=3;i++)
					{
						temp[i]=code[3-i][j];	//把一列数移到中间变量
					}
					temp[4]=0;
					change=change+add(LineList);
					for(i=0;i<=3;i++)
					{
						code[3-i][j]=temp[i];	//把处理好的中间变量移回来
					}
					for(i=0;LineList[i]!=-1;i++)
					{
						StartEndList[p++]=(3-LineList[i])*4+j;	//将code[3-LineList[i]][j]记入
					}
				}
				break;

			case 'D':
			case 'd':	//右
				for(i=0;i<=3;i++)
				{
					memset(LineList,-1,20*sizeof(int));
					for(j=0;j<=3;j++)
					{
						temp[j]=code[i][3-j];	//把一行数移到中间变量
					}
					temp[4]=0;
					change=change+add(LineList);
					for(j=0;j<=3;j++)
					{
						code[i][3-j]=temp[j];	//把处理好的中间变量移回来
					}
					for(j=0;LineList[j]!=-1;j++)
					{
						StartEndList[p++]=4*i+3-LineList[j];	//将code[j][3-LineList[i]]记入
					}
				}
				break;
		}
		return change;
	}

	/*
	int Gameover()//判断游戏是否结束，1结束，0继续
	{
		int i,j;
		for(i=0;i<=3;i++)
		for(j=0;j<=3;j++)
		{
			if (code[i][j]==0)
				return 0;
			if (i<3 && code[i][j]==code[i+1][j])
				return 0;
			if (j<3 && code[i][j]==code[i][j+1])
				return 0;
		}
		return 1;
	}
	*/

	int Win()
	{
		int win;
		int i,j;
		win=0;
		for(i=0;i<=3;i++)
			for(j=0;j<=3;j++)
				if(code[i][j]>=2048)
					win=1;

		return win;
	}

	void clr()
	{
		MEMCLR(code);
		score=move=0;
	}

	//file operations
	void Fread(FILE *f)
	{
		fread(code,sizeof(code),1,f);
		fread(&score,sizeof(int),1,f);
		fread(&move,sizeof(int),1,f);
	}

	void Fwrite(FILE *f)
	{
		fwrite(code,sizeof(code),1,f);
		fwrite(&score,sizeof(int),1,f);
		fwrite(&move,sizeof(int),1,f);
	}


};

