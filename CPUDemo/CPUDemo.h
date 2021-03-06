//////////////////////////////////////////////////////////////////////////////
// 类名：CCPUDemo
// 功能：应用程序的初始化
// 说明：在此加入动态菲屏显示(每次启动程序时菲屏以不同方式显示)
// 作者：徐景周(johnny Xu, xujingzhou2016@gmail.com)
// 组织：未来工作室(Future Studio)
// 日期：2003.1.1
/////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_CPUDEMO_H__1E013B25_3301_11D7_AA35_EA02DB2FF40A__INCLUDED_)
#define AFX_CPUDEMO_H__1E013B25_3301_11D7_AA35_EA02DB2FF40A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCPUDemoApp:
// See CPUDemo.cpp for the implementation of this class
//

class CCPUDemoApp : public CWinApp
{
public:
	CCPUDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCPUDemoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCPUDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPUDEMO_H__1E013B25_3301_11D7_AA35_EA02DB2FF40A__INCLUDED_)
