
// BreakOutMFCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BreakOutMFC.h"
#include "BreakOutMFCDlg.h"
#include "afxdialogex.h"
#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBreakOutMFCDlg dialog



CBreakOutMFCDlg::CBreakOutMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_BREAKOUTMFC_DIALOG, pParent)
	, m_textoMouse_X(_T(""))
	, m_textoMouse_Y(_T(""))
	, m_scoreString(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBreakOutMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MOUSE_X, m_textoMouse_X);
	DDX_Text(pDX, IDC_MOUSE_Y, m_textoMouse_Y);
	DDX_Text(pDX, IDC_SCORE, m_scoreString);
}

BEGIN_MESSAGE_MAP(CBreakOutMFCDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDOK, &CBreakOutMFCDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CBreakOutMFCDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CBreakOutMFCDlg message handlers

BOOL CBreakOutMFCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBreakOutMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
		


	}
	else
	{
		// Limites de la ventana
		RECT miRect;
		GetClientRect(&miRect);

		frame();
		fn_Bar(PositionX);
		fn_Ball();

		
		//LeftStart.x = 0;
		//LeftStart.y = 0;
		//RightStart.x = 100;
		//RightStart.y = 15;
		//click = false;
		//SetTimer(1, 250, NULL);
		 // Se dibuja el rectangulo
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBreakOutMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CBreakOutMFCDlg::fn_Ball()
{
	// Se crea el archivo
	HANDLE hBitmap = LoadImage(0, TEXT("Dummie.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	CBitmap bmp;
	bmp.Attach(reinterpret_cast<HBITMAP>(hBitmap));
	CDC* pDC = this->GetDC();
	CDC bmDC;
	// Se crea un divice context compatible
	bmDC.CreateCompatibleDC(pDC);
	CBitmap* oldBMP = bmDC.SelectObject(&bmp);
	//CSize miSize = bmp.GetBitmapDimension();
	m_BallSizes = bmp.GetBitmap(&Bitsize);
	m_BitBallHeight = Bitsize.bmHeight;
	m_BitBallWidth = Bitsize.bmWidth;
	GetClientRect(&rect); // By RECT rect on .h
	Ball.m_bottom = rect.bottom;
	Ball.m_right = rect.right;
	//miSize.cx = 64;
	//miSize.cy = 64;

	// Se dibuja la bola
	pDC->BitBlt(Ball.PosX, Ball.PosY, m_BitBallWidth, m_BitBallHeight, &bmDC, 0, 0, SRCCOPY);
	Ball.fn_movment();
	//pDC->Ellipse(PosX, PosY, miSize.cx, miSize.cy);
	// Si el posY es 0 la dirY se mueve 5
	///* En el eje Y */
	//// Si posY es igual a 0 entonces la direccion sera 5
	//if (PosY <= 0)
	//{
	//	DirY = 5;
	//}
	//
	///* En el eje X */
	//if (PosX <= 0)
	//{
	//	DirX = 5;
	//}
	//if (PosX > rect.right - 64)
	//{
	//	DirX = -5;
	//}
	//
	//// Si la posy es mayor que el ancho, la direccion de Y sube
	//if (PosY > rect.bottom - 64)
	//{
	//	// Si la posY es mayor que el ancho de la pantalla
	//	PosY = 0;
	//	PosX = 0;
	//	m_score -= 1;
	//	m_scoreString = to_string(m_score).c_str();
	//	UpdateData(FALSE);
	//	MessageBeep(MB_OK); 
	//}
	//
	//if (m_score == 0)
	//{
	//	OnCancel();
	//}
	//

	//*COLLIDER BAR*/
	//if (Ball.PosY + 64 > Ball.m_bottom - 50)
	//{
	//	if (Ball.PosX + 32 > m_xWidth1 && Ball.PosX + 32 < m_xWidth2)
	//	{
	//		Ball.DirY = -5;
	//	}
	//}
	if (Ball.PosY + m_BitBallHeight > Ball.m_bottom - 50)
	{
		// Condiciones Mouse Middle
		if (Ball.PosX + m_BitBallHeight / 2 > Bar.m_xWidth1 && Ball.PosX + m_BitBallHeight / 2 < Bar.m_xWidth2) // m_BitBallHeight / 2 = 32
		{
			Ball.DirY = -5;
		}
	}
	//
	//PosX += DirX;
	//PosY = PosY + DirY;

}

void CBreakOutMFCDlg::fn_Bar(int x)
{
	CDC* pDC = this->GetDC();
	RECT rectBar;
	GetClientRect(&rectBar);
	Bar.m_leftSideBar = rectBar.left;
	Bar.m_rightSideBar = rectBar.right;
	Bar.m_bottomSideBar = rectBar.bottom;
	/// Value of X
	
	//m_xWidth1 = x - 50;
	//m_xWidth2 = x + 50;
	//// Stop in left
	//if (m_xWidth1 < rectBar.left)
	//{
	//	m_xWidth1 = rectBar.left;
	//	m_xWidth2 = m_xWidth1 + 100;
	//}
	//// Stop in right
	//else if (m_xWidth2 > rectBar.right)
	//{
	//	m_xWidth2 = rectBar.right;
	//	m_xWidth1 = m_xWidth2 - 100;
	//}
	// Paint a Rectangle with
	pDC->Rectangle(Bar.m_xWidth1, Bar.m_bottomSideBar - 20, Bar.m_xWidth2, Bar.m_bottomSideBar - 50);
	Bar.fn_movment(x);
}


void CBreakOutMFCDlg::frame()
{
	CDC* pDC = this->GetDC();
	RECT rectBarC;
	GetClientRect(&rectBarC);
	pDC->Rectangle(0, 0, rectBarC.right, rectBarC.bottom);
	
}
void CBreakOutMFCDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// Si se da click en el rectangulo
	if (point.x >= LeftStart.x && point.x <= RightStart.x && point.y >= LeftStart.y && point.y <= RightStart.y)
	{
		click = true;
		
		onPoint = point;
		
	}
	CDialog::OnLButtonDown(nFlags, point);
}

void CBreakOutMFCDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	//OnMouseMove( nFlags, point);
	PositionX = point.x;

	// TODO: Add your message handler code here and/or call default
	
		
	
	m_textoMouse_X = to_string(point.x).c_str();
	m_textoMouse_Y = to_string(point.y).c_str();
	UpdateData(FALSE);
	
	CDialog::OnMouseMove(nFlags, point);
}

void CBreakOutMFCDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	SetTimer(1, m_tiempo, NULL);
	//CDialog::OnOK();
}

void CBreakOutMFCDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	//MessageBeep(MB_OK);
	
	OnPaint();
	CDialog::OnTimer(nIDEvent);
}




void CBreakOutMFCDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	click = false;
	CDialog::OnLButtonUp(nFlags, point);
}




void CBreakOutMFCDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
