// ÔÄ¶Á¼ÇÂ¼Æ÷9ºÅ.h : main header file for the ÔÄ¶Á¼ÇÂ¼Æ÷9ºÅ application
//

#if !defined(AFX_9_H__0B40E9BA_D319_4EF1_B37B_64F447B3CF1B__INCLUDED_)
#define AFX_9_H__0B40E9BA_D319_4EF1_B37B_64F447B3CF1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy9App:
// See ÔÄ¶Á¼ÇÂ¼Æ÷9ºÅ.cpp for the implementation of this class
//

class CMy9App : public CWinApp
{
public:
	CMy9App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy9App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy9App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_9_H__0B40E9BA_D319_4EF1_B37B_64F447B3CF1B__INCLUDED_)
