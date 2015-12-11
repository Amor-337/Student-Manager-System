
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
