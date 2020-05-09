// yxsmdlg.cpp : implementation file
//

#include "stdafx.h"
#include "ÃÅ½ÝÁÐ·òµÄÄÆ.h"
#include "yxsmdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// yxsmdlg dialog


yxsmdlg::yxsmdlg(CWnd* pParent /*=NULL*/)
	: CDialog(yxsmdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(yxsmdlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void yxsmdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(yxsmdlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(yxsmdlg, CDialog)
	//{{AFX_MSG_MAP(yxsmdlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// yxsmdlg message handlers
