// 1View.cpp : implementation of the CMy1View class
//

#include "stdafx.h"
#include "1.h"

#include "1Doc.h"
#include "1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy1View

IMPLEMENT_DYNCREATE(CMy1View, CView)

BEGIN_MESSAGE_MAP(CMy1View, CView)
	//{{AFX_MSG_MAP(CMy1View)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1View construction/destruction

CMy1View::CMy1View()
{
	
	// TODO: add construction code here

}

CMy1View::~CMy1View()
{
}

BOOL CMy1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy1View drawing

void CMy1View::OnDraw(CDC* pDC)
{
    CDC MemDC;
	CClientDC dc(this);	
	
	int i;
	int j;
	for(i=0;i<501;i+=20)
	{
	dc.MoveTo(i,0);
	dc.LineTo(i,501);
	}
	for(j=0;j<501;j+=20)
	{
	dc.MoveTo(0,j);
	dc.LineTo(501,j);
	}
     
      /*  CBitmap bitmap;
		int id_picture;
		BITMAP bm;
    	id_picture=IDB_BITMAP1;
   
		//&MemDC指向原设备对象的指针
	    //SRCCOPY 光栅操作方式
    	//函数功能：函数从源矩形中复制一个位图到目标矩形，必要时按目前目标设备设置的模式进行图像的拉伸或压缩。

		bitmap.LoadBitmap(id_picture);
		MemDC.SelectObject(&bitmap);
  		bitmap.GetBitmap(&bm);
		dc.StretchBlt(bm.bmWidth+30,10,bm.bmWidth,bm.bmHeight,&MemDC,0,0,bm.bmWidth,bm.bmHeight,SRCCOPY); 
		bitmap.DeleteObject();
		*/


	/*
	dc.MoveTo(0,0);
	dc.LineTo(300,300);
	CBrush brush(RGB(240,240,240));
	pDC->SelectObject(&brush);
	pDC->SetBkColor(RGB(0,0,0));
	pDC->SetTextColor(RGB(0,255,255));
	LOGFONT lf;
	CFont cf;
	memset(&lf,0,sizeof(LOGFONT));
	lf.lfHeight=-80;
	lf.lfCharSet=GB2312_CHARSET;
	::lstrcpy(lf.lfFaceName,"华文行楷");
	cf.CreateFontIndirect(&lf);
	CFont* oldfont=pDC->SelectObject(&cf);
	pDC->SetTextColor(RGB(255,255,0));
	pDC->SetBkColor(RGB(0,120,120));
	pDC->TextOut(50,140,"机");
	pDC->TextOut(50,210,"对");

   
	for(i=1;i<16;i+=2)
	pDC->Ellipse(20*(i-1),20*(i-1),20*i,20*i);
	CBrush brush2(RGB(0,0,0));
	pDC->SelectObject(&brush2);
	for(j=2;j<16;j+=2)
	pDC->Ellipse(20*(j-1),20*(j-1),20*j,20*j);
	pDC->Ellipse(0,0,100,100);
*/

	CMy1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMy1View printing

BOOL CMy1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMy1View diagnostics

#ifdef _DEBUG
void CMy1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1Doc* CMy1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1Doc)));
	return (CMy1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy1View message handlers

void CMy1View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	   
	
	CClientDC dc(this);

	ii=(point.x/20)*20;
	jj=(point.y/20)*20;
    

    char* pszFileName="E:\\jiami\\wuzimimi.txt";
	CStdioFile myFile;
	CFileException fileException;
	if(myFile.Open(pszFileName,CFile::typeText|CFile::modeReadWrite),&fileException)
	{  
       CString xieru1;
       CString xieru2;
	   xieru1.Format("%d",ii/20);
	   xieru2.Format("%d",jj/20);
	   myFile.SeekToEnd();
	   myFile.WriteString(xieru1);
	   myFile.WriteString(",");
       myFile.WriteString(xieru2);
	   myFile.WriteString(",");
         
	}

	else
	{
	TRACE("Can't open file %s,error=%u\n",pszFileName,fileException.m_cause);
	}
	myFile.Close();







	if(biaozhi==1)
	{
	CBrush brush2(RGB(0,20,120));
	dc.SelectObject(&brush2);
	dc.Ellipse(ii,jj,ii+20,jj+20);

	biaozhi=0;
	}
	else
	{
	CBrush brush2(RGB(120,30,40));
	dc.SelectObject(&brush2);
	dc.Ellipse(ii,jj,ii+20,jj+20);
	biaozhi=1;
	
	
	}
	// TODO: Add your message handler code here and/or call default
	
}

void CMy1View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default


}
