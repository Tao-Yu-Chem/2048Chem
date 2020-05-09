#if !defined(AFX_YXSMDLG_H__BAA6190E_7C7C_41FF_B262_FF63995BB47B__INCLUDED_)
#define AFX_YXSMDLG_H__BAA6190E_7C7C_41FF_B262_FF63995BB47B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// yxsmdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// yxsmdlg dialog

class yxsmdlg : public CDialog
{
// Construction
public:
	yxsmdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(yxsmdlg)
	enum { IDD = IDD_YXSM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(yxsmdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(yxsmdlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YXSMDLG_H__BAA6190E_7C7C_41FF_B262_FF63995BB47B__INCLUDED_)
