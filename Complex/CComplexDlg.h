#pragma once


class CComplexDlg : public CDialog
{
	DECLARE_DYNAMIC(CComplexDlg)

public:
	CComplexDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CComplexDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = ID_CALCULATOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:

public:
	afx_msg void OnBnClickedClose();
private:
	CButton m_Divide;
	CButton m_Module;
	CButton m_Multi;
	CButton m_Minus;
	double m_Im;
	double m_Im2;
	double m_Re;
	double m_Re2;
	CButton m_Plus;
public:
	afx_msg void OnBnClickedPlus();
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedMulti();
	afx_msg void OnBnClickedDivide();
	afx_msg void OnBnClickedModule();
	afx_msg void OnBnClickedComp();
	afx_msg void OnBnClickedReset();
};
