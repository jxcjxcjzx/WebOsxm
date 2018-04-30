// Ä§·½.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Ä§·½.h"
#include "Ä§·½Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyApp

BEGIN_MESSAGE_MAP(CMyApp, CWinApp)
	//{{AFX_MSG_MAP(CMyApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyApp construction

void CMyDlg::xianshi()
{
   
	SetDlgItemText(IDC_a1,a[1]);
	SetDlgItemText(IDC_a2,a[2]);
	SetDlgItemText(IDC_a3,a[3]);
	SetDlgItemText(IDC_a4,a[4]);
	SetDlgItemText(IDC_a5,a[5]);
	SetDlgItemText(IDC_a6,a[6]);
	SetDlgItemText(IDC_a7,a[7]);
	SetDlgItemText(IDC_a8,a[8]);
	SetDlgItemText(IDC_a9,a[9]);
	SetDlgItemText(IDC_b1,b[1]);
	SetDlgItemText(IDC_b2,b[2]);
	SetDlgItemText(IDC_b3,b[3]);
	SetDlgItemText(IDC_b4,b[4]);
	SetDlgItemText(IDC_b5,b[5]);
	SetDlgItemText(IDC_b6,b[6]);
	SetDlgItemText(IDC_b7,b[7]);
	SetDlgItemText(IDC_b8,b[8]);
	SetDlgItemText(IDC_b9,b[9]);
	SetDlgItemText(IDC_c1,c[1]);
	SetDlgItemText(IDC_c2,c[2]);
	SetDlgItemText(IDC_c3,c[3]);
	SetDlgItemText(IDC_c4,c[4]);
	SetDlgItemText(IDC_c5,c[5]);
	SetDlgItemText(IDC_c6,c[6]);
	SetDlgItemText(IDC_c7,c[7]);
	SetDlgItemText(IDC_c8,c[8]);
	SetDlgItemText(IDC_c9,c[9]);
	SetDlgItemText(IDC_d1,d[1]);
	SetDlgItemText(IDC_d2,d[2]);
	SetDlgItemText(IDC_d3,d[3]);
	SetDlgItemText(IDC_d4,d[4]);
	SetDlgItemText(IDC_d5,d[5]);
	SetDlgItemText(IDC_d6,d[6]);
	SetDlgItemText(IDC_d7,d[7]);
	SetDlgItemText(IDC_d8,d[8]);
	SetDlgItemText(IDC_d9,d[9]);
	SetDlgItemText(IDC_e1,e[1]);
	SetDlgItemText(IDC_e2,e[2]);
	SetDlgItemText(IDC_e3,e[3]);
	SetDlgItemText(IDC_e4,e[4]);
	SetDlgItemText(IDC_e5,e[5]);
	SetDlgItemText(IDC_e6,e[6]);
	SetDlgItemText(IDC_e7,e[7]);
	SetDlgItemText(IDC_e8,e[8]);
	SetDlgItemText(IDC_e9,e[9]);
	SetDlgItemText(IDC_f1,f[1]);
	SetDlgItemText(IDC_f2,f[2]);
	SetDlgItemText(IDC_f3,f[3]);
	SetDlgItemText(IDC_f4,f[4]);
	SetDlgItemText(IDC_f5,f[5]);
	SetDlgItemText(IDC_f6,f[6]);
	SetDlgItemText(IDC_f7,f[7]);
	SetDlgItemText(IDC_f8,f[8]);
	SetDlgItemText(IDC_f9,f[9]);







}

void CMyDlg::chushihua()
{
    int i;
	for(i=1;i<10;i++)
		a[i]="À¶";
	for(i=1;i<10;i++)
		b[i]="°×";
	for(i=1;i<10;i++)
		c[i]="ÂÌ";
	for(i=1;i<10;i++)
		d[i]="»Æ";
	for(i=1;i<10;i++)
		e[i]="ºì";
	for(i=1;i<10;i++)
		f[i]="·Û";

}



CMyApp::CMyApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMyApp object

CMyApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMyApp initialization

BOOL CMyApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CMyDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
