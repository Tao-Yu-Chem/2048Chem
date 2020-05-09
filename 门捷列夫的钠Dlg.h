// ÃÅ½ÝÁÐ·òµÄÄÆDlg.h : header file
//

#if !defined(AFX_DLG_H__3D0F34C1_1817_4E42_BCFA_FA86BBB00746__INCLUDED_)
#define AFX_DLG_H__3D0F34C1_1817_4E42_BCFA_FA86BBB00746__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	void setpict(int picn,int jbn);
	void display() ;
	void ShowDemo(int*);
	BOOL PreTranslateMessage(MSG* pMsg);
	void Save() ;
	void PaintBitmap(int IDB,int x,int y,int width,int height);
	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnStart();
	afx_msg void OnUndo();
	afx_msg void OnReStart();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void Onyxsm();
	afx_msg void OnQuit();
	afx_msg void OnRemoveAmmonia();
	afx_msg void OnRemoveCyan();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__3D0F34C1_1817_4E42_BCFA_FA86BBB00746__INCLUDED_)
