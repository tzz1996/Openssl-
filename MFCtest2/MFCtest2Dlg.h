
// MFCtest2Dlg.h : ͷ�ļ�
//

#pragma once
#include <string>
#include "VedioEncrypt.h"

using namespace std;

// CMFCtest2Dlg �Ի���
class CMFCtest2Dlg : public CDialogEx
{
private:
	CString input_string;
	CString output_string;
	int radio5 = 0;
	int radio6 = 0;
public:
	VedioEncrypt vedio_encrypt;


// ����
public:
	CMFCtest2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTEST2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
