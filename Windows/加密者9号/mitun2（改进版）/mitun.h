// mitun.h : main header file for the MITUN application
//

#if !defined(AFX_MITUN_H__4401F634_50BB_4AFF_B120_FC6F444EC3EE__INCLUDED_)
#define AFX_MITUN_H__4401F634_50BB_4AFF_B120_FC6F444EC3EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMitunApp:
// See mitun.cpp for the implementation of this class
//

class CMitunApp : public CWinApp
{
public:
	CMitunApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMitunApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMitunApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MITUN_H__4401F634_50BB_4AFF_B120_FC6F444EC3EE__INCLUDED_)
