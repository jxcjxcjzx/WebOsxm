// pintu1Doc.cpp : implementation of the CPintu1Doc class
//

#include "stdafx.h"
#include "pintu1.h"

#include "pintu1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPintu1Doc

IMPLEMENT_DYNCREATE(CPintu1Doc, CDocument)

BEGIN_MESSAGE_MAP(CPintu1Doc, CDocument)
	//{{AFX_MSG_MAP(CPintu1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPintu1Doc construction/destruction

CPintu1Doc::CPintu1Doc()
{
	// TODO: add one-time construction code here

}

CPintu1Doc::~CPintu1Doc()
{
}

BOOL CPintu1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPintu1Doc serialization

void CPintu1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPintu1Doc diagnostics

#ifdef _DEBUG
void CPintu1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPintu1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPintu1Doc commands
