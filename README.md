# Student-Manager-System
//登陆界面
#include "stdafx.h"
#include "学生管理系统.h"
#include "学生管理系统Dlg.h"
#include"zhuce.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
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
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)   //CDialog类是对话框的基类
{
	//{{AFX_DATA_INIT(CMyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	brush.CreateSolidBrush(RGB(36,130,234));
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Control(pDX, IDC_BUTTON1, m_mybtzc);
	DDX_Control(pDX, IDCANCEL, m_mybtcc);
	DDX_Control(pDX, IDOK, m_mybt);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog) //）消息映射

	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()    //OnInitDialog 在对话框显示时调用，缺省时返回TRUE
{
	CDialog::OnInitDialog();


	m_mybt.SetInactiveBgColor(RGB(49,239,33),TRUE);
	m_mybt.SetInactiveFgColor(RGB(255,255,255),TRUE);
	m_mybt.SetActiveBgColor(RGB(0,0,0));
	m_mybt.SetActiveFgColor(RGB(255,255,255));

	m_mybtcc.SetInactiveBgColor(RGB(49,239,33),TRUE);
	m_mybtcc.SetInactiveFgColor(RGB(255,255,255),TRUE);
	m_mybtcc.SetActiveBgColor(RGB(0,0,0));
	m_mybtcc.SetActiveFgColor(RGB(255,255,255));

	m_mybtzc.SetInactiveBgColor(RGB(49,100,0),TRUE);
	m_mybtzc.SetInactiveFgColor(RGB(255,255,255),TRUE);
	m_mybtzc.SetActiveBgColor(RGB(0,0,0));
	m_mybtzc.SetActiveFgColor(RGB(255,255,255));
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
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyDlg::OnPaint() 
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
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


	else return hbr;
}
