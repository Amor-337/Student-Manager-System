// zhuce.cpp : implementation file
//

#include "stdafx.h"
#include "学生管理系统.h"
#include "zhuce.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Czhuce dialog


Czhuce::Czhuce(CWnd* pParent /*=NULL*/)
	: CDialog(Czhuce::IDD, pParent)
{
	//{{AFX_DATA_INIT(Czhuce)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	brush.CreateSolidBrush(RGB(112,67,194));
}


void Czhuce::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Czhuce)
	DDX_Control(pDX, IDC_BUTTON2, m_mybtzy);
	DDX_Control(pDX, IDOK, m_mybtok);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Czhuce, CDialog)
	//{{AFX_MSG_MAP(Czhuce)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Czhuce message handlers


BOOL Czhuce::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_mybtok.SetInactiveBgColor(RGB(49,239,33),TRUE);
	m_mybtok.SetInactiveFgColor(RGB(255,255,255),TRUE);
	m_mybtok.SetActiveBgColor(RGB(0,0,0));
	m_mybtok.SetActiveFgColor(RGB(255,255,255));

	m_mybtzy.SetInactiveBgColor(RGB(0,255,255),TRUE);
	m_mybtzy.SetInactiveFgColor(RGB(255,255,255),TRUE);
	m_mybtzy.SetActiveBgColor(RGB(0,0,0));
	m_mybtzy.SetActiveFgColor(RGB(255,255,255));
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH Czhuce::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	CFont font;
	// TODO: Change any attributes of the DC here
	if(pWnd->GetDlgCtrlID()==IDC_STATIC1||pWnd->GetDlgCtrlID()==IDC_STATIC2||
		pWnd->GetDlgCtrlID()==IDC_STATIC3||pWnd->GetDlgCtrlID()==IDC_STATIC4)
	{
		pDC->SetTextColor(RGB(255,0,0));
		pDC->SetBkMode(TRANSPARENT);
	}
	if(pWnd->GetDlgCtrlID()==IDC_EDIT1||pWnd->GetDlgCtrlID()==IDC_EDIT2||
		pWnd->GetDlgCtrlID()==IDC_EDIT3||pWnd->GetDlgCtrlID()==IDC_EDIT4)
	{
		pDC->SetTextColor(RGB(0,214,248));
		pDC->SetBkMode(TRANSPARENT);
	}


	if(pWnd->GetDlgCtrlID()==IDC_huanying)
	{
		font.CreatePointFont(200,"华文行楷",GetDC());
		pDC->SetTextColor(RGB(37,0,0));
		pDC->SetBkMode(TRANSPARENT);
		pDC->SelectObject(&font);
		font.DeleteObject();
	}

	if(pWnd->GetDlgCtrlID()==IDC_4||pWnd->GetDlgCtrlID()==IDC_1||pWnd->GetDlgCtrlID()==IDC_2||
		pWnd->GetDlgCtrlID()==IDC_3)
	{
		font.CreatePointFont(100,"华文行楷",GetDC());
		pDC->SetTextColor(RGB(37,0,0));
		pDC->SetBkMode(TRANSPARENT);
		pDC->SelectObject(&font);
		pDC->SetTextColor(RGB(255,255,255));
		font.DeleteObject();
	}
	// TODO: Return a different brush if the default is not desired
	if(pWnd->GetDlgCtrlID()!=IDC_EDIT1&&pWnd->GetDlgCtrlID()!=IDC_EDIT2&&
		pWnd->GetDlgCtrlID()!=IDC_EDIT3&&pWnd->GetDlgCtrlID()!=IDC_EDIT4)
		return brush;
	return hbr;
}

void Czhuce::OnButton2() 
{
	// TODO: Add your control notification handler code here
	Czhuyemian zy;
	CDialog::OnOK();
	zy.DoModal();
}

void Czhuce::OnOK() 
{
	// TODO: Add extra validation here
	CString strname;
	CString strnum;
	CString strmath;
	CString strgrad;
	CString tempstr;
	Conlyone oo;
	FILE *zc=fopen("个人信息文件.txt","a");
	int tagit=1;
	while(1&&tagit==1)
	{
		tagit=0;
		if(GetDlgItemText(IDC_EDIT1,strname),strname=="")
		{
			MessageBox("姓名不能有空值!");
			tagit=1;
			break;
		}
		if(GetDlgItemText(IDC_EDIT2,strnum),strnum=="")
		{
			MessageBox("学号不能有空值!");
			tagit=1;
			break;
		}
		if(GetDlgItemText(IDC_EDIT3,strmath),strmath=="")
		{
			MessageBox("专业不能有空值!");
			tagit=1;
			break;
		}
		if(GetDlgItemText(IDC_EDIT4,strgrad),strgrad=="")
		{
			MessageBox("班级不能有空值!");
			tagit=1;
			break;
		}
	//	sprintf(&tempstr,"%s %s %s %s",&strname,&strnum,&strmath,&strgrad);	
	}
	if(strname!=""&&strnum!=""&&strmath!=""&&strgrad!="")
	{
		fwrite(strnum+" "+strname+" "+strmath+" "+strgrad,1,strlen(strname)+3+strlen(strnum)+
			strlen(strmath)+strlen(strgrad)+strlen("\0"),zc);
		fwrite("\n",1,strlen("\n"),zc);
//		fwrite(strname+" ",1,strlen(strname)+strlen(" "),zc);
		CDialog::OnOK();
		oo.DoModal();
	}
	fclose(zc);
}
