
// ComplexView.h : interface of the CComplexView class
//

#pragma once


class CComplexView : public CView
{
protected: // create from serialization only
	CComplexView() noexcept;
	DECLARE_DYNCREATE(CComplexView)

// Attributes
public:
	CComplexDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CComplexView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDlgCalc();
};

#ifndef _DEBUG  // debug version in ComplexView.cpp
inline CComplexDoc* CComplexView::GetDocument() const
   { return reinterpret_cast<CComplexDoc*>(m_pDocument); }
#endif

