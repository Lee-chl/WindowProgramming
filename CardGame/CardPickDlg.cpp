// CardPickDlg.cpp: 구현 파일
//

#include "pch.h"
#include "CardGame.h"
#include "CardPickDlg.h"
#include "afxdialogex.h"
#include <math.h>
#include <time.h>

//0부터 10까지의 숫자
#define MAX 11


// CardPickDlg 대화 상자

IMPLEMENT_DYNAMIC(CCardPickDlg, CDialog)

//선택한 횟수
int choiceNum = 0;
//선택한 숫자 1
CString choiceNum1;
//선택한 숫자 2
CString choiceNum2;
//랜덤 값 나눠주기 위한 배열
int save[MAX];
//최종 선택 값
CString CCardPickDlg::m_strResultChoice;


CCardPickDlg::CCardPickDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_cardPick, pParent)
{

}

CCardPickDlg::~CCardPickDlg()
{
}

void CCardPickDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_resultChoice, m_strChioceRes);
	DDX_Control(pDX, IDC_BUTTON_choice1, m_butChoice1);
	DDX_Control(pDX, IDC_BUTTON_choice2, m_butChoice2);
}


BEGIN_MESSAGE_MAP(CCardPickDlg, CDialog)
	ON_BN_CLICKED(IDC_but_card1, &CCardPickDlg::OnClickedButtoncard1)
	ON_BN_CLICKED(IDC_but_card2, &CCardPickDlg::OnClickedButtoncard2)
	ON_BN_CLICKED(IDC_but_card3, &CCardPickDlg::OnClickedButtoncard3)
	ON_BN_CLICKED(IDC_but_card4, &CCardPickDlg::OnClickedButtoncard4)
	ON_BN_CLICKED(IDC_but_card5, &CCardPickDlg::OnClickedButtoncard5)
	ON_BN_CLICKED(IDC_but_card6, &CCardPickDlg::OnClickedButtoncard6)
	ON_BN_CLICKED(IDC_but_card7, &CCardPickDlg::OnClickedButtoncard7)
	ON_BN_CLICKED(IDC_but_card8, &CCardPickDlg::OnClickedButtoncard8)
	ON_BN_CLICKED(IDC_but_card9, &CCardPickDlg::OnClickedButtoncard9)
	ON_BN_CLICKED(IDC_but_card10, &CCardPickDlg::OnClickedButtoncard10)
	ON_BN_CLICKED(IDC_but_card11, &CCardPickDlg::OnClickedButtoncard11)
	ON_BN_CLICKED(IDC_BUTTON_choice1, &CCardPickDlg::OnClickedButtonChoice1)
	ON_BN_CLICKED(IDC_BUTTON_choice2, &CCardPickDlg::OnClickedButtonChoice2)
	ON_WM_SYSCOMMAND()
END_MESSAGE_MAP()


// CardPickDlg 메시지 처리기


void CCardPickDlg::OnClickedButtoncard1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	checkChoiceNum(0);
	
}


void CCardPickDlg::OnClickedButtoncard2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	checkChoiceNum(1);
}


void CCardPickDlg::OnClickedButtoncard3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	checkChoiceNum(2);
}


void CCardPickDlg::OnClickedButtoncard4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	checkChoiceNum(3);
}


void CCardPickDlg::OnClickedButtoncard5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	checkChoiceNum(4);
}


void CCardPickDlg::OnClickedButtoncard6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	checkChoiceNum(5);
}


void CCardPickDlg::OnClickedButtoncard7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	checkChoiceNum(6);
}


void CCardPickDlg::OnClickedButtoncard8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	checkChoiceNum(7);
}


void CCardPickDlg::OnClickedButtoncard9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	checkChoiceNum(8);
}



void CCardPickDlg::OnClickedButtoncard10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	checkChoiceNum(9);
}


void CCardPickDlg::OnClickedButtoncard11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	checkChoiceNum(10);
}


void CCardPickDlg::OnClickedButtonChoice1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	finalChoice(choiceNum1);

	
}


void CCardPickDlg::OnClickedButtonChoice2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	finalChoice(choiceNum2);


}

//카드 고르고 값이 나오게 하는 함수
void CCardPickDlg::checkChoiceNum(int buttonNum)
{
	// TODO: 여기에 구현 코드 추가.
	if (choiceNum < 2) {
		if (choiceNum1.IsEmpty()) {
			//랜덤 값으로 저장
			randomNum();
			//값을 보이게 하기 위해 변수에 저장
			choiceNum1.Format(_T("%d"), save[buttonNum]);
			m_butChoice1.SetWindowTextW(choiceNum1);
			choiceNum++;
		}
		else if (choiceNum2.IsEmpty()) {
			choiceNum2.Format(_T("%d"), save[buttonNum]);
			m_butChoice2.SetWindowTextW(choiceNum2);
			choiceNum++;
		}
	}
	else {
		AfxMessageBox(_T("랜덤 두 카드를 선택하셨습니다. 맨 밑 버튼에서 선택해주세요"), MB_ICONSTOP);
	}
}


//종료, 재시작 시 초기화 해주기
void CCardPickDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nID == SC_CLOSE || nID == SC_RESTORE) {
		choiceNum = 0;
		choiceNum1.Empty();
		choiceNum2.Empty();
	}

	CDialog::OnSysCommand(nID, lParam);
}


//맨 처음 랜덤값 나눠주는 함수
void CCardPickDlg::randomNum()
{
	// TODO: 여기에 구현 코드 추가.
	int count = 0;
	int isSame = 0;
	int randomN = 0;


	srand(time(0));

	while (count < MAX) {
		isSame = 0;
		randomN = rand() % MAX; //0부터 10까지 출력
		//중복 검사
		for (int i = 0; i < count; i++) {
			if (randomN == save[i]) {
				//중복 있을때
				isSame = 1;
				break;
			}
		}
		//중복 없을 때 
		if (isSame == 0) {
			save[count] = randomN;
			count++;
		}
	}
}



void CCardPickDlg::finalChoice(CString choice)
{
	// TODO: 여기에 구현 코드 추가.
	if (choiceNum == 2) {
		choiceNum = 0;
		m_strResultChoice = choice;
		choiceNum1.Empty();
		choiceNum2.Empty();
		OnOK();
	}
	else {
		AfxMessageBox(_T("카드 두개를 먼저 선택해주세요."), MB_ICONSTOP);
	}
}
