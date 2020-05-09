/*2048*/
#include<mystyle.h>


class class2048
{
public:
	int code[4][4];	//16������
	int temp[5];	//�м����
	int move;	//�ƶ�����
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

	int add(int *StartEndList=NULL)		//���м����������д���
	{
		int i,j,p,t=0,change=0,bottom=-1;	
		//bottom���󣨲�������Ԫ�أ���Ϊ��ͨ���ϲ��������ɵģ����ܺͱ��Ԫ�غϲ���֮���Ԫ���������ƶ���temp[bottom]�������������ˡ�
		// change �ж������Ƿ��иı䣬0���䣬1�仯��
		CString cs,tmp;

		//AHYMX("037");
		if (StartEndList)
			for(p=0;StartEndList[p]!=-1;p++);
		i=0;
		if (StartEndList)
		{	//û�б仯��Ԫ��Ҳ����StartEndList
			StartEndList[p]=i;
			StartEndList[p+1]=i;
			p+=2;
		}

		for (i=1;i<4;i++)
		if (temp[i])
		{
			if (temp[i]==temp[i-1] && temp[i]!=17 && temp[i]!=52)
			{	//������ͬ��Ԫ�أ����ǰ����裩����Ҫ�ϲ�
				if (StartEndList)
				{
					StartEndList[p]=i;
					StartEndList[p+1]=i-1;
					p+=2;
				}
				score+=(temp[i]*2);	//�ӷ�
				temp[i-1]*=2;
				temp[i]=0;
				change=1;
				bottom=i;
			}
			else if (temp[i-1]==0)
			{
				for(j=i-1;temp[j]==0 && j>=0;j--);	//j��������ߵķ�0��Ԫ�أ�Ҳ������-1
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
					{	//������ͬ��Ԫ�أ���Ҫ�ϲ�
						if (StartEndList)
						{
							StartEndList[p]=i;
							StartEndList[p+1]=j;
							p+=2;
						}
						score+=(temp[i]*2);	//�ӷ�
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
				{	//û�б仯��Ԫ��Ҳ����StartEndList
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
		int LineList[25]; //֮ǰ������Ϊ20��������Խ��
		//CString cs;
		//���i(0<=i<=15)��ͼƬ��Ӧclass2048::code[x][y]������x=i/4,y=i%4����������i=x*4+y���μ�CMyDlg::OnLButtonDblClk�ĺ����塣
		switch(input)
		{				//	******��ǰdebug���ȣ�������(W/S)��ʱ��ᷢ����ѭ������������(A/D)��ʱ�򲻻ᣬԭ����******
			case 'W':
			case 'w':	//��
				for(j=0;j<=3;j++)
				{
					memset(LineList,-1,20*sizeof(int));	//ÿ����һ�л�һ�У������һ��LineList����p��StartEndList�������
					//cs.Format("188,i=%d,j=%d",i,j);
					//AHYMX(cs);
					for(i=0;i<=3;i++)
					{
						temp[i]=code[i][j];	//��һ�����Ƶ��м����
					}
					temp[4]=0;
					change=change+add(LineList);
					for(i=0;i<=3;i++)
					{
						code[i][j]=temp[i];	//�Ѵ���õ��м�����ƻ���
					}
					for(i=0;LineList[i]!=-1;i++)
					{
						StartEndList[p++]=LineList[i]*4+j;	//��code[LineList[i]][j]����
					}
					//AHYMX("203");
				}
				break;

			case 'A':
			case 'a':	//��
				for(i=0;i<=3;i++)
				{
					memset(LineList,-1,20*sizeof(int));
					for(j=0;j<=3;j++)
					{
						temp[j]=code[i][j];	//��һ�����Ƶ��м����
					}
					temp[4]=0;
					change=change+add(LineList);
					for(j=0;j<=3;j++)
					{
						code[i][j]=temp[j];	//�Ѵ���õ��м�����ƻ���
					}
					for(j=0;LineList[j]!=-1;j++)
					{
						StartEndList[p++]=4*i+LineList[j];	//��code[j][LineList[i]]����
					}
				}

				break;

			case 'S':
			case 's':	//��
				for(j=0;j<=3;j++)
				{
					memset(LineList,-1,20*sizeof(int));
					for(i=0;i<=3;i++)
					{
						temp[i]=code[3-i][j];	//��һ�����Ƶ��м����
					}
					temp[4]=0;
					change=change+add(LineList);
					for(i=0;i<=3;i++)
					{
						code[3-i][j]=temp[i];	//�Ѵ���õ��м�����ƻ���
					}
					for(i=0;LineList[i]!=-1;i++)
					{
						StartEndList[p++]=(3-LineList[i])*4+j;	//��code[3-LineList[i]][j]����
					}
				}
				break;

			case 'D':
			case 'd':	//��
				for(i=0;i<=3;i++)
				{
					memset(LineList,-1,20*sizeof(int));
					for(j=0;j<=3;j++)
					{
						temp[j]=code[i][3-j];	//��һ�����Ƶ��м����
					}
					temp[4]=0;
					change=change+add(LineList);
					for(j=0;j<=3;j++)
					{
						code[i][3-j]=temp[j];	//�Ѵ���õ��м�����ƻ���
					}
					for(j=0;LineList[j]!=-1;j++)
					{
						StartEndList[p++]=4*i+3-LineList[j];	//��code[j][3-LineList[i]]����
					}
				}
				break;
		}
		return change;
	}

	/*
	int Gameover()//�ж���Ϸ�Ƿ������1������0����
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

