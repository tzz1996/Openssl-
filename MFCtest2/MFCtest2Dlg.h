
// MFCtest2Dlg.h : 头文件
//

#pragma once
#include <string>
#include "VedioEncrypt.h"

using namespace std;

// CMFCtest2Dlg 对话框
class CMFCtest2Dlg : public CDialogEx
{
private:
	CString input_string;
	CString output_string;
	int radio5 = 0;
	int radio6 = 0;
public:
	VedioEncrypt vedio_encrypt;


// 构造
public:
	CMFCtest2Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTEST2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
};
