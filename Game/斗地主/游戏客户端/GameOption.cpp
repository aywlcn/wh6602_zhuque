#include "Stdafx.h"
#include "GameOption.h"
#include ".\gameoption.h"

//////////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(CGameOption, CSkinDialogEx)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////

//构造函数
CGameOption::CGameOption() : CSkinDialogEx(IDD_OPTION)
{
	//m_bDeasilOrder=true;
	m_bEnableSound=true;
	m_bAllowLookOn=false ;
	//m_dwCardHSpace=DEFAULT_PELS;

	return;
}

//析构函数
CGameOption::~CGameOption()
{
}

//控件绑定
void CGameOption::DoDataExchange(CDataExchange * pDX)
{
	__super::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_btOK);
	DDX_Control(pDX, IDCANCEL, m_btCancel);
}

//初始化函数
BOOL CGameOption::OnInitDialog()
{
	__super::OnInitDialog();

	//设置标题
	SetWindowText(TEXT("游戏配置"));

	//调整参数
	//if ((m_dwCardHSpace>MAX_PELS)||(m_dwCardHSpace<LESS_PELS)) m_dwCardHSpace=DEFAULT_PELS;

	//设置控件
	//if (m_bDeasilOrder==true) ((CButton *)GetDlgItem(IDC_DEASIL_ORDER))->SetCheck(BST_CHECKED);
	if (m_bEnableSound==true) ((CButton *)GetDlgItem(IDC_ENABLE_SOUND))->SetCheck(BST_CHECKED);
	if (m_bAllowLookOn==true) ((CButton *)GetDlgItem(IDC_ALLOW_LOOKON))->SetCheck(BST_CHECKED);

	//扑克象素
	//int nItem=0;
	//TCHAR szBuffer[32]=TEXT("");
	//CComboBox * pComboBox=(CComboBox *)GetDlgItem(IDC_CARD_SPACE);
	//for (DWORD i=LESS_PELS;i<=MAX_PELS;i++)
	//{
	//	_snprintf(szBuffer,sizeof(szBuffer),TEXT("%2ld"),i);
	//	nItem=pComboBox->InsertString((i-LESS_PELS),szBuffer);
	//	pComboBox->SetItemData(nItem,i);
	//	if (m_dwCardHSpace==i) pComboBox->SetCurSel(nItem);
	//}

	return TRUE;
}

//确定消息
void CGameOption::OnOK()
{
	//获取变量
	//m_bDeasilOrder=(((CButton *)GetDlgItem(IDC_DEASIL_ORDER))->GetCheck()==BST_CHECKED);
	m_bEnableSound=(((CButton *)GetDlgItem(IDC_ENABLE_SOUND))->GetCheck()==BST_CHECKED);
	m_bAllowLookOn = (((CButton *)GetDlgItem(IDC_ALLOW_LOOKON))->GetCheck()==BST_CHECKED);

	//扑克象素
	//CComboBox * pComboBox=(CComboBox *)GetDlgItem(IDC_CARD_SPACE);
	//m_dwCardHSpace=(DWORD)pComboBox->GetItemData(pComboBox->GetCurSel());

	__super::OnOK();
}

//////////////////////////////////////////////////////////////////////////

HBRUSH CGameOption::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CSkinDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	switch (pWnd->GetDlgCtrlID())  
	{     
	case IDC_ALLOW_LOOKON:   //为静态文本框的资源ID号  
	case IDC_ENABLE_SOUND:
	case IDC_STATIC:
		{      pDC->SetBkMode(TRANSPARENT);     
		pDC->SetTextColor(RGB(0,0,0));      
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);     
		Invalidate();     
		}     
		break;  
	}  

	return hbr;
}
