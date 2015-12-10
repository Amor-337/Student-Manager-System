# Student-Manager-System
//  曹姣姣 登陆界面（2015.12.9）
// 学生管理系统Dlg.cpp : implementation file
//

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
	: CDialog(CMyDlg::IDD, pParent)
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

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
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

void CMyDlg::OnOK() 
{
	// TODO: Add extra validation here
	CString str;
	Czhuyemian zy;
	if((GetDlgItem(IDC_EDIT1)->GetWindowText(str),str=="曹姣姣")&&
		(GetDlgItem(IDC_EDIT2)->GetWindowText(str),str=="941107"))
	{
		CDialog::OnOK();
		zy.DoModal();
	}
	else
		MessageBox("信息有误!");
}

void CMyDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	Czhuce zc;
	CDialog::OnOK();
	zc.DoModal();
}

HBRUSH CMyDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	CFont font;
	// TODO: Change any attributes of the DC here
	if(pWnd->GetDlgCtrlID()==IDC_STATIC1)
	{
		font.CreatePointFont(200,"华文行楷",GetDC());
		pDC->SetTextColor(RGB(255,255,255));
		pDC->SetBkMode(TRANSPARENT);
		pDC->SelectObject(&font);
//		font.DeleteObject();
	}

	((CEdit*)(GetDlgItem(IDC_EDIT2)))->SetPasswordChar('*');
	if(pWnd->GetDlgCtrlID()==IDC_EDIT1||pWnd->GetDlgCtrlID()==IDC_EDIT2)
	{
		font.CreatePointFont(90,"华文行楷",GetDC());
		pDC->SetTextColor(RGB(255,255,255));
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,100,255));
		pDC->SelectObject(&font);
    	font.DeleteObject();
	}

	if(pWnd->GetDlgCtrlID()==IDC_STATIC3||pWnd->GetDlgCtrlID()==IDC_STATIC2)
	{
		font.CreatePointFont(120,"华文行楷",GetDC());
		pDC->SetTextColor(RGB(255,255,255));
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255,255,0));
		pDC->SelectObject(&font);
//		font.DeleteObject();
	}
	// TODO: Return a different brush if the default is not desired
	if(pWnd->GetDlgCtrlID()!=IDC_EDIT1&&pWnd->GetDlgCtrlID()!=IDC_EDIT2)
		return brush;
	else return hbr;
}

//高贝贝  信息查询（2015.12.10）
// xinxichuangkou.cpp : implementation file
//

#include "stdafx.h"
#include "学生管理系统.h"
#include "xinxichuangkou.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cxinxichuangkou dialog


Cxinxichuangkou::Cxinxichuangkou(CWnd* pParent /*=NULL*/)
	: CDialog(Cxinxichuangkou::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cxinxichuangkou)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Cxinxichuangkou::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cxinxichuangkou)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cxinxichuangkou, CDialog)
	//{{AFX_MSG_MAP(Cxinxichuangkou)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cxinxichuangkou message handlers

void Cxinxichuangkou::OnOK() 
{
	// TODO: Add extra validation here
	Czhuyemian ye;
	CDialog::OnCancel();
	ye.DoModal();
}

BOOL Cxinxichuangkou::OnInitDialog() 
{
	CDialog::OnInitDialog();
	FILE *file=fopen("成绩文件.txt","r");
	char rdname[100]={""};
	char tem[1];
	int i=0;
	while(1)
	{
		if(!feof(file))
		{
			fread(tem,sizeof(char),1,file);
			if(tem[0]!='\n')
				rdname[i++]=tem[0];
			if(tem[0]=='\n'&&rdname[0]!=' ')
			{
				((CListBox*)GetDlgItem(IDC_LIST1))->AddString(rdname);
				i=0;
				for(i=0;i<=99;i++)
					rdname[i]=' ';
				i=0;
			}
		}
		else 
			break;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Cxinxichuangkou::OnSelchangeList1() 
{
	// TODO: Add your control notification handler code here
	char ret[200]={""};
	char shuxue[10]={""};
	char yingyu[10]={""};
	char yuwen[10]={""};
	char zonghe[10]={""};
	char name[30]={""};
	char pj11[10]={""};
	int i;
	int tagit=1;
	int boxlen;
	int j=0;
	int sx;
	int yy;
	int yw;
	int zh;	
	float pjf11=0;
	int sum=0;
	int surc;
	i=((CListBox*)GetDlgItem(IDC_LIST1))->GetCurSel();
	surc=i;
	((CListBox*)GetDlgItem(IDC_LIST1))->GetText(i,ret);
	boxlen=strlen(ret);
	i=0;
	while(ret[i]!=' ')
	{
		name[i]=ret[i];
		i++;
	}
	i++;
	j=0;
	while(ret[i]!=' ')	
	{
		shuxue[j++]=ret[i];
		i++;
	}
	sx=atoi(shuxue);
	GetDlgItem(IDC_EDIT2)->SetWindowText(shuxue);
	i++;
	j=0;
	while(ret[i]!=' ')
	{
		yingyu[j++]=ret[i];
		i++;
	}
	yy=atoi(yingyu);
	GetDlgItem(IDC_EDIT1)->SetWindowText(yingyu);
	i++;
	j=0;
	while(ret[i]!=' ')
	{
		yuwen[j++]=ret[i];
		i++;
	}
	yw=atoi(yuwen);
	GetDlgItem(IDC_EDIT3)->SetWindowText(yuwen);
	i++;
	j=0;
	while(i<boxlen)
		zonghe[j++]=ret[i++];
	zh=atoi(zonghe);
	int sumone;
	sumone=sx+yy+yw+zh;
	sum=int(sx+yy+yw+zh)/4;
	char sum1[10]={""};
	char xiaoshu[3]={""};
	int xiao;
	xiao=(float(sx+yy+yw+zh)/float(4)-int((sx+yy+yw+zh)/4))*1000;
	itoa(xiao,xiaoshu,10);
	itoa(sum,sum1,10);
	char xin[10];
	GetDlgItem(IDC_EDIT4)->SetWindowText(zonghe);
	sprintf(xin,".%s",xiaoshu);
	GetDlgItem(IDC_EDIT5)->SetWindowText(sum1);
	sprintf(xiaoshu,"%s%s",sum1,xin);
	GetDlgItem(IDC_EDIT5)->SetWindowText(xiaoshu);
	/*mingci*/
	int mingci=1;
	int renshu;
	int sumall;
	int k;
	renshu=((CListBox*)GetDlgItem(IDC_LIST1))->GetCount();
	mingci=renshu;
	for(k=0;k<renshu;k++)
	{
		sx=0;
		yy=0;
		yw=0;
		zh=0;
		for(i=0;i<200;i++)
			ret[i]=' ';
		sumall=0;
		((CListBox*)GetDlgItem(IDC_LIST1))->GetText(k,ret);
		boxlen=strlen(ret);
		i=0;
		while(ret[i]!=' ')
		{
			name[i]=ret[i];
			i++;
		}
		i++;
		j=0;
		while(ret[i]!=' ')	
		{
			shuxue[j++]=ret[i];
			i++;
		}		
		sx=atoi(shuxue);
		i++;
		j=0;
		while(ret[i]!=' ')
		{
			yingyu[j++]=ret[i];
			i++;
		}
		yy=atoi(yingyu);
		i++;
		j=0;
		while(ret[i]!=' ')
		{
			yuwen[j++]=ret[i];
			i++;
		}
		yw=atoi(yuwen);
		i++;
		j=0;
		while(i<boxlen)
			zonghe[j++]=ret[i++];
		zh=atoi(zonghe);
		sumall=sx+yy+yw+zh;
		if(sumone>sumall)
			mingci--;
	}
	char mingcic[10];
	itoa(mingci,mingcic,10);
	GetDlgItem(IDC_EDIT6)->SetWindowText(mingcic);
}
