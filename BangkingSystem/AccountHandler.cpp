#include "BankingCommonDecl.h"

using namespace std;

AccountHandler::AccountHandler() : customer(MAX_BUF_SIZE) {}
void AccountHandler::ShowMenu(void)
{
	std::cout << "-----MENU-----" << std::endl;
	std::cout << "1. ���� ����" << std::endl;
	std::cout << "2. ��     ��" << std::endl;
	std::cout << "3. ��     ��" << std::endl;
	std::cout << "4. ��ü�� �ܾ� ��ȸ" << std::endl;
	std::cout << "5. ���α׷� ����" << std::endl;
	std::cout << "��� ����(1,2,3,4,5) : ";
}
void AccountHandler::MakeAccount(void)
{
	int choice;
	cout << "[������������]\n" << "1. ���뿹�ݰ��� 2. �ſ�ŷڰ���" << endl;
	cout << "���� : ";
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

	std::cout << "[���뿹�ݰ��� ����]" << std::endl;
	std::cout << "���� ID : ";
	std::cin >> id;
	std::cout << "��   �� : ";
	std::cin >> name;
	std::cout << "��   �� : ";
	std::cin >> balance;
	std::cout << "�� �� �� : ";
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
	std::cout << "[�ſ�ŷڰ��� ����]" << std::endl;
	std::cout << "���� ID : ";
	std::cin >> id;
	std::cout << "��   �� : ";
	std::cin >> name;
	std::cout << "��   �� : ";
	std::cin >> balance;
	std::cout << "�� �� �� : ";
	std::cin >> interestRate;
	std::cout << "�ſ���(1 to A, 2 to B, 3 to B) : ";
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
	std::cout << "[��    ��]" << std::endl;
	std::cout << "�Ա��� ���� ID : ";
	std::cin >> tmpID;
	for (int i = 0; i < customer.GetCustomercnt(); i++)
	{
		if (tmpID == customer[i]->GetAccID())
		{
			std::cout << "�Ա��� �ݾ� : ";
			std::cin >> money;
			customer[i]->DepositMoney(money);
			std::cout << "�Ա� �Ϸ�!" << std::endl;
			return;
		}
	}
	std::cout << "��ȿ���� ���� ID�Դϴ�." << std::endl;
}
void AccountHandler::WithdrawMoney()
{
	int tmpID;
	int money;
	std::cout << "[��    ��]" << std::endl;
	std::cout << "����� ���� ID : ";
	std::cin >> tmpID;
	for (int i = 0; i < customer.GetCustomercnt(); i++)
	{
		if (tmpID == customer[i]->GetAccID())
		{
			std::cout << "����� �ݾ� : ";
			std::cin >> money;
			if (!customer[i]->WithdrawMoney(money))
			{
				std::cout << "�ܾ׺���" << std::endl;
				return;
			}
			std::cout << "��ݿϷ�" << std::endl;
			return;
		}
	}
	std::cout << "��ȿ���� ���� ID�Դϴ�." << std::endl;
}
void AccountHandler::ShowAllAccInfo(void)
{
	for (int i = 0; i < customer.GetCustomercnt(); i++)
	{
		customer[i]->ShowAllAccInfo();
	}
}