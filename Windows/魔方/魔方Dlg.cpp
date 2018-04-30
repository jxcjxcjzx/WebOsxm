// 魔方Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "魔方.h"
#include "魔方Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
	//{{AFX_DATA_MAP(CMyDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON13, OnButton13)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	ON_BN_CLICKED(IDC_BUTTON14, OnButton14)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnButton1() 
{
	CString daiti[12];
	daiti[1]=f[7];
    daiti[2]=f[4];
    daiti[3]=f[1];
	f[7]=b[3];
	f[4]=b[6];
	f[1]=b[9];
	b[3]=c[3];
	b[6]=c[6];
	b[9]=c[9];
	c[3]=a[3];
	c[6]=a[6];
	c[9]=a[9];
	a[3]=daiti[1];
    a[6]=daiti[2];
    a[9]=daiti[3];
	//单面左转
	daiti[4]=e[1];
	daiti[5]=e[2];
	daiti[6]=e[3];
	daiti[7]=e[4];
	daiti[8]=e[6];
	daiti[9]=e[7];
	daiti[10]=e[8];
	daiti[11]=e[9];
	e[1]=e[3];
	e[2]=e[6];
	e[3]=e[9];
	e[4]=daiti[5];
    e[6]=daiti[10];
	e[7]=daiti[4];
    e[8]=daiti[7];
    e[9]=daiti[9];

    xianshi();



	// TODO: Add your control notification handler code here
	
}
//初始化
void CMyDlg::OnButton13() 
{
	chushihua();
    xianshi();

	// TODO: Add your control notification handler code here
	
}

void CMyDlg::OnButton2() 
{
	CString daiti[12];
	daiti[1]=f[7];
    daiti[2]=f[4];
    daiti[3]=f[1];
	f[7]=a[3];
	f[4]=a[6];
	f[1]=a[9];
	a[3]=c[3];
	a[6]=c[6];
	a[9]=c[9];
	c[3]=b[3];
	c[6]=b[6];
	c[9]=b[9];
	b[3]=daiti[1];
    b[6]=daiti[2];
    b[9]=daiti[3];
	//单面右转
	daiti[4]=e[1];
	daiti[5]=e[2];
	daiti[6]=e[3];
	daiti[7]=e[4];
	daiti[8]=e[6];
	daiti[9]=e[7];
	daiti[10]=e[8];
	daiti[11]=e[9];
	e[3]=e[1];
	e[6]=e[2];
	e[9]=daiti[6];
	e[2]=daiti[7];
    e[8]=daiti[8];
	e[1]=daiti[9];
    e[4]=daiti[10];
    e[7]=daiti[11];
    
	xianshi();

	// TODO: Add your control notification handler code here
	
}
//左下
void CMyDlg::OnButton3() 
{
    CString daiti[12];
	daiti[1]=f[3];
	daiti[2]=f[6];
	daiti[3]=f[9];
    f[3]=b[7];
	f[6]=b[4];
	f[9]=b[1];
	b[1]=c[1];
	b[4]=c[4];
	b[7]=c[7];
	c[1]=a[1];
	c[4]=a[4];
	c[7]=a[7];
	a[1]=daiti[3];
	a[4]=daiti[2];
	a[7]=daiti[1];


    daiti[4]=d[1];
	daiti[5]=d[2];
	daiti[6]=d[3];
	daiti[7]=d[4];
	daiti[8]=d[6];
	daiti[9]=d[7];
	daiti[10]=d[8];
	daiti[11]=d[9];
	d[3]=d[1];
	d[6]=d[2];
	d[9]=daiti[6];
	d[2]=daiti[7];
    d[8]=daiti[8];
	d[1]=daiti[9];
    d[4]=daiti[10];
    d[7]=daiti[11];

	xianshi();
	// TODO: Add your control notification handler code here
	
}
//左上
void CMyDlg::OnButton4() 
{

	CString daiti[12];
	daiti[1]=f[3];
	daiti[2]=f[6];
	daiti[3]=f[9];
    f[3]=a[7];
	f[6]=a[4];
	f[9]=a[1];
	a[1]=c[1];
	a[4]=c[4];
	a[7]=c[7];
	c[1]=b[1];
	c[4]=b[4];
	c[7]=b[7];
	b[1]=daiti[3];
	b[4]=daiti[2];
	b[7]=daiti[1];
	daiti[4]=d[1];
	daiti[5]=d[2];
	daiti[6]=d[3];
	daiti[7]=d[4];
	daiti[8]=d[6];
	daiti[9]=d[7];
	daiti[10]=d[8];
	daiti[11]=d[9];
	d[1]=d[3];
	d[2]=d[6];
	d[3]=d[9];
	d[4]=daiti[5];
    d[6]=daiti[10];
	d[7]=daiti[4];
    d[8]=daiti[7];
    d[9]=daiti[9];

	xianshi();
	// TODO: Add your control notification handler code here
	
}
//前左
void CMyDlg::OnButton9() 
{    
	CString daiti[12];
    daiti[1]=a[7];
	daiti[2]=a[8];
	daiti[3]=a[9];
    a[7]=e[1];
	a[8]=e[4];
	a[9]=e[7];
	e[1]=b[3];
	e[4]=b[2];
	e[7]=b[1];
	b[1]=d[3];
	b[2]=d[6];
	b[3]=d[9];
	d[3]=daiti[3];
	d[6]=daiti[2];
	d[9]=daiti[1];
    daiti[4]=c[1];
	daiti[5]=c[2];
	daiti[6]=c[3];
	daiti[7]=c[4];
	daiti[8]=c[6];
	daiti[9]=c[7];
	daiti[10]=c[8];
	daiti[11]=c[9];
	c[1]=c[3];
	c[2]=c[6];
	c[3]=c[9];
	c[4]=daiti[5];
    c[6]=daiti[10];
	c[7]=daiti[4];
    c[8]=daiti[7];
    c[9]=daiti[9];

	xianshi();
	// TODO: Add your control notification handler code here
	
}
//前右
void CMyDlg::OnButton10() 
{
	CString daiti[12];
    daiti[1]=a[7];
	daiti[2]=a[8];
	daiti[3]=a[9];
	a[7]=d[9];
	a[8]=d[6];
	a[9]=d[3];
	d[9]=b[3];
	d[6]=b[2];
	d[3]=b[1];
	b[3]=e[1];
	b[2]=e[4];
	b[1]=e[7];
	e[1]=daiti[1];
	e[4]=daiti[2];
	e[7]=daiti[3];
	daiti[4]=c[1];
	daiti[5]=c[2];
	daiti[6]=c[3];
	daiti[7]=c[4];
	daiti[8]=c[6];
	daiti[9]=c[7];
	daiti[10]=c[8];
	daiti[11]=c[9];
	c[3]=c[1];
	c[6]=c[2];
	c[9]=daiti[6];
	c[2]=daiti[7];
    c[8]=daiti[8];
	c[1]=daiti[9];
    c[4]=daiti[10];
    c[7]=daiti[11];
    
	xianshi();

	// TODO: Add your control notification handler code here
	
}
//后左
void CMyDlg::OnButton5() 
{
	CString daiti[12];
    daiti[1]=a[1];
	daiti[2]=a[2];
	daiti[3]=a[3];
	a[3]=d[1];
	a[2]=d[4];
	a[1]=d[7];
	d[1]=b[7];
	d[4]=b[8];
	d[7]=b[9];
	b[7]=e[9];
	b[8]=e[6];
	b[9]=e[3];
	e[9]=daiti[3];
	e[6]=daiti[2];
	e[3]=daiti[1];

	daiti[4]=f[1];
	daiti[5]=f[2];
	daiti[6]=f[3];
	daiti[7]=f[4];
	daiti[8]=f[6];
	daiti[9]=f[7];
	daiti[10]=f[8];
	daiti[11]=f[9];
	f[1]=f[3];
	f[2]=f[6];
	f[3]=f[9];
	f[4]=daiti[5];
    f[6]=daiti[10];
	f[7]=daiti[4];
    f[8]=daiti[7];
    f[9]=daiti[9];

    xianshi();
	// TODO: Add your control notification handler code here
	
}
//后右
void CMyDlg::OnButton6() 
{
	CString daiti[12];
    daiti[1]=a[1];
	daiti[2]=a[2];
	daiti[3]=a[3];
	a[1]=e[3];
	a[2]=e[6];
	a[3]=e[9];
	e[3]=b[9];
	e[6]=b[8];
	e[9]=b[7];
	b[9]=d[7];
	b[8]=d[4];
	b[7]=d[1];
	d[7]=daiti[1];
	d[4]=daiti[2];
	d[1]=daiti[3];

	daiti[4]=f[1];
	daiti[5]=f[2];
	daiti[6]=f[3];
	daiti[7]=f[4];
	daiti[8]=f[6];
	daiti[9]=f[7];
	daiti[10]=f[8];
	daiti[11]=f[9];
	f[3]=f[1];
	f[6]=f[2];
	f[9]=daiti[6];
	f[2]=daiti[7];
    f[8]=daiti[8];
	f[1]=daiti[9];
    f[4]=daiti[10];
    f[7]=daiti[11];
    
	xianshi();

	// TODO: Add your control notification handler code here
	
}
//上左
void CMyDlg::OnButton7() 
{

	CString daiti[12];
    daiti[1]=c[1];
	daiti[2]=c[2];
	daiti[3]=c[3];
	c[1]=d[1];
	c[2]=d[2];
	c[3]=d[3];
	d[1]=f[1];
	d[2]=f[2];
	d[3]=f[3];
	f[1]=e[1];
	f[2]=e[2];
	f[3]=e[3];
	e[1]=daiti[1];
	e[2]=daiti[2];
	e[3]=daiti[3];
	daiti[4]=a[1];
	daiti[5]=a[2];
	daiti[6]=a[3];
	daiti[7]=a[4];
	daiti[8]=a[6];
	daiti[9]=a[7];
	daiti[10]=a[8];
	daiti[11]=a[9];
	a[1]=a[3];
	a[2]=a[6];
	a[3]=a[9];
	a[4]=daiti[5];
    a[6]=daiti[10];
	a[7]=daiti[4];
    a[8]=daiti[7];
    a[9]=daiti[9];

    xianshi();
	// TODO: Add your control notification handler code here
	
}
//上右
void CMyDlg::OnButton8() 
{
	CString daiti[12];
	daiti[1]=c[1];
	daiti[2]=c[2];
	daiti[3]=c[3];
	c[1]=e[1];
	c[2]=e[2];
	c[3]=e[3];
	e[1]=f[1];
	e[2]=f[2];
	e[3]=f[3];
	f[1]=d[1];
	f[2]=d[2];
	f[3]=d[3];
	d[1]=daiti[1];
	d[2]=daiti[2];
	d[3]=daiti[3];
	daiti[4]=a[1];
	daiti[5]=a[2];
	daiti[6]=a[3];
	daiti[7]=a[4];
	daiti[8]=a[6];
	daiti[9]=a[7];
	daiti[10]=a[8];
	daiti[11]=a[9];
	a[3]=a[1];
	a[6]=a[2];
	a[9]=daiti[6];
	a[2]=daiti[7];
    a[8]=daiti[8];
	a[1]=daiti[9];
    a[4]=daiti[10];
    a[7]=daiti[11];
    
	xianshi();

	// TODO: Add your control notification handler code here
	
}
//下左
void CMyDlg::OnButton11() 
{

	CString daiti[12];
    daiti[1]=c[7];
	daiti[2]=c[8];
	daiti[3]=c[9];
	c[7]=e[7];
	c[8]=e[8];
	c[9]=e[9];
	e[7]=f[7];
	e[8]=f[8];
	e[9]=f[9];
	f[7]=d[7];
	f[8]=d[8];
	f[9]=d[9];
	d[7]=daiti[1];
	d[8]=daiti[2];
	d[9]=daiti[3];
	daiti[4]=b[1];
	daiti[5]=b[2];
	daiti[6]=b[3];
	daiti[7]=b[4];
	daiti[8]=b[6];
	daiti[9]=b[7];
	daiti[10]=b[8];
	daiti[11]=b[9];
	b[1]=b[3];
	b[2]=b[6];
	b[3]=b[9];
	b[4]=daiti[5];
    b[6]=daiti[10];
	b[7]=daiti[4];
    b[8]=daiti[7];
    b[9]=daiti[9];

    xianshi();
	// TODO: Add your control notification handler code here
	
}
//下右
void CMyDlg::OnButton12() 
{
	CString daiti[12];
	daiti[1]=c[7];
	daiti[2]=c[8];
	daiti[3]=c[9];
    c[7]=d[7];
    c[8]=d[8];
    c[9]=d[9];
	d[7]=f[7];
    d[8]=f[8];
    d[9]=f[9];
    f[7]=e[7];
	f[8]=e[8];
	f[9]=e[9];
    e[7]=daiti[1];
	e[8]=daiti[2];
	e[9]=daiti[3];

    daiti[4]=b[1];
	daiti[5]=b[2];
	daiti[6]=b[3];
	daiti[7]=b[4];
	daiti[8]=b[6];
	daiti[9]=b[7];
	daiti[10]=b[8];
	daiti[11]=b[9];
	b[3]=b[1];
	b[6]=b[2];
	b[9]=daiti[6];
	b[2]=daiti[7];
    b[8]=daiti[8];
	b[1]=daiti[9];
    b[4]=daiti[10];
    b[7]=daiti[11];
    
	xianshi();

	// TODO: Add your control notification handler code here
	
}

void CMyDlg::OnButton14() 
{
	GetDlgItemText(IDC_a1,a[1]);
	GetDlgItemText(IDC_a2,a[2]);
	GetDlgItemText(IDC_a3,a[3]);
	GetDlgItemText(IDC_a4,a[4]);
	GetDlgItemText(IDC_a5,a[5]);
    GetDlgItemText(IDC_a6,a[6]);
	GetDlgItemText(IDC_a7,a[7]);
	GetDlgItemText(IDC_a8,a[8]);
	GetDlgItemText(IDC_a9,a[9]);
	GetDlgItemText(IDC_b1,b[1]);
	GetDlgItemText(IDC_b2,b[2]);
	GetDlgItemText(IDC_b3,b[3]);
	GetDlgItemText(IDC_b4,b[4]);
	GetDlgItemText(IDC_b5,b[5]);
    GetDlgItemText(IDC_b6,b[6]);
	GetDlgItemText(IDC_b7,b[7]);
	GetDlgItemText(IDC_b8,b[8]);
	GetDlgItemText(IDC_b9,b[9]);
	GetDlgItemText(IDC_c1,c[1]);
	GetDlgItemText(IDC_c2,c[2]);
	GetDlgItemText(IDC_c3,c[3]);
	GetDlgItemText(IDC_c4,c[4]);
	GetDlgItemText(IDC_c5,c[5]);
    GetDlgItemText(IDC_c6,c[6]);
	GetDlgItemText(IDC_c7,c[7]);
	GetDlgItemText(IDC_c8,c[8]);
	GetDlgItemText(IDC_c9,c[9]);
	GetDlgItemText(IDC_d1,d[1]);
	GetDlgItemText(IDC_d2,d[2]);
	GetDlgItemText(IDC_d3,d[3]);
	GetDlgItemText(IDC_d4,d[4]);
	GetDlgItemText(IDC_d5,d[5]);
    GetDlgItemText(IDC_d6,d[6]);
	GetDlgItemText(IDC_d7,d[7]);
	GetDlgItemText(IDC_d8,d[8]);
	GetDlgItemText(IDC_d9,d[9]);
	GetDlgItemText(IDC_e1,e[1]);
	GetDlgItemText(IDC_e2,e[2]);
	GetDlgItemText(IDC_e3,e[3]);
	GetDlgItemText(IDC_e4,e[4]);
	GetDlgItemText(IDC_e5,e[5]);
    GetDlgItemText(IDC_e6,e[6]);
	GetDlgItemText(IDC_e7,e[7]);
	GetDlgItemText(IDC_e8,e[8]);
	GetDlgItemText(IDC_e9,e[9]);
	GetDlgItemText(IDC_f1,f[1]);
	GetDlgItemText(IDC_f2,f[2]);
	GetDlgItemText(IDC_f3,f[3]);
	GetDlgItemText(IDC_f4,f[4]);
	GetDlgItemText(IDC_f5,f[5]);
    GetDlgItemText(IDC_f6,f[6]);
	GetDlgItemText(IDC_f7,f[7]);
	GetDlgItemText(IDC_f8,f[8]);
	GetDlgItemText(IDC_f9,f[9]);
	// TODO: Add your control notification handler code here
	
}
