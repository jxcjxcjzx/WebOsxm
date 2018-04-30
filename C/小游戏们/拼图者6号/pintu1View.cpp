// pintu1View.cpp : implementation of the CPintu1View class
//

#include "stdafx.h"
#include "pintu1.h"

#include "pintu1Doc.h"
#include "pintu1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPintu1View

IMPLEMENT_DYNCREATE(CPintu1View, CView)

BEGIN_MESSAGE_MAP(CPintu1View, CView)
	//{{AFX_MSG_MAP(CPintu1View)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPintu1View construction/destruction

CPintu1View::CPintu1View()
{
	int i;
	for(i=1;i<10;i++)
		biaoji[i]=0;
	// TODO: add construction code here

}

CPintu1View::~CPintu1View()
{
}

BOOL CPintu1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPintu1View drawing

void CPintu1View::OnDraw(CDC* pDC)
{
	int i;
	int j;
	int suiji;
	CPintu1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
    GetClientRect(rect); 
    jilu1=rect.Width()/6; 
    jilu2=rect.Height()/3; 
    biaoji[9]=1;
	pintu[3][3]=0;
    for(i=1;i<4;i++)
		for(j=1;j<3;j++)
		{   
		     suiji=((rand()*152+123)/23-2)%8+1;
	
          	 while(biaoji[suiji]==1)
		   {
               suiji=((rand()*152+123)/23-2)%8+1;
			   pintu[i][j]=suiji;
			   
		   }
             pintu[i][j]=suiji;
             biaoji[suiji]=1;
		}
    for(i=1;i<10;i++)
		if(biaoji[i]==0)
		{
			pintu[1][3]=i;
			biaoji[i]=1;
			break;
		}
	for(i=1;i<10;i++)
		if(biaoji[i]==0)
			pintu[2][3]=i;


  for(i=1;i<4;i++)
	  for(j=1;j<4;j++)
	  {
		if(i==3&&j==3)
			continue;
		else
		if(pintu[i][j]==1)
			  draw1(pDC,i-1,j-1);
		else
		if(pintu[i][j]==2)
			  draw2(pDC,i-1,j-1);
		else
		if(pintu[i][j]==3)
			  draw3(pDC,i-1,j-1);
		else
		if(pintu[i][j]==4)
			  draw4(pDC,i-1,j-1);
		else
		if(pintu[i][j]==5)
			  draw5(pDC,i-1,j-1);
		else
		if(pintu[i][j]==6)
			  draw6(pDC,i-1,j-1);
		else
		if(pintu[i][j]==7)
			  draw7(pDC,i-1,j-1);
		else
		if(pintu[i][j]==8)
			  draw8(pDC,i-1,j-1);


	  }

	 

	
	// TODO: add draw code for native data here




}

/////////////////////////////////////////////////////////////////////////////
// CPintu1View printing

BOOL CPintu1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPintu1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPintu1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPintu1View diagnostics

#ifdef _DEBUG
void CPintu1View::AssertValid() const
{
	CView::AssertValid();
}

void CPintu1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPintu1Doc* CPintu1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPintu1Doc)));
	return (CPintu1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPintu1View message handlers

void CPintu1View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	 CDC* pDC = GetDC();
	weizhix=(point.x/jilu1)+1;
	weizhiy=(point.y/jilu2)+1;
    
    int i;
	int j;
	for(i=1;i<4;i++)
		for(j=1;j<4;j++)
		{
		
		   if(pintu[i][j]==0)
		   {
		     jix=i;
			 jiy=j;
		   }
		
		
		}
     if (((jix==weizhix)&&(jiy==weizhiy-1))|((jix==weizhix)&&(jiy==weizhiy+1))|((jix-1==weizhix)&&(jiy==weizhiy))|((jix+1==weizhix)&&(jiy==weizhiy)))
	 {
		 drawwhite(pDC,weizhix-1,weizhiy-1);
	          if(pintu[weizhix][weizhiy]==8)
			 draw8(pDC,jix-1,jiy-1);
		 else
			  if(pintu[weizhix][weizhiy]==1)
			 draw1(pDC,jix-1,jiy-1);
		 else
			  if(pintu[weizhix][weizhiy]==2)
			 draw2(pDC,jix-1,jiy-1);
		 else
			  if(pintu[weizhix][weizhiy]==3)
			 draw3(pDC,jix-1,jiy-1);
		 else
			  if(pintu[weizhix][weizhiy]==4)
			 draw4(pDC,jix-1,jiy-1);
		 else
			  if(pintu[weizhix][weizhiy]==5)
			 draw5(pDC,jix-1,jiy-1);
		 else
			  if(pintu[weizhix][weizhiy]==6)
			 draw6(pDC,jix-1,jiy-1);
		 else
			  if(pintu[weizhix][weizhiy]==7)
			 draw7(pDC,jix-1,jiy-1);
		pintu[jix][jiy]=pintu[weizhix][weizhiy];
		pintu[weizhix][weizhiy]=0;
	 }

	// TODO: Add your message handler code here and/or call default
	
}


void CPintu1View::draw1(CDC *pDC,int i,int j)
{
	IPicture *pPic; 

	IStream *pStm; 

	CFileStatus fstatus; 

	CFile file; 

	LONG cb; 

	if (file.Open("1.jpg",CFile::modeRead)&&file.GetStatus("1.jpg", fstatus)&& ((cb = fstatus.m_size) != -1)) 

	{ 

	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb); 

	LPVOID pvData = NULL; 

	if (hGlobal != NULL) 

	{ 

	if ((pvData = GlobalLock(hGlobal)) != NULL) 

	{ 

	file.ReadHuge(pvData, cb); 

	GlobalUnlock(hGlobal); 

	CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 

	if(SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic))) 

	{ 

	OLE_XSIZE_HIMETRIC hmWidth; 

	OLE_YSIZE_HIMETRIC hmHeight; 

	pPic->get_Width(&hmWidth); 

	pPic->get_Height(&hmHeight); 

	double fX;
	double fY;

	fX=jilu1;

	fY=jilu2; 

	
	//fX = (double)pDC->GetDeviceCaps(HORZRES)*(double)hmWidth/((double)pDC->GetDeviceCaps(HORZSIZE)*100.0); 

	//fY = (double)pDC->GetDeviceCaps(VERTRES)*(double)hmHeight/((double)pDC->GetDeviceCaps(VERTSIZE)*100.0); 

	if(FAILED(pPic->Render(*pDC,jilu1*i,jilu2*j,(DWORD)fX,(DWORD)fY,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		AfxMessageBox("Failed To Render The picture!"); 

	pPic->Release(); 

	} 

	else 

	AfxMessageBox("Error Loading Picture From Stream!"); 

} 

} 

} 

else 

AfxMessageBox("Can't Open Image File!"); 

}




void CPintu1View::draw2(CDC *pDC,int i,int j)
{
	IPicture *pPic; 

	IStream *pStm; 

	CFileStatus fstatus; 

	CFile file; 

	LONG cb; 

	if (file.Open("2.jpg",CFile::modeRead)&&file.GetStatus("2.jpg", fstatus)&& ((cb = fstatus.m_size) != -1)) 

	{ 

	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb); 

	LPVOID pvData = NULL; 

	if (hGlobal != NULL) 

	{ 

	if ((pvData = GlobalLock(hGlobal)) != NULL) 

	{ 

	file.ReadHuge(pvData, cb); 

	GlobalUnlock(hGlobal); 

	CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 

	if(SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic))) 

	{ 

	OLE_XSIZE_HIMETRIC hmWidth; 

	OLE_YSIZE_HIMETRIC hmHeight; 

	pPic->get_Width(&hmWidth); 

	pPic->get_Height(&hmHeight); 

	double fX;
	double fY;

	fX=jilu1;

	fY=jilu2; 

	
	//fX = (double)pDC->GetDeviceCaps(HORZRES)*(double)hmWidth/((double)pDC->GetDeviceCaps(HORZSIZE)*100.0); 

	//fY = (double)pDC->GetDeviceCaps(VERTRES)*(double)hmHeight/((double)pDC->GetDeviceCaps(VERTSIZE)*100.0); 

	if(FAILED(pPic->Render(*pDC,jilu1*i,jilu2*j,(DWORD)fX,(DWORD)fY,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		AfxMessageBox("Failed To Render The picture!"); 

	pPic->Release(); 

	} 

	else 

	AfxMessageBox("Error Loading Picture From Stream!"); 

} 

} 

} 

else 

AfxMessageBox("Can't Open Image File!"); 

}


void CPintu1View::draw3(CDC *pDC,int i,int j)
{
	IPicture *pPic; 

	IStream *pStm; 

	CFileStatus fstatus; 

	CFile file; 

	LONG cb; 

	if (file.Open("3.jpg",CFile::modeRead)&&file.GetStatus("3.jpg", fstatus)&& ((cb = fstatus.m_size) != -1)) 

	{ 

	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb); 

	LPVOID pvData = NULL; 

	if (hGlobal != NULL) 

	{ 

	if ((pvData = GlobalLock(hGlobal)) != NULL) 

	{ 

	file.ReadHuge(pvData, cb); 

	GlobalUnlock(hGlobal); 

	CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 

	if(SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic))) 

	{ 

	OLE_XSIZE_HIMETRIC hmWidth; 

	OLE_YSIZE_HIMETRIC hmHeight; 

	pPic->get_Width(&hmWidth); 

	pPic->get_Height(&hmHeight); 

	double fX;
	double fY;

	fX=jilu1;

	fY=jilu2; 

	
	//fX = (double)pDC->GetDeviceCaps(HORZRES)*(double)hmWidth/((double)pDC->GetDeviceCaps(HORZSIZE)*100.0); 

	//fY = (double)pDC->GetDeviceCaps(VERTRES)*(double)hmHeight/((double)pDC->GetDeviceCaps(VERTSIZE)*100.0); 

	if(FAILED(pPic->Render(*pDC,jilu1*i,jilu2*j,(DWORD)fX,(DWORD)fY,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		AfxMessageBox("Failed To Render The picture!"); 

	pPic->Release(); 

	} 

	else 

	AfxMessageBox("Error Loading Picture From Stream!"); 

} 

} 

} 

else 

AfxMessageBox("Can't Open Image File!"); 

}


void CPintu1View::draw4(CDC *pDC,int i,int j)
{
	IPicture *pPic; 

	IStream *pStm; 

	CFileStatus fstatus; 

	CFile file; 

	LONG cb; 

	if (file.Open("4.jpg",CFile::modeRead)&&file.GetStatus("4.jpg", fstatus)&& ((cb = fstatus.m_size) != -1)) 

	{ 

	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb); 

	LPVOID pvData = NULL; 

	if (hGlobal != NULL) 

	{ 

	if ((pvData = GlobalLock(hGlobal)) != NULL) 

	{ 

	file.ReadHuge(pvData, cb); 

	GlobalUnlock(hGlobal); 

	CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 

	if(SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic))) 

	{ 

	OLE_XSIZE_HIMETRIC hmWidth; 

	OLE_YSIZE_HIMETRIC hmHeight; 

	pPic->get_Width(&hmWidth); 

	pPic->get_Height(&hmHeight); 

	double fX;
	double fY;

	fX=jilu1;

	fY=jilu2; 

	
	//fX = (double)pDC->GetDeviceCaps(HORZRES)*(double)hmWidth/((double)pDC->GetDeviceCaps(HORZSIZE)*100.0); 

	//fY = (double)pDC->GetDeviceCaps(VERTRES)*(double)hmHeight/((double)pDC->GetDeviceCaps(VERTSIZE)*100.0); 

	if(FAILED(pPic->Render(*pDC,jilu1*i,jilu2*j,(DWORD)fX,(DWORD)fY,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		AfxMessageBox("Failed To Render The picture!"); 

	pPic->Release(); 

	} 

	else 

	AfxMessageBox("Error Loading Picture From Stream!"); 

} 

} 

} 

else 

AfxMessageBox("Can't Open Image File!"); 

}


void CPintu1View::draw5(CDC *pDC,int i,int j)
{
	IPicture *pPic; 

	IStream *pStm; 

	CFileStatus fstatus; 

	CFile file; 

	LONG cb; 

	if (file.Open("5.jpg",CFile::modeRead)&&file.GetStatus("5.jpg", fstatus)&& ((cb = fstatus.m_size) != -1)) 

	{ 

	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb); 

	LPVOID pvData = NULL; 

	if (hGlobal != NULL) 

	{ 

	if ((pvData = GlobalLock(hGlobal)) != NULL) 

	{ 

	file.ReadHuge(pvData, cb); 

	GlobalUnlock(hGlobal); 

	CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 

	if(SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic))) 

	{ 

	OLE_XSIZE_HIMETRIC hmWidth; 

	OLE_YSIZE_HIMETRIC hmHeight; 

	pPic->get_Width(&hmWidth); 

	pPic->get_Height(&hmHeight); 

	double fX;
	double fY;

	fX=jilu1;

	fY=jilu2; 

	
	//fX = (double)pDC->GetDeviceCaps(HORZRES)*(double)hmWidth/((double)pDC->GetDeviceCaps(HORZSIZE)*100.0); 

	//fY = (double)pDC->GetDeviceCaps(VERTRES)*(double)hmHeight/((double)pDC->GetDeviceCaps(VERTSIZE)*100.0); 

	if(FAILED(pPic->Render(*pDC,jilu1*i,jilu2*j,(DWORD)fX,(DWORD)fY,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		AfxMessageBox("Failed To Render The picture!"); 

	pPic->Release(); 

	} 

	else 

	AfxMessageBox("Error Loading Picture From Stream!"); 

} 

} 

} 

else 

AfxMessageBox("Can't Open Image File!"); 

}



void CPintu1View::draw6(CDC *pDC,int i,int j)
{
	IPicture *pPic; 

	IStream *pStm; 

	CFileStatus fstatus; 

	CFile file; 

	LONG cb; 

	if (file.Open("6.jpg",CFile::modeRead)&&file.GetStatus("6.jpg", fstatus)&& ((cb = fstatus.m_size) != -1)) 

	{ 

	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb); 

	LPVOID pvData = NULL; 

	if (hGlobal != NULL) 

	{ 

	if ((pvData = GlobalLock(hGlobal)) != NULL) 

	{ 

	file.ReadHuge(pvData, cb); 

	GlobalUnlock(hGlobal); 

	CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 

	if(SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic))) 

	{ 

	OLE_XSIZE_HIMETRIC hmWidth; 

	OLE_YSIZE_HIMETRIC hmHeight; 

	pPic->get_Width(&hmWidth); 

	pPic->get_Height(&hmHeight); 

	double fX;
	double fY;

	fX=jilu1;

	fY=jilu2; 

	
	//fX = (double)pDC->GetDeviceCaps(HORZRES)*(double)hmWidth/((double)pDC->GetDeviceCaps(HORZSIZE)*100.0); 

	//fY = (double)pDC->GetDeviceCaps(VERTRES)*(double)hmHeight/((double)pDC->GetDeviceCaps(VERTSIZE)*100.0); 

	if(FAILED(pPic->Render(*pDC,jilu1*i,jilu2*j,(DWORD)fX,(DWORD)fY,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		AfxMessageBox("Failed To Render The picture!"); 

	pPic->Release(); 

	} 

	else 

	AfxMessageBox("Error Loading Picture From Stream!"); 

} 

} 

} 

else 

AfxMessageBox("Can't Open Image File!"); 

}


void CPintu1View::draw7(CDC *pDC,int i,int j)
{
	IPicture *pPic; 

	IStream *pStm; 

	CFileStatus fstatus; 

	CFile file; 

	LONG cb; 

	if (file.Open("7.jpg",CFile::modeRead)&&file.GetStatus("7.jpg", fstatus)&& ((cb = fstatus.m_size) != -1)) 

	{ 

	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb); 

	LPVOID pvData = NULL; 

	if (hGlobal != NULL) 

	{ 

	if ((pvData = GlobalLock(hGlobal)) != NULL) 

	{ 

	file.ReadHuge(pvData, cb); 

	GlobalUnlock(hGlobal); 

	CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 

	if(SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic))) 

	{ 

	OLE_XSIZE_HIMETRIC hmWidth; 

	OLE_YSIZE_HIMETRIC hmHeight; 

	pPic->get_Width(&hmWidth); 

	pPic->get_Height(&hmHeight); 

	double fX;
	double fY;

	fX=jilu1;

	fY=jilu2; 

	
	//fX = (double)pDC->GetDeviceCaps(HORZRES)*(double)hmWidth/((double)pDC->GetDeviceCaps(HORZSIZE)*100.0); 

	//fY = (double)pDC->GetDeviceCaps(VERTRES)*(double)hmHeight/((double)pDC->GetDeviceCaps(VERTSIZE)*100.0); 

	if(FAILED(pPic->Render(*pDC,jilu1*i,jilu2*j,(DWORD)fX,(DWORD)fY,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		AfxMessageBox("Failed To Render The picture!"); 

	pPic->Release(); 

	} 

	else 

	AfxMessageBox("Error Loading Picture From Stream!"); 

} 

} 

} 

else 

AfxMessageBox("Can't Open Image File!"); 

}


void CPintu1View::draw8(CDC *pDC,int i,int j)
{
	IPicture *pPic; 

	IStream *pStm; 

	CFileStatus fstatus; 

	CFile file; 

	LONG cb; 

	if (file.Open("8.jpg",CFile::modeRead)&&file.GetStatus("8.jpg", fstatus)&& ((cb = fstatus.m_size) != -1)) 

	{ 

	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb); 

	LPVOID pvData = NULL; 

	if (hGlobal != NULL) 

	{ 

	if ((pvData = GlobalLock(hGlobal)) != NULL) 

	{ 

	file.ReadHuge(pvData, cb); 

	GlobalUnlock(hGlobal); 

	CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 

	if(SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic))) 

	{ 

	OLE_XSIZE_HIMETRIC hmWidth; 

	OLE_YSIZE_HIMETRIC hmHeight; 

	pPic->get_Width(&hmWidth); 

	pPic->get_Height(&hmHeight); 

	double fX;
	double fY;

	fX=jilu1;

	fY=jilu2; 

	
	//fX = (double)pDC->GetDeviceCaps(HORZRES)*(double)hmWidth/((double)pDC->GetDeviceCaps(HORZSIZE)*100.0); 

	//fY = (double)pDC->GetDeviceCaps(VERTRES)*(double)hmHeight/((double)pDC->GetDeviceCaps(VERTSIZE)*100.0); 

	if(FAILED(pPic->Render(*pDC,jilu1*i,jilu2*j,(DWORD)fX,(DWORD)fY,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		AfxMessageBox("Failed To Render The picture!"); 

	pPic->Release(); 

	} 

	else 

	AfxMessageBox("Error Loading Picture From Stream!"); 

} 

} 

} 

else 

AfxMessageBox("Can't Open Image File!"); 

}



void CPintu1View::draw9(CDC *pDC,int i,int j)
{
	IPicture *pPic; 

	IStream *pStm; 

	CFileStatus fstatus; 

	CFile file; 

	LONG cb; 

	if (file.Open("9.jpg",CFile::modeRead)&&file.GetStatus("9.jpg", fstatus)&& ((cb = fstatus.m_size) != -1)) 

	{ 

	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb); 

	LPVOID pvData = NULL; 

	if (hGlobal != NULL) 

	{ 

	if ((pvData = GlobalLock(hGlobal)) != NULL) 

	{ 

	file.ReadHuge(pvData, cb); 

	GlobalUnlock(hGlobal); 

	CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 

	if(SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic))) 

	{ 

	OLE_XSIZE_HIMETRIC hmWidth; 

	OLE_YSIZE_HIMETRIC hmHeight; 

	pPic->get_Width(&hmWidth); 

	pPic->get_Height(&hmHeight); 

	double fX;
	double fY;

	fX=jilu1;

	fY=jilu2; 

	
	//fX = (double)pDC->GetDeviceCaps(HORZRES)*(double)hmWidth/((double)pDC->GetDeviceCaps(HORZSIZE)*100.0); 

	//fY = (double)pDC->GetDeviceCaps(VERTRES)*(double)hmHeight/((double)pDC->GetDeviceCaps(VERTSIZE)*100.0); 

	if(FAILED(pPic->Render(*pDC,jilu1*i,jilu2*j,(DWORD)fX,(DWORD)fY,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		AfxMessageBox("Failed To Render The picture!"); 

	pPic->Release(); 

	} 

	else 

	AfxMessageBox("Error Loading Picture From Stream!"); 

} 

} 

} 

else 

AfxMessageBox("Can't Open Image File!"); 

}



void CPintu1View::drawwhite(CDC *pDC,int i,int j)
{
	IPicture *pPic; 

	IStream *pStm; 

	CFileStatus fstatus; 

	CFile file; 

	LONG cb; 

	if (file.Open("bai.jpg",CFile::modeRead)&&file.GetStatus("bai.jpg", fstatus)&& ((cb = fstatus.m_size) != -1)) 

	{ 

	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb); 

	LPVOID pvData = NULL; 

	if (hGlobal != NULL) 

	{ 

	if ((pvData = GlobalLock(hGlobal)) != NULL) 

	{ 

	file.ReadHuge(pvData, cb); 

	GlobalUnlock(hGlobal); 

	CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); 

	if(SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic))) 

	{ 

	OLE_XSIZE_HIMETRIC hmWidth; 

	OLE_YSIZE_HIMETRIC hmHeight; 

	pPic->get_Width(&hmWidth); 

	pPic->get_Height(&hmHeight); 

	double fX;
	double fY;

	fX=jilu1;

	fY=jilu2; 

	
	//fX = (double)pDC->GetDeviceCaps(HORZRES)*(double)hmWidth/((double)pDC->GetDeviceCaps(HORZSIZE)*100.0); 

	//fY = (double)pDC->GetDeviceCaps(VERTRES)*(double)hmHeight/((double)pDC->GetDeviceCaps(VERTSIZE)*100.0); 

	if(FAILED(pPic->Render(*pDC,jilu1*i,jilu2*j,(DWORD)fX,(DWORD)fY,0,hmHeight,hmWidth,-hmHeight,NULL))) 
		AfxMessageBox("Failed To Render The picture!"); 

	pPic->Release(); 

	} 

	else 

	AfxMessageBox("Error Loading Picture From Stream!"); 

} 

} 

} 

else 

AfxMessageBox("Can't Open Image File!"); 

}