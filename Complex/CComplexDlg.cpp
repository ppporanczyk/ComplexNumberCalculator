// CComplexDlg.cpp : implementation file
//

#include "pch.h"
#include "Complex.h"
#include "CComplex.h"
#include "CComplexDlg.h"
#include "afxdialogex.h"
#include <sstream>

// CComplexDlg dialog

IMPLEMENT_DYNAMIC(CComplexDlg, CDialog)

CComplexDlg::CComplexDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(ID_CALCULATOR, pParent), m_Im(0), m_Im2(0), m_Re(0), m_Re2(0)
{}

CComplexDlg::~CComplexDlg()
{}

void CComplexDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, ID_DIVIDE, m_Divide);
	DDX_Control(pDX, ID_MODULE, m_Module);
	DDX_Control(pDX, ID_MULTI, m_Multi);
	DDX_Control(pDX, ID_MINUS, m_Minus);
	DDX_Text(pDX, ID_IM, m_Im);
	DDX_Text(pDX, ID_IM2, m_Im2);
	DDX_Text(pDX, ID_RE, m_Re);
	DDX_Text(pDX, ID_RE2, m_Re2);
	DDX_Control(pDX, ID_PLUS, m_Plus);
}


BEGIN_MESSAGE_MAP(CComplexDlg, CDialog)
	ON_BN_CLICKED(ID_CLOSE, &CComplexDlg::OnBnClickedClose)
	ON_BN_CLICKED(ID_PLUS, &CComplexDlg::OnBnClickedPlus)
	ON_BN_CLICKED(ID_MINUS, &CComplexDlg::OnBnClickedMinus)
	ON_BN_CLICKED(ID_MULTI, &CComplexDlg::OnBnClickedMulti)
	ON_BN_CLICKED(ID_DIVIDE, &CComplexDlg::OnBnClickedDivide)
	ON_BN_CLICKED(ID_MODULE, &CComplexDlg::OnBnClickedModule)
	ON_BN_CLICKED(ID_COMP, &CComplexDlg::OnBnClickedComp)
	ON_BN_CLICKED(ID_RESET, &CComplexDlg::OnBnClickedReset)
END_MESSAGE_MAP()


void CComplexDlg::OnBnClickedClose()
{
	UpdateData();
	CDialog::OnOK();
}


void CComplexDlg::OnBnClickedPlus()
{	
	UpdateData();

	CComplex com1 = CComplex(m_Re, m_Im);
	CComplex com2 = CComplex(m_Re2, m_Im2);
	
	CComplex com(com1 + com2);

	CCanonComplex ccom = CCanonComplex(com);
	CString str = ccom.wypisanie();
	CWnd* pWnd = GetDlgItem(ID_RESULT);
	pWnd->SetWindowTextW(str);
}


void CComplexDlg::OnBnClickedMinus()
{
	UpdateData();
	CComplex com1 = CComplex(m_Re, m_Im);
	CComplex com2 = CComplex(m_Re2, m_Im2);

	CComplex com(com1 - com2);

	CCanonComplex ccom = CCanonComplex(com);
	CString str=ccom.wypisanie();
	CWnd* pWnd = GetDlgItem(ID_RESULT);
	pWnd->SetWindowTextW(str);
}


void CComplexDlg::OnBnClickedMulti()
{
	UpdateData();
	CComplex com1 = CComplex(m_Re, m_Im);
	CComplex com2 = CComplex(m_Re2, m_Im2);

	CComplex com(com1 * com2);

	CCanonComplex ccom = CCanonComplex(com);
	CString str = ccom.wypisanie();
	CWnd* pWnd = GetDlgItem(ID_RESULT);
	pWnd->SetWindowTextW(str);
}


void CComplexDlg::OnBnClickedDivide()
{
	UpdateData();
	CComplex com1 = CComplex(m_Re, m_Im);
	CComplex com2 = CComplex(m_Re2, m_Im2);

	CComplex com(com1 / com2);

	CCanonComplex ccom = CCanonComplex(com);
	CString str = ccom.wypisanie();
	CWnd* pWnd = GetDlgItem(ID_RESULT);
	pWnd->SetWindowTextW(str);
}


void CComplexDlg::OnBnClickedModule()
{
	UpdateData();
	
	CComplex com;

	if(!m_Re && !m_Im && (m_Re2 || m_Im2))
		com = CComplex(m_Re2, m_Im2);
	else if((!m_Re2 && !m_Im2) || ( m_Re== m_Re2 && m_Im == m_Im2))
		com = CComplex(m_Re, m_Im);
	else {
		AfxMessageBox(L"Wprowadz jedna liczbe!");
		return;
	}
	CString str; str.Format(L"%.2f", com.Module());

	CWnd* pWnd = GetDlgItem(ID_RESULT);
	pWnd->SetWindowTextW(str);
}


void CComplexDlg::OnBnClickedComp()
{
	UpdateData();

	CComplex com;

	if (!m_Re && !m_Im && (m_Re2 || m_Im2))
		com = CComplex(m_Re2, m_Im2);
	else if ((!m_Re2 && !m_Im2) || (m_Re == m_Re2 && m_Im == m_Im2))
		com = CComplex(m_Re, m_Im);
	else {
		AfxMessageBox(L"Wprowadz jedna liczbe!");
		return;
	}

	com.Coupled();

	CCanonComplex ccom = CCanonComplex(com);
	CString str = ccom.wypisanie();
	CWnd* pWnd = GetDlgItem(ID_RESULT);
	pWnd->SetWindowTextW(str);
}


void CComplexDlg::OnBnClickedReset()
{
	UpdateData();
	CString str; str.Format(L"%d", 0);
	GetDlgItem(ID_RE)->SetWindowTextW(str);
	GetDlgItem(ID_RE2)->SetWindowTextW(str);
	GetDlgItem(ID_IM)->SetWindowTextW(str);
	GetDlgItem(ID_IM2)->SetWindowTextW(str);

}
