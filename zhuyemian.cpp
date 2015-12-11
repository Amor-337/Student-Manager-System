//主页面  缑田田（2015.12.11）
// zhuyemian.cpp : implementation file
//

#include "stdafx.h"
#include "学生管理系统.h"
#include "zhuyemian.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Czhuyemian dialog


Czhuyemian::Czhuyemian(CWnd* pParent /*=NULL*/)
	: CDialog(Czhuyemian::IDD, pParent)
{
	//{{AFX_DATA_INIT(Czhuyemian)
	m_value = -1;
	//}}AFX_DATA_INIT
	m_value=-1;
	brush.CreateSolidBrush(RGB(255,196,255));
}


void Czhuyemian::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Czhuyemian)
	DDX_Control(pDX, IDCANCEL, m_mybtcc);
	DDX_Control(pDX, IDOK, m_mybtok);
	DDX_Radio(pDX, IDC_RADIO1, m_value);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Czhuyemian, CDialog)
	//{{AFX_MSG_MAP(Czhuyemian)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Czhuyemian message handlers

void Czhuyemian::OnOK() 
{
	// TODO: Add extra validation here
	Cxinxichuangkou xk;
	Czengjiashuju add;
	Cxiugaishuju modify;
	Czhanghuxiugai zg;
	Cchengjichaxun cj;
	Cshanchushuju ss;
	Conlyone oo;
	UpdateData();
	if(m_value==-1)
		MessageBox("请选择");
	else
	{
		CDialog::OnCancel();
	switch(m_value)
	{
	case 0:
		xk.DoModal();//DoModal()建立对话框窗口并显示窗口
		break;
	case 1:
		add.DoModal();
		break;
	case 2:
		modify.DoModal();
		break;
	case 3:
		zg.DoModal();
		break;
	case 4:
		cj.DoModal();
		break;
	case 5:
		ss.DoModal();
		break;
	case 6:
		oo.DoModal();
	}
	}
}

HBRUSH Czhuyemian::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	CFont font;
	// TODO: Change any attributes of the DC here
	if(pWnd->GetDlgCtrlID()==IDC_STATIC1)
	{
		font.CreatePointFont(200,"华文行楷",GetDC());
		pDC->SelectObject(&font);
		pDC->SetTextColor(RGB(0,0,255));
		pDC->SetBkMode(TRANSPARENT);
		font.DeleteObject();
	}
	if(pWnd->GetDlgCtrlID()==IDC_STATIC2)
	{
		font.CreatePointFont(100,"华文行楷",GetDC());
		pDC->SelectObject(&font);
		pDC->SetTextColor(RGB(0,0,0));
		pDC->SetBkMode(TRANSPARENT);
		font.DeleteObject();
	}
	if(pWnd->GetDlgCtrlID()==IDC_RADIO1||pWnd->GetDlgCtrlID()==IDC_RADIO2||
		pWnd->GetDlgCtrlID()==IDC_RADIO3||pWnd->GetDlgCtrlID()==IDC_RADIO4||
		pWnd->GetDlgCtrlID()==IDC_RADIO5||pWnd->GetDlgCtrlID()==IDC_RADIO6||
		pWnd->GetDlgCtrlID()==IDC_RADIO7)
	{
		pDC->SetTextColor(RGB(20,180,12));
		pDC->SetBkMode(TRANSPARENT);
		font.DeleteObject();
	}
	// TODO: Return a different brush if the default is not desired
	return brush;
}

BOOL Czhuyemian::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_mybtok.SetInactiveBgColor(RGB(49,239,33),TRUE);
	m_mybtok.SetInactiveFgColor(RGB(255,255,255),TRUE);
	m_mybtok.SetActiveBgColor(RGB(0,0,0));
	m_mybtok.SetActiveFgColor(RGB(255,255,255));

	m_mybtcc.SetInactiveBgColor(RGB(0,0,255),TRUE);
	m_mybtcc.SetInactiveFgColor(RGB(255,255,255),TRUE);
	m_mybtcc.SetActiveBgColor(RGB(0,0,0));
	m_mybtcc.SetActiveFgColor(RGB(255,255,255));
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
