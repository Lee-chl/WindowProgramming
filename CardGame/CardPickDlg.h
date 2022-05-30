#pragma once


// CardPickDlg 대화 상자

class CCardPickDlg : public CDialog
{
	DECLARE_DYNAMIC(CCardPickDlg)

public:
	CCardPickDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCardPickDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_cardPick };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButtoncard1();
	afx_msg void OnClickedButtoncard2();
	afx_msg void OnClickedButtoncard3();
	afx_msg void OnClickedButtoncard4();
	afx_msg void OnClickedButtoncard5();
	afx_msg void OnClickedButtoncard6();
	afx_msg void OnClickedButtoncard7();
	afx_msg void OnClickedButtoncard8();
	afx_msg void OnClickedButtoncard9();
	afx_msg void OnClickedButtoncard10();
	afx_msg void OnClickedButtoncard11();
	afx_msg void OnClickedButtonChoice1();
	afx_msg void OnClickedButtonChoice2();


	CButton m_butChoice1;
	CButton m_butChoice2;
	void checkChoiceNum(int buttonNum);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	void randomNum();
	static CString m_strResultChoice;
	void finalChoice(CString choice);
};
