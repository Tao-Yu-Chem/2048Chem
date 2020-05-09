// 门捷列夫的钠Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "门捷列夫的钠.h"
#include "门捷列夫的钠Dlg.h"
#include "2048.cpp"
#include "yxsmdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define N 50

int success=0,maxscore=0,loadfromfile,LockedByDemo=0/*,nh3cn*/;
class2048 v;
class2048 arr[N];int p=0;
FILE *f;

int log2(int n)
{
	int z=0;
	if (n==0) return 0;
	while (n>>=1) z++;
	return z;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, v.score);
	DDX_Text(pDX, IDC_EDIT2, v.move);
	DDX_Text(pDX, IDC_EDIT3, maxscore);
	//{{AFX_DATA_MAP(CMyDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CHAR()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_UNDO, OnUndo)
	ON_BN_CLICKED(IDC_RESTART, OnReStart)
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_BUTTON1, Onyxsm)
	ON_BN_CLICKED(IDC_QUIT, OnQuit)
	ON_BN_CLICKED(IDC_REMOVEAMMONIA, OnRemoveAmmonia)
	ON_BN_CLICKED(IDC_REMOVECYAN, OnRemoveCyan)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers
void CMyDlg::setpict(int picn,int jbn)
{
	CStatic *p;
	p=(CStatic *)GetDlgItem(picn);
	if (p==NULL)
	{
		AHYMX("加载失败");
		return;
	}
	HBITMAP hBitmap=::LoadBitmap(
		AfxGetResourceHandle(),MAKEINTRESOURCE(jbn));
	p->ModifyStyle(0xF,SS_BITMAP|SS_CENTERIMAGE);  
	p->SetBitmap(hBitmap);   
}   

int ValueToIDB(int val)
{
	if (val==17) return IDB_BITMAP017;
	else if (val==52) return IDB_BITMAP052;
	else return IDB_BITMAP0+log2(val);
}

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	f=fopen("data.dat","rb");
	if (f==NULL) {f=fopen("data.dat","wb"); loadfromfile=0;}
	else
	{
		fread(&maxscore,sizeof(int),1,f);
		fread(&p,sizeof(int),1,f);
		int i;
		for(i=0;i<p;i++)
			arr[i].Fread(f);
		if (p>0) v=arr[p-1];
		loadfromfile=1;
	}
	fclose(f);
	if (v.Win()) success=1;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::PaintBitmap(int IDB,int x,int y,int width,int height) 
{
	CRect rc;
	//加载位图
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB);

	//选入DC
	CClientDC cdc(this); 
	CDC comdc;
	comdc.CreateCompatibleDC(&cdc);
	comdc.SelectObject(&bitmap);

	//生成BITMAP
	BITMAP bit;
	bitmap.GetBitmap(&bit);
	
	//用客户区的DC绘制所生成的BITMAP，并适应为窗口大小
	//cdc.StretchBlt(0,0,rc.Width(),rc.Height(),&comdc,0,0,bit.bmWidth,bit.bmHeight,SRCCOPY);
	cdc.StretchBlt(x,y,width,height,&comdc,0,0,bit.bmWidth,bit.bmHeight,SRCCOPY);
}

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		display();

		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CMyDlg::PreTranslateMessage(MSG* pMsg)
{
	SendMessage(pMsg->message,pMsg->wParam,pMsg->lParam);
	return 0;
}

void CMyDlg::display() 
{
	if (v.score>maxscore) maxscore=v.score;
	UpdateData(0);
	int i,j,x,y,idb;

	PaintBitmap(IDB_BITMAP_BG,80,100,406,406);
	for(i=0;i<=3;i++)
	for(j=0;j<=3;j++)
	{
		if (v.code[i][j]==0) continue;
		x=80+j*102; y=100+i*102;
		idb=ValueToIDB(v.code[i][j]);
	
		PaintBitmap(idb,x,y,100,100);
	}
}

void CMyDlg::ShowDemo(int *StartEndList=NULL) 
{
	// 每个图片移动到相邻的格子要移动69像素，可以每次移动3像素；移动n格的话每次移动3n像素。一共移动23次，每次移动后暂停20ms
	CRect posi; 
	int i,j,a,b,c,x,y,idb;
	int oldx,oldy,newx,newy;
	CString cs,tmp;

	//放动画时锁上各按钮和键盘消息
	LockedByDemo=1;
	GetDlgItem(IDC_QUIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_START)->EnableWindow(FALSE);
	GetDlgItem(IDC_UNDO)->EnableWindow(FALSE);
	GetDlgItem(IDC_RESTART)->EnableWindow(FALSE);
	GetDlgItem(IDC_REMOVECYAN)->EnableWindow(FALSE);
	GetDlgItem(IDC_REMOVEAMMONIA)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);

	//cs="269, StartEndList= ";
	//for (i=0;i<10;i++) {tmp.Format("%d ",StartEndList[i]); cs+=tmp;}
	//AHYMX(cs);

	for(a=1;a<=17;a++)
	{
		//AHYMX("271");
		PaintBitmap(IDB_BITMAP_BG,80,100,406,406);
		for (i=0;StartEndList[i]!=-1;i+=2)
		{
			oldx=StartEndList[i]/4;			oldy=StartEndList[i]%4;
			newx=StartEndList[i+1]/4;		newy=StartEndList[i+1]%4;
			x=oldy*102+80+6*(newy-oldy)*a;	y=oldx*102+100+6*(newx-oldx)*a;
			idb=ValueToIDB(arr[p-1].code[oldx][oldy]);
			//cs.Format("oldx=%d,oldy=%d,newx=%d,newy=%d",oldx,oldy,newx,newy);
			//AHYMX(cs);
			PaintBitmap(idb,x,y,100,100);
		}
		Sleep(16);
	}

	//放完动画时解锁各按钮和键盘消息
	GetDlgItem(IDC_QUIT)->EnableWindow(TRUE);
	GetDlgItem(IDC_START)->EnableWindow(TRUE);
	GetDlgItem(IDC_UNDO)->EnableWindow(TRUE);
	GetDlgItem(IDC_RESTART)->EnableWindow(TRUE);
	GetDlgItem(IDC_REMOVECYAN)->EnableWindow(TRUE);
	GetDlgItem(IDC_REMOVEAMMONIA)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	LockedByDemo=0;

	display();
}

void CMyDlg::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	//AHYMX("317");
	if (nChar==',') {OnRemoveCyan();	CDialog::OnChar(nChar, nRepCnt, nFlags); return;}
	if (nChar=='.') {OnRemoveAmmonia();	CDialog::OnChar(nChar, nRepCnt, nFlags); return;}
	if (nChar=='=') {OnQuit();			CDialog::OnChar(nChar, nRepCnt, nFlags); return;}
	if (LockedByDemo)	{	AHYMX("LockedByDemo");	CDialog::OnChar(nChar, nRepCnt, nFlags); return;}

	int StartEndList[40];
	if (v.Move(nChar,StartEndList)==0) return;	//没有移动，返回
	ShowDemo(StartEndList);
	v.AddTo();	//加入新的氢、氦，有时加入氰或者氨
	if (v.score>maxscore) maxscore=v.score;
	display();
	Save();
	if (p==N) //达到悔棋队列最大数目
	{
		for(p=0;p<N-1;p++)
			arr[p]=arr[p+1];
		arr[N-1]=v;
		p=N;
	}
	else
	{
		arr[p]=v;
		p++;
	}
	if (v.Win() && !success)
	{
		Beep(500,50);
		Beep(500,50);
		Beep(600,50);
		Beep(700,80);
		Beep(600,50);
		success=1;
		if (HYMX("成功合成钠！是否继续？","成功",MB_YESNO)==IDNO)
			PostQuitMessage(0);
	}

	/*if (v.Gameover())
	{
		Beep(500,50);
		Beep(400,50);
		Beep(300,50);
		if (HYMX("GAME OVER !!!!\r\n堵死了！\r\n是否重来？","GAME OVER",MB_YESNO)==IDNO)
			PostQuitMessage(0);
		else OnReStart(),success=0;
	}*/

	CDialog::OnChar(nChar, nRepCnt, nFlags);
}

void CMyDlg::Save() 
{
	f=fopen("data.dat","wb");
	if (f!=NULL) 
	{
		fwrite(&maxscore,sizeof(int),1,f);
		fwrite(&p,sizeof(int),1,f);
		int i;
		for(i=0;i<p;i++)
			arr[i].Fwrite(f);
	}
	fclose(f);
}

void CMyDlg::OnStart() 
{
	if (!loadfromfile) OnReStart();
	else display();
}

void CMyDlg::OnUndo() 
{
	if (p>1) p--,v=arr[p-1];
	display();
	Save();
}
/*
void CMyDlg::OnQuit() 
{
	Save();
}
*/
BOOL CMyDlg::DestroyWindow() 
{
	Save();
	return CDialog::DestroyWindow();
}


void CMyDlg::OnReStart() 
{
	//if (LockedByDemo) {return;}
	int i;
	for(i=0;i<N;i++)
		arr[i].clr();
	p=0;
	v.clr();
	v.AddTo();
	display();
	//GetDlgItem(IDC_BUTTON1)->EnableWindow(0);
}

void CMyDlg::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	CRect posi;
	//CString cs;
	int i,x,y;
	for (i=0;i<16;i++)
	{
		GetDlgItem(IDC_STATIC1+i)->GetWindowRect(&posi);
		ScreenToClient(&posi);
		if (posi.PtInRect(point))
		{
			//cs.Format("OnLButtonDblClk %d",i);
			//AHYMX(cs);
			x=i/4; y=i%4;
			if (v.code[x][y]==17)
			{
				v.score+=170;
				v.code[x][y]=0;
			}
			if (v.code[x][y]==52)
			{
				v.score+=520;
				v.code[x][y]=0;
			}
			display();
			break;
		}
	}
	Save();
	if (p==N)
	{
		for(p=0;p<N-1;p++)
			arr[p]=arr[p+1];
		arr[N-1]=v;
		p=N;
	}
	else
	{
		arr[p]=v;
		p++;
	}

	CDialog::OnLButtonDblClk(nFlags, point);
}

void CMyDlg::Onyxsm() 
{
	yxsmdlg dlg;
	dlg.DoModal();
}

void CMyDlg::OnQuit() 
{
	PostQuitMessage(0);
}

void CMyDlg::OnRemoveAmmonia() 
{
	int x,y;
	for (x=0;x<4;x++) for (y=0;y<4;y++)
	{
		if (v.code[x][y]==17)
		{
			v.score+=170;
			v.code[x][y]=0;
		}
	}
	display();
	Save();
	//ShowDemo();		// This is a debug line and should be removed after debug completed
}

void CMyDlg::OnRemoveCyan() 
{
	int x,y;
	for (x=0;x<4;x++) for (y=0;y<4;y++)
	{
		if (v.code[x][y]==52)
		{
			v.score+=520;
			v.code[x][y]=0;
		}
	}
	display();
	Save();
}
