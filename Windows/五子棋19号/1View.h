// 1View.h : interface of the CMy1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_1VIEW_H__66053DCC_9211_4F45_B0C1_1432F92F68E7__INCLUDED_)
#define AFX_1VIEW_H__66053DCC_9211_4F45_B0C1_1432F92F68E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy1View : public CView
{
protected: // create from serialization only
	CMy1View();
	DECLARE_DYNCREATE(CMy1View)

// Attributes
public:
	int ii;
	int biaozhi;
	int jj;
	CMy1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy1View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 1View.cpp
inline CMy1Doc* CMy1View::GetDocument()
   { return (CMy1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1VIEW_H__66053DCC_9211_4F45_B0C1_1432F92F68E7__INCLUDED_)
