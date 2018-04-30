// pintu1Doc.h : interface of the CPintu1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PINTU1DOC_H__833E7B44_6EDD_4B55_B0A0_B57479CD5A2F__INCLUDED_)
#define AFX_PINTU1DOC_H__833E7B44_6EDD_4B55_B0A0_B57479CD5A2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPintu1Doc : public CDocument
{
protected: // create from serialization only
	CPintu1Doc();
	DECLARE_DYNCREATE(CPintu1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPintu1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPintu1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPintu1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PINTU1DOC_H__833E7B44_6EDD_4B55_B0A0_B57479CD5A2F__INCLUDED_)
