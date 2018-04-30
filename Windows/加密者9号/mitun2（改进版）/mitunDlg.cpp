// mitunDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mitun.h"
#include "mitunDlg.h"

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
// CMitunDlg dialog

CMitunDlg::CMitunDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMitunDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMitunDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMitunDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMitunDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMitunDlg, CDialog)
	//{{AFX_MSG_MAP(CMitunDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMitunDlg message handlers

BOOL CMitunDlg::OnInitDialog()
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

void CMitunDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMitunDlg::OnPaint() 
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
HCURSOR CMitunDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMitunDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	char* p=new char[90];
	 CString shuru;
	 int i=1;
	 int j=1;
	 CString hangshu;
	 int jishu=1;
	 int hang=9;
	 CString read;
    char* pszFileName="E:\\jiami\\jiami.txt";
	CStdioFile myFile;
	CFileException fileException;
    char* pszFileName1="E:\\jiami\\jiemi.txt";
	CStdioFile myFile1;
	CFileException fileException1;
	// TODO: Add your control notification handler code here
	 GetDlgItemText(IDC_EDIT2,hangshu);
	 hang=atoi(hangshu);
   if(myFile.Open(pszFileName,CFile::typeText|CFile::modeReadWrite,&fileException))
   {
	   
	  
       if(myFile1.Open(pszFileName1,CFile::typeText|CFile::modeWrite,&fileException1))
	   {
		   myFile.SeekToBegin();
	       myFile1.SeekToBegin();
		   for(i=1;i<hang;i++)
		   {
			  myFile.ReadString(shuru);
			  p=shuru.GetBuffer(39);
			  char* s=p;
			  *s=~*s;
			  shuru=p;
			  myFile1.WriteString(shuru);
			  myFile1.WriteString("\n");
		   }
	   }
		
   }
   myFile1.Close();
   myFile.Close();
   AfxMessageBox("加密成功啦！你的数据安全又保障了。");
}

void CMitunDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CString kouling;
	GetDlgItemText(IDC_EDIT3,kouling);

   	char* p=new char[90];
	 CString shuru;
	 int i=1;
	 int j=1;
	 CString hangshu;
	 int jishu=1;
	 int hang=9;
	 CString read;
    char* pszFileName="E:\\jiami\\jiemi.txt";
	CStdioFile myFile;
	CFileException fileException;
    char* pszFileName1="E:\\jiami\\jiami.txt";
	CStdioFile myFile1;
	CFileException fileException1;
	// TODO: Add your control notification handler code here
	 GetDlgItemText(IDC_EDIT2,hangshu);
	 hang=atoi(hangshu);
	 if(kouling=="蒋欣呈你真一大好人")
	{
			   if(myFile.Open(pszFileName,CFile::typeText|CFile::modeReadWrite,&fileException))
			   {
				   
				  
						   if(myFile1.Open(pszFileName1,CFile::typeText|CFile::modeWrite,&fileException1))
						   {
									   myFile.SeekToBegin();
									   myFile1.SeekToBegin();
									   for(i=1;i<hang;i++)
									   {
												  myFile.ReadString(shuru);
												  p=shuru.GetBuffer(39);
												  char* s=p;
												  *s=~*s;
												  shuru=p;
												  myFile1.WriteString(shuru);
												  myFile1.WriteString("\n");
									   }
									  
									   myFile1.Close();
									   myFile.Close();
									   AfxMessageBox("解密成功啦！欢迎再次使用。");
						   }
						   
						   else
							   AfxMessageBox("Unable to open the file.");
							
			   }
			  
			   else
				   AfxMessageBox("Unable to open the file.");
			  
	}
	else
	{
		AfxMessageBox("对不起，你的口令貌似不太正确。请再次输入吧");
	}
}

void CMitunDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
   	AfxMessageBox("本软件非用于商业用途，默认加密行数为9行，若要自己定义，请在lines for it:后的对话框中定制，最多可以有190行，点击加密后将jiami.txt（E盘根目录）文件转化为jiemi.txt（E盘根目录），加密时同理将jiemi.txt转化为jiami.txt,希望能对阁下起到帮助，2012.1.21，by 卷心菜");	
}

void CMitunDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	 char* p=new char[90];
     char* mi=new char[90];
	 CString shuru;
	 CString miyao;
	 CString hangshu;
	 int i=1;
	 int j=1;
	 int jishu=1;
	 int hang=9;
	 CString read;
    char* pszFileName="E:\\jiami\\jiami.txt";
	CStdioFile myFile;
	CFileException fileException;
    char* pszFileName1="E:\\jiami\\jiemi.txt";
	CStdioFile myFile1;
	CFileException fileException1;
	// TODO: Add your control notification handler code here
	 GetDlgItemText(IDC_EDIT2,hangshu);
	 GetDlgItemText(IDC_EDIT1,miyao);
	 hang=atoi(hangshu);
	 mi=miyao.GetBuffer(39);
	 char* yao=mi;
   if(myFile.Open(pszFileName,CFile::typeText|CFile::modeReadWrite,&fileException))
   {
	   
	  
       if(myFile1.Open(pszFileName1,CFile::typeText|CFile::modeWrite,&fileException1))
	   {
		   myFile.SeekToBegin();
	       myFile1.SeekToBegin();
		   for(i=1;i<hang;i++)
		   {
			  myFile.ReadString(shuru);
			  p=shuru.GetBuffer(39);
			  char* s=p;
			  while(*s)
			  {
			     *s=*s^*yao;
				 s++;
			  }
			     shuru=p;
			  myFile1.WriteString(shuru);
			  myFile1.WriteString("\n");
		   }
	   }
		
   }
   myFile1.Close();
   myFile.Close();
   AfxMessageBox("加密成功啦！你的数据安全又保障了。不过务必记住你的密钥哦！");
}

void CMitunDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
    		CString kouling;
	GetDlgItemText(IDC_EDIT3,kouling);
   	char* p=new char[90];
	char* mi=new char[90];
	CString miyao;
	 CString shuru;
	 int i=1;
	 int j=1;
	 CString hangshu;
	 int jishu=1;
	 int hang=9;
	 CString read;
    char* pszFileName="E:\\jiami\\jiemi.txt";
	CStdioFile myFile;
	CFileException fileException;
    char* pszFileName1="E:\\jiami\\jiami.txt";
	CStdioFile myFile1;
	CFileException fileException1;
	// TODO: Add your control notification handler code here
	 GetDlgItemText(IDC_EDIT2,hangshu);
	 GetDlgItemText(IDC_EDIT1,miyao);
	 hang=atoi(hangshu);
	 mi=miyao.GetBuffer(39);
	 char* yao=mi;
	 if(kouling=="蒋欣呈你真一大好人")
	{
			   if(myFile.Open(pszFileName,CFile::typeText|CFile::modeReadWrite,&fileException))
			   {
				   
				  
						   if(myFile1.Open(pszFileName1,CFile::typeText|CFile::modeWrite,&fileException1))
						   {
									   myFile.SeekToBegin();
									   myFile1.SeekToBegin();
									   for(i=1;i<hang;i++)
									   {
												  myFile.ReadString(shuru);
												  p=shuru.GetBuffer(39);
												  char* s=p;
												  while(*s)
												  {
												     *s=*s^*yao;
													 s++;
												  }
												  shuru=p;
												  myFile1.WriteString(shuru);
												  myFile1.WriteString("\n");
									   }
									  
									   myFile1.Close();
									   myFile.Close();
									   AfxMessageBox("解密成功啦！欢迎再次使用。");
						   }
						   
						   else
							   AfxMessageBox("Unable to open the file.");
							
			   }
			  
			   else
				   AfxMessageBox("Unable to open the file.");
			  
	}
	else
	{
		AfxMessageBox("对不起，你的口令貌似不太正确。请再次输入吧");
	}
}

void CMitunDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	AfxMessageBox("对于左边的常规部分，加密无需输入密钥，而解密需输入操作密钥。右边同理，可以自定义加密所用的密钥，密钥最好采用英文字符串（别急，中文字符加密会在之后开发）可保证安全性。本软件为2012新春特别版，愿给阁下带来帮助！by 卷心菜");
}
