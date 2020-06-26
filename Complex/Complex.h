
// Complex.h : main header file for the Complex application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CComplexApp:
// See Complex.cpp for the implementation of this class
//

class CComplexApp : public CWinApp
{
public:
	CComplexApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CComplexApp theApp;
