// 1Doc.h : interface of the CMy1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_1DOC_H__B85A5E29_2735_46FA_986D_70677F9F603F__INCLUDED_)
#define AFX_1DOC_H__B85A5E29_2735_46FA_986D_70677F9F603F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy1Doc : public CDocument
{
protected: // create from serialization only
	CMy1Doc();
	DECLARE_DYNCREATE(CMy1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1DOC_H__B85A5E29_2735_46FA_986D_70677F9F603F__INCLUDED_)
