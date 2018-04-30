// 阅读记录器9号Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "阅读记录器9号.h"
#include "阅读记录器9号Dlg.h"

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
// CMy9Dlg dialog

CMy9Dlg::CMy9Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy9Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy9Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy9Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy9Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy9Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy9Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy9Dlg message handlers

BOOL CMy9Dlg::OnInitDialog()
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

void CMy9Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy9Dlg::OnPaint() 
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
HCURSOR CMy9Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy9Dlg::OnButton3() 
{
		int jilu;
		int j;
		char* pszFileName="F:\\geithei.txt";
		CStdioFile myFile2;
		CFileException fileException;
		if(myFile2.Open(pszFileName,CFile::typeText|CFile::modeReadWrite),&fileException)
		{
			 CString read1;
			 myFile2.ReadString(read1);
			 jilu=atoi(read1);

		}
		else
		{
		TRACE("Can't open file %s,error=%u\n",pszFileName,fileException.m_cause);
		}
		myFile2.Close();


       //此处重新写入
	    CString shuming[99];
		CString jincheng[99];
	     GetDlgItemText(IDC_EDIT3,shuming[jilu]);
		 GetDlgItemText(IDC_EDIT4,jincheng[jilu]);


		 
	    	
		char* pszFileName4="F:\\myfile.txt";
		CStdioFile myFile4;
		CFileException fileException4;

    	if(myFile4.Open(pszFileName4,CFile::typeText|CFile::modeReadWrite),&fileException4)
		{ 
		
			for(j=0;j<jilu;j++)
		   {
			  	myFile4.SeekToBegin();
       		   for(j=0;j<jilu;j++)
		   {
			   myFile4.ReadString(shuming[j]);
			   myFile4.ReadString(jincheng[j]);
		   }
		   }
         
		}

		else
		{
		TRACE("Can't open file %s,error=%u\n",pszFileName4,fileException4.m_cause);
		}
		myFile4.Close();

	    	
		char* pszFileName3="F:\\myfile.txt";
		CStdioFile myFile3;
		CFileException fileException3;

		 
		if(myFile3.Open(pszFileName3,CFile::modeCreate|CFile::typeText|CFile::modeReadWrite),&fileException3)
		{ 
		
			for(j=0;j<jilu+1;j++)
		   {
			   myFile3.WriteString(shuming[j]);
			   myFile3.WriteString("\n");
			   myFile3.WriteString(jincheng[j]);
			   myFile3.WriteString("\n");
		   }
         
		}

		else
		{
		TRACE("Can't open file %s,error=%u\n",pszFileName3,fileException.m_cause);
		}
		myFile3.Close();


     //改变新的页码
		char* pszFileName22="F:\\geithei.txt";
		CStdioFile myFile22;
		CFileException fileException22;
		if(myFile22.Open(pszFileName22,CFile::modeCreate|CFile::typeText|CFile::modeReadWrite),&fileException22)
		{
			 CString jilujilu;
			 jilujilu.Format("%d",jilu+1);
			 myFile22.WriteString(jilujilu);
			 SetDlgItemText(IDC_EDIT5," 添加成功！");
		}
		else
		{
		TRACE("Can't open file %s,error=%u\n",pszFileName22,fileException22.m_cause);
		}
		myFile22.Close();

		


	// TODO: Add your control notification handler code here
	
}

void CMy9Dlg::OnButton2() 
{
	
    int jilu;
	int j;
	char* pszFileName="F:\\geithei.txt";
	CStdioFile myFile2;
	CFileException fileException;
	if(myFile2.Open(pszFileName,CFile::typeText|CFile::modeReadWrite),&fileException)
	{
         CString read1;
		 myFile2.ReadString(read1);
		 jilu=atoi(read1);

	}
	else
	{
	TRACE("Can't open file %s,error=%u\n",pszFileName,fileException.m_cause);
	}
	myFile2.Close();
	//these are the places the books' names are recorded
	CString shuming[99];

    
	//these are the places the process reading are recorded
	CString jincheng[99];


    char* pszFileName2="F:\\myfile.txt";
	CStdioFile myFile;
	CFileException fileException2;
	if(myFile.Open(pszFileName2,CFile::typeText|CFile::modeReadWrite),&fileException2)
	{
	   myFile.SeekToBegin();
       	   for(j=0;j<jilu;j++)
	   {
		   myFile.ReadString(shuming[j]);
		   myFile.ReadString(jincheng[j]);
	   }
       CString chaxun;
	   GetDlgItemText(IDC_EDIT1,chaxun);
	   CString xiugai;
	   CString xiugai2;
	   for(j=0;j<jilu;j++)
	   {
		   if(chaxun==shuming[j])
		   {	
			   
		       GetDlgItemText(IDC_EDIT2,xiugai);
			   jincheng[j]=xiugai;
			   GetDlgItemText(IDC_EDIT1,xiugai2);
			   shuming[j]=xiugai2;

			   
		       
		   }

	   }
	   
	}
	else
	{
	TRACE("Can't open file %s,error=%u\n",pszFileName,fileException.m_cause);
	}
	myFile.Close();
	






     //此处重新写入文件
     
	char* pszFileName3="F:\\myfile.txt";
	CStdioFile myFile3;
	CFileException fileException3;
	if(myFile3.Open(pszFileName3,CFile::typeText|CFile::modeReadWrite),&fileException3)
	{  
		for(j=0;j<jilu;j++)
	   {
		   myFile3.WriteString(shuming[j]);
		   myFile3.WriteString("\n");
	       myFile3.WriteString(jincheng[j]);
		   myFile3.WriteString("\n");
	   }
		SetDlgItemText(IDC_EDIT5," 修改成功！");
         
	}

	else
	{
	TRACE("Can't open file %s,error=%u\n",pszFileName3,fileException.m_cause);
	}
	myFile3.Close();
	// TODO: Add your control notification handler code here
	
}

void CMy9Dlg::OnButton1() 
{
	int result1=0;
    int jilu;
	int j;
	char* pszFileName="F:\\geithei.txt";
	CStdioFile myFile2;
	CFileException fileException;
	if(myFile2.Open(pszFileName,CFile::typeText|CFile::modeReadWrite),&fileException)
	{
         CString read1;
		 myFile2.ReadString(read1);
		 jilu=atoi(read1);
		   
         
	}
	else
	{
	TRACE("Can't open file %s,error=%u\n",pszFileName,fileException.m_cause);
	}
	myFile2.Close();
	//these are the places the books' names are recorded
	CString shuming[99];

    
	//these are the places the process reading are recorded
	CString jincheng[99];


    char* pszFileName2="F:\\myfile.txt";
	CStdioFile myFile;
	CFileException fileException2;
	if(myFile.Open(pszFileName2,CFile::typeText|CFile::modeReadWrite),&fileException2)
	{
	   myFile.SeekToBegin();
       	   for(j=0;j<jilu;j++)
	   {
		   myFile.ReadString(shuming[j]);
		   myFile.ReadString(jincheng[j]);
	   }
       CString chaxun;
	   GetDlgItemText(IDC_EDIT1,chaxun);
	   for(j=0;j<jilu;j++)
	   {
		   
		   if(chaxun==shuming[j])
		   {
			   SetDlgItemText(IDC_EDIT2,jincheng[j]);
			   result1=1;

		   }
		   if(0==result1)
			   SetDlgItemText(IDC_EDIT2,"没找到");

	   }
	   
     


	}
	else
	{
	TRACE("Can't open file %s,error=%u\n",pszFileName,fileException.m_cause);
	}
	myFile.Close();


	

	// TODO: Add your control notification handler code here
	
}

void CMy9Dlg::OnButton4() 
{   
	
	// TODO: Add your control notification handler code here
	
}

void CMy9Dlg::OnButton5() 
{
	SetDlgItemText(IDC_EDIT6,"本软件非商业用途。本软件主要用于阅读的管理，本软件在阁下电脑的F盘中自动生成myfile.txt和getthei.txt两个文件，可以删除这两个文件。希望能对阁下的工作生活起到帮助！卷心菜祝万事如意！");
	// TODO: Add your control notification handler code here
	
}
