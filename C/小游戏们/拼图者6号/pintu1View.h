// pintu1View.h : interface of the CPintu1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PINTU1VIEW_H__F7640F9C_05E5_4527_82DD_50EBDB1235AC__INCLUDED_)
#define AFX_PINTU1VIEW_H__F7640F9C_05E5_4527_82DD_50EBDB1235AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPintu1View : public CView
{
protected: // create from serialization only
	CPintu1View();
	DECLARE_DYNCREATE(CPintu1View)
    double jilu1;
	double jilu2;
	CRect rect; 
	int pintu[4][4];
	int biaoji[10];
	int weizhix;
	int weizhiy;
	int jix;
	int jiy;
// Attributes
public:
	CPintu1Doc* GetDocument();
	void draw1(CDC *pDC,int i,int j);
	void draw2(CDC *pDC,int i,int j);
	void draw3(CDC *pDC,int i,int j);
	void draw4(CDC *pDC,int i,int j);
	void draw5(CDC *pDC,int i,int j);
	void draw6(CDC *pDC,int i,int j);
	void draw7(CDC *pDC,int i,int j);
	void draw8(CDC *pDC,int i,int j);
	void draw9(CDC *pDC,int i,int j);
	void drawwhite(CDC *pDC,int i,int j);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPintu1View)
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
	virtual ~CPintu1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPintu1View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in pintu1View.cpp
inline CPintu1Doc* CPintu1View::GetDocument()
   { return (CPintu1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PINTU1VIEW_H__F7640F9C_05E5_4527_82DD_50EBDB1235AC__INCLUDED_)
