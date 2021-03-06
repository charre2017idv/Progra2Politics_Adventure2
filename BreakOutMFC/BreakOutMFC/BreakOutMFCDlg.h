
// BreakOutMFCDlg.h : header file
//

#pragma once
#include "CBall.h"
#include "CBar.h"

// CBreakOutMFCDlg dialog
class CBreakOutMFCDlg : public CDialog
{
	// Construction
public:
	CBreakOutMFCDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BREAKOUTMFC_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	// Objects
	CBall Ball;
	CBar Bar;
	// Functions
	void fn_Ball();
	void fn_Bar(int x);
	void frame();
	POINT LeftStart, RightStart, onPoint;
	RECT rect;
	BITMAP Bitsize;
	int m_BallSizes;
	int m_BitBallWidth;
	int m_BitBallHeight;

	// SCORES
	int m_score = 3;
	CString m_scoreString;

	// MOUSE
	CString m_textoMouse_X;
	CString m_textoMouse_Y;
	int PositionX;

	// BAR
	int m_xWidth1;
	int m_xWidth2;

	// BALL
	int PosX = 0;
	int PosY = 0;
	int DirX = 5;
	int DirY = 5;

	// BAR
	int m_BPosX = 0;
	int m_BPosY = 0;
	int m_BDirX = 5;
	int m_BDirY = 5;

	// SCREEN
	int SWidth = 500;
	int SHeight = 300;
	bool click; 
	// FRAME
	int m_tiempo = 32;



	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
