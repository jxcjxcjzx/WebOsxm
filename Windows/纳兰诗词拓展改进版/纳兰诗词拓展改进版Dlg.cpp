// ����ʫ����չ�Ľ���Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "����ʫ����չ�Ľ���.h"
#include "����ʫ����չ�Ľ���Dlg.h"

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
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
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
	    int jilu;
		int j;
		char* pszFileName2="F:\\ʫ��ʫ�ʸ����ļ�.txt";
		CStdioFile myFile2;
		CFileException fileException2;
		if(myFile2.Open(pszFileName2,CFile::typeText|CFile::modeReadWrite),&fileException2)
		{
			 CString read1;
			 myFile2.ReadString(read1);
			 jilu=atoi(read1);

		}
		else
		{
		TRACE("Can't open file %s,error=%u\n",pszFileName2,fileException2.m_cause);
		}
		myFile2.Close();


		CString shuming[999];
		CString jincheng[999];
		GetDlgItemText(IDC_EDIT1,shuming[jilu]);
		GetDlgItemText(IDC_EDIT2,jincheng[jilu]);

		char * pszFileName="F:\\ʫ��ʫ�ʴ洢�ļ�.txt";
		CStdioFile myFile;
		CFileException fileException;
		if(myFile.Open(pszFileName,CFile::typeText|CFile::modeReadWrite),&fileException)
		{
          
			  myFile.SeekToBegin();
       		   for(j=0;j<jilu;j++)
		   {
			   myFile.ReadString(shuming[j]);
			   myFile.ReadString(jincheng[j]);
		   }
		   
		}
		else
		{
		TRACE("Can't open file %s,error=%u\n",pszFileName,fileException.m_cause);
		}
		myFile.Close();


		//�˴�����д��
		char * pszFileName3="F:\\ʫ��ʫ�ʴ洢�ļ�.txt";
		CStdioFile myFile3;
		CFileException fileException3;
		if(myFile3.Open(pszFileName3,CFile::modeCreate|CFile::typeText|CFile::modeReadWrite),&fileException3)
		{
          
			  	myFile3.SeekToBegin();
       		   for(j=0;j<jilu+1;j++)
		   {
			   
			   myFile3.WriteString(shuming[j]);
			    myFile3.WriteString("\n");
			   myFile3.WriteString(jincheng[j]);
			    myFile3.WriteString("\n");
		   }
			   SetDlgItemText(IDC_EDIT4,"��ӳɹ���");
		   
		}
		else
		{
		TRACE("Can't open file %s,error=%u\n",pszFileName3,fileException3.m_cause);
		}
		myFile3.Close();

		

		//�˴�����д���µ�ҳ��
		char* pszFileName22="F:\\ʫ��ʫ�ʸ����ļ�.txt";
		CStdioFile myFile22;
		CFileException fileException22;
		if(myFile22.Open(pszFileName22,CFile::modeCreate|CFile::typeText|CFile::modeReadWrite),&fileException22)
		{
			 CString jilujilu;
			 jilujilu.Format("%d",jilu+1);
			 myFile22.WriteString(jilujilu);
		
		}
		else
		{
		TRACE("Can't open file %s,error=%u\n",pszFileName22,fileException22.m_cause);
		}
		myFile22.Close();



	// TODO: Add your control notification handler code here
	
}

void CMyDlg::OnButton2() 
{
	int jilu;
	int result1;
	int j;
	char* pszFileName="F:\\ʫ��ʫ�ʸ����ļ�.txt";
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
	
     	CString shuming[999];
     
		CString jincheng[999];

    char* pszFileName2="F:\\ʫ��ʫ�ʴ洢�ļ�.txt";
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
	   GetDlgItemText(IDC_EDIT3,chaxun);
	   for(j=0;j<jilu;j++)
	   {
		   
		   if(chaxun==shuming[j])
		   {
			   SetDlgItemText(IDC_EDIT4,jincheng[j]);
			   result1=1;

		   }
		   if(0==result1)
			   SetDlgItemText(IDC_EDIT4,"û�ҵ�");

	   }
	   
     


	}
	else
	{
	TRACE("Can't open file %s,error=%u\n",pszFileName,fileException.m_cause);
	}
	myFile.Close();
	// TODO: Add your control notification handler code here
	
}

void CMyDlg::OnButton3() 
{
     SetDlgItemText(IDC_EDIT4,"��л���¶Ա������֧�֣�����������ڲ�ʹ�ã�ʹ��ǰ���ȵ��������ϵġ���ʼ������ť�������ڸ��µĵ���F�����Զ������������ġ�����ʫ�ʴ洢�ļ�.txt���͡�����ʫ�ʸ����ļ�.txt��������������Ҫʹ�ñ����ʱ������ɾ���������ļ���������Ҫ���ʫ��ʱ���ڽ����ұߵ���Ӧλ���������ݣ�����Ϊʫ�⣬����Ϊʫ����Ȼ������һ����ӡ����ɡ�");
	// TODO: Add your control notification handler code here
	 SetDlgItemText(IDC_EDIT2,"������Ҫ��ѯʱ���ڽ��������Ӧλ�ã����棩д��ʫ�⣬�����һ����ѯ��������ʫ���·��������ݡ����Ĳ�ף���������⣡");
	
}

void CMyDlg::OnButton4() 
{
    char* pszFileName="F:\\ʫ��ʫ�ʸ����ļ�.txt";
	CStdioFile myFile2;
	CFileException fileException;
	if(myFile2.Open(pszFileName,CFile::modeCreate|CFile::typeText|CFile::modeReadWrite),&fileException)
	{
		CString str1="0";
		myFile2.WriteString(str1);
         SetDlgItemText(IDC_EDIT2,"��ʼ����һ���ɹ���");
         
	}
	else
	{
	TRACE("Can't open file %s,error=%u\n",pszFileName,fileException.m_cause);
	}
	myFile2.Close();
	// TODO: Add your control notification handler code here



	  char* pszFileName2="F:\\ʫ��ʫ�ʴ洢�ļ�.txt";
	CStdioFile myFile;
	CFileException fileException2;
	if(myFile.Open(pszFileName2,CFile::modeCreate|CFile::typeText|CFile::modeReadWrite),&fileException2)
	{
     
         SetDlgItemText(IDC_EDIT4,"��ʼ���ڶ����ɹ���");

	}
	else
	{
	TRACE("Can't open file %s,error=%u\n",pszFileName,fileException.m_cause);
	}
	myFile.Close();


	
}
