// pintu1.h : main header file for the PINTU1 application
//

#if !defined(AFX_PINTU1_H__397B3170_00E0_44E4_BD48_B642A4D14D03__INCLUDED_)
#define AFX_PINTU1_H__397B3170_00E0_44E4_BD48_B642A4D14D03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPintu1App:
// See pintu1.cpp for the implementation of this class
//

class CPintu1App : public CWinApp
{
public:
	CPintu1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPintu1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPintu1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PINTU1_H__397B3170_00E0_44E4_BD48_B642A4D14D03__INCLUDED_)
