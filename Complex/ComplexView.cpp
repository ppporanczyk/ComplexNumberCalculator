
// ComplexView.cpp : implementation of the CComplexView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Complex.h"
#endif

#include "ComplexDoc.h"
#include "ComplexView.h"
#include "CComplexDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CComplexView

IMPLEMENT_DYNCREATE(CComplexView, CView)

BEGIN_MESSAGE_MAP(CComplexView, CView)
	ON_COMMAND(32771, &CComplexView::OnDlgCalc)
END_MESSAGE_MAP()

// CComplexView construction/destruction

CComplexView::CComplexView() noexcept
{
	// TODO: add construction code here

}

CComplexView::~CComplexView()
{
}

BOOL CComplexView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CComplexView drawing

void CComplexView::OnDraw(CDC* /*pDC*/)
{
	CComplexDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CComplexView diagnostics

#ifdef _DEBUG
void CComplexView::AssertValid() const
{
	CView::AssertValid();
}

void CComplexView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CComplexDoc* CComplexView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CComplexDoc)));
	return (CComplexDoc*)m_pDocument;
}
#endif //_DEBUG


// CComplexView message handlers


void CComplexView::OnDlgCalc()
{
	CComplexDlg dlg;
	dlg.DoModal();
}
