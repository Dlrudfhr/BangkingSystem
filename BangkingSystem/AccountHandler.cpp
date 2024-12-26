#include "BankingCommonDecl.h"

using namespace std;

AccountHandler::AccountHandler() : customer(MAX_BUF_SIZE) {}
void AccountHandler::ShowMenu(void)
{
	std::cout << "-----MENU-----" << std::endl;
	std::cout << "1. 계좌 개설" << std::endl;
	std::cout << "2. 입     금" << std::endl;
	std::cout << "3. 출     금" << std::endl;
	std::cout << "4. 전체고객 잔액 조회" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
	std::cout << "기능 선택(1,2,3,4,5) : ";
}
void AccountHandler::MakeAccount(void)
{
	int choice;
	cout << "[계좌종류선택]\n" << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
	cout << "선택 : ";
	cin >> choice;

	(choice == ACCOUNT_KIND::NORMAL_ACCOUNT) ?
		MakeNormal() : MakeHighCredit();
}
void AccountHandler::MakeNormal()
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interestRate;

	std::cout << "[보통예금계좌 개설]" << std::endl;
	std::cout << "계좌 ID : ";
	std::cin >> id;
	std::cout << "이   름 : ";
	std::cin >> name;
	std::cout << "잔   액 : ";
	std::cin >> balance;
	std::cout << "이 자 율 : ";
	std::cin >> interestRate;
	customer.MakeAccount(new NormalAccount(id, name, balance, interestRate));
}
void AccountHandler::MakeHighCredit()
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interestRate;
	int creditRate;
	std::cout << "[신용신뢰계좌 개설]" << std::endl;
	std::cout << "계좌 ID : ";
	std::cin >> id;
	std::cout << "이   름 : ";
	std::cin >> name;
	std::cout << "잔   액 : ";
	std::cin >> balance;
	std::cout << "이 자 율 : ";
	std::cin >> interestRate;
	std::cout << "신용등급(1 to A, 2 to B, 3 to B) : ";
	std::cin >> creditRate;

	switch (creditRate)
	{
	case 1:
		customer.MakeAccount(new HighCreditAccount(id, name, balance, interestRate, CREDIT_LEVEL::LEVEL_A));
		break;
	case 2:
		customer.MakeAccount(new HighCreditAccount(id, name, balance, interestRate, CREDIT_LEVEL::LEVEL_B));
		break;
	case 3:
		customer.MakeAccount(new HighCreditAccount(id, name, balance, interestRate, CREDIT_LEVEL::LEVEL_C));
		break;
	}
}
void AccountHandler::DepositMoney(void)
{
	int tmpID;
	int money;
	std::cout << "[입    금]" << std::endl;
	std::cout << "입금할 계좌 ID : ";
	std::cin >> tmpID;
	for (int i = 0; i < customer.GetCustomercnt(); i++)
	{
		if (tmpID == customer[i]->GetAccID())
		{
			std::cout << "입금할 금액 : ";
			std::cin >> money;
			customer[i]->DepositMoney(money);
			std::cout << "입금 완료!" << std::endl;
			return;
		}
	}
	std::cout << "유효하지 않은 ID입니다." << std::endl;
}
void AccountHandler::WithdrawMoney()
{
	int tmpID;
	int money;
	std::cout << "[출    금]" << std::endl;
	std::cout << "출금할 계좌 ID : ";
	std::cin >> tmpID;
	for (int i = 0; i < customer.GetCustomercnt(); i++)
	{
		if (tmpID == customer[i]->GetAccID())
		{
			std::cout << "출금할 금액 : ";
			std::cin >> money;
			if (!customer[i]->WithdrawMoney(money))
			{
				std::cout << "잔액부족" << std::endl;
				return;
			}
			std::cout << "출금완료" << std::endl;
			return;
		}
	}
	std::cout << "유효하지 않은 ID입니다." << std::endl;
}
void AccountHandler::ShowAllAccInfo(void)
{
	for (int i = 0; i < customer.GetCustomercnt(); i++)
	{
		customer[i]->ShowAllAccInfo();
	}
}