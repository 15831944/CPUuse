//////////////////////////////////////////////////////////////////////////////
//类名：CCPUDemoDlg
//功能：CPU利用率组件示例程序(客户端)
//作者：徐景周(johnny Xu, xujingzhou2016@gmail.com)
//组织：未来工作室(Future Studio)
//日期：2003.1.1
/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "CPUDemo.h"
#include "CPUDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "..\\CPUuse\\CPUuse.h"
#include "..\\CPUuse\\CPUuse_i.c"

CComPtr<ICpuUsage> ptrCpuUsage;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CPictureEx	m_Flag;				// GIF动态图像显示
	CHyperLink	m_Mail;				// 超链接形式显示EMAIL
	CWinXPButtonST	m_OK;			// XP风格按钮
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Control(pDX, IDC_FLAG, m_Flag);
	DDX_Control(pDX, IDC_STATIC_MAIL, m_Mail);
	DDX_Control(pDX, IDOK, m_OK);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////
//名称：OnInitDialog
//功能：初始化"关于"对话框
//作者：徐景周(xujingzhou2016@gmail.com)
//组织：未来工作室(Future Studio)
//日期：2003.1.1
/////////////////////////////////////////////////////////////////////////////
BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	//设置“关于”对话框的XP风格按钮显示
	m_OK.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_OK.SetBkColor(RGB(160,180,220));
	m_OK.SetRounded(TRUE);
	m_OK.SetTooltipText(_T("关闭"));

	//加入EMAIL的超连接
    m_Mail.SetURL(_T("mailto:xujingzhou2016@gmail.com"));
	m_Mail.SetUnderline(FALSE);	

	//显示动态GIF图像logo
	if(m_Flag.Load(MAKEINTRESOURCE(IDR_FLAG),_T("GIF")))
	{
		m_Flag.SetBkColor(RGB(160,180,220));
		m_Flag.Draw();	
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/////////////////////////////////////////////////////////////////////////////
// CCPUDemoDlg dialog
CCPUDemoDlg::CCPUDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCPUDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCPUDemoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCPUDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCPUDemoDlg)
	DDX_Control(pDX, IDC_SYSTEMTYPE, m_SystemType);
	DDX_Control(pDX, IDC_PROGRESS, m_Progress);
	DDX_Control(pDX, IDOK, m_OK);
	DDX_Control(pDX, IDCANCEL, m_Cancel);
	DDX_Control(pDX, ID_ABOUT, m_About);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCPUDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CCPUDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_ABOUT, OnAbout)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCPUDemoDlg message handlers
//////////////////////////////////////////////////////////////////////////////
//名称：OnInitDialog
//功能：初始化对话框
//作者：徐景周(jingzhou_xu@163.net)
//组织：未来工作室(Future Studio)
//日期：2002.12.1
/////////////////////////////////////////////////////////////////////////////
BOOL CCPUDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// 在此设置XP风格按钮
	m_OK.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_OK.SetBkColor(RGB(162,189,252));
	m_OK.SetRounded(TRUE);
	m_OK.SetTooltipText(_T("检测"));

	m_Cancel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_Cancel.SetBkColor(RGB(162,189,252));
	m_Cancel.SetRounded(TRUE);
	m_Cancel.SetTooltipText(_T("退出"));

	m_About.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	m_About.SetBkColor(RGB(162,189,252));
	m_About.SetRounded(TRUE);
	m_About.SetTooltipText(_T("关于"));

	// 在此初始化渐变色进度条
	m_Progress.SetRange32(0,100);
    m_Progress.SetBkColor(RGB(160,180,220));
	m_Progress.ShowPercent(true);	
	m_Progress.SetPos(0);

	//使用程序窗体总在最前方
	SetWindowPos(&wndTopMost,0,0,0,0, SWP_NOMOVE | SWP_NOSIZE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCPUDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
void CCPUDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCPUDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

////////////////////////////////////////////////////////////////////////////
//名称：OnAbout
//功能：弹出"关于"对话框
//作者：徐景周(jingzhou_xu@163.net)
//组织：未来工作室(Future Studio)
//日期：2003.1.1
/////////////////////////////////////////////////////////////////////////////
void CCPUDemoDlg::OnAbout() 
{
	CAboutDlg dlg;
	dlg.DoModal();
}

////////////////////////////////////////////////////////////////////////////
//名称：OnOK
//功能：检测CPU利用率及系统版本
//作者：徐景周(jingzhou_xu@163.net)
//组织：未来工作室(Future Studio)
//日期：2003.1.1
/////////////////////////////////////////////////////////////////////////////
void CCPUDemoDlg::OnOK() 
{
	// 置灰检测按钮
	CButton *pButton = (CButton*)GetDlgItem(IDOK);
	pButton->EnableWindow(FALSE);

	// 创建组件实例
	HRESULT hr;
	hr = CoCreateInstance(CLSID_CpuUsage,
						  NULL,
						  CLSCTX_SERVER,
						  IID_ICpuUsage,
						  (void**)&ptrCpuUsage);

	if(FAILED(hr))
	{
		AfxMessageBox("创建ICpuUsage实例失败!");
		return ;
	}

	// 获取当前操作系统版本
	BSTR bstrSysType;
	hr = ptrCpuUsage->IsShellSystemType(&bstrSysType);
	if(hr == S_FALSE)
	{
		AfxMessageBox("获取系统版本接口涵数出错!");
		return;
	}
	USES_CONVERSION;
	m_SystemType.SetWindowText(OLE2T(bstrSysType));
	m_strSystemType = OLE2T(bstrSysType);

	// 获取当前CPU利用率,在OnTimer()中实现
	SetTimer(1,300,NULL);

	// 清除工作
	if(bstrSysType)
		SysFreeString(bstrSysType);
}

////////////////////////////////////////////////////////////////////////////
//名称：OnTimer
//功能：获取当前CPU利用率
//作者：徐景周(jingzhou_xu@163.net)
//组织：未来工作室(Future Studio)
//日期：2003.1.1
/////////////////////////////////////////////////////////////////////////////
void CCPUDemoDlg::OnTimer(UINT nIDEvent) 
{
	switch(nIDEvent)
	{
		case 1:
			long lResult;
			CString strResult;
			HRESULT hr;
			if(m_strSystemType == "Windows95" || m_strSystemType == "Windows98")
				hr = ptrCpuUsage->CpuUsage9x(&lResult);
			else
				hr = ptrCpuUsage->CpuUsage2000(&lResult);

			if(hr == S_FALSE)
			{
				AfxMessageBox("获取系统版本接口涵数出错!");
				return;
			}

			strResult.Format("%d", lResult);

			m_Progress.SetPos(atoi(strResult));

			break;
	}
	
	CDialog::OnTimer(nIDEvent);
}

////////////////////////////////////////////////////////////////////////////
//名称：DestroyWindow
//功能：退出时清除工作
//作者：徐景周(jingzhou_xu@163.net)
//组织：未来工作室(Future Studio)
//日期：2003.1.1
/////////////////////////////////////////////////////////////////////////////
BOOL CCPUDemoDlg::DestroyWindow() 
{
	KillTimer(1);

	if(ptrCpuUsage)
		ptrCpuUsage.Release();
		
	return CDialog::DestroyWindow();
}
