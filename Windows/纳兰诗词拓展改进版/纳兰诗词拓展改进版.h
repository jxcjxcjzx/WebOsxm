// ÄÉÀ¼Ê«´ÊÍØÕ¹¸Ä½ø°æ.h : main header file for the ÄÉÀ¼Ê«´ÊÍØÕ¹¸Ä½ø°æ application
//

#if !defined(AFX__H__E8B4819D_2371_4F53_8EDE_FEC7DCAA7621__INCLUDED_)
#define AFX__H__E8B4819D_2371_4F53_8EDE_FEC7DCAA7621__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyApp:
// See ÄÉÀ¼Ê«´ÊÍØÕ¹¸Ä½ø°æ.cpp for the implementation of this class
//

class CMyApp : public CWinApp
{
public:
	CMyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__H__E8B4819D_2371_4F53_8EDE_FEC7DCAA7621__INCLUDED_)
