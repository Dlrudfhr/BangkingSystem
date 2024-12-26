/*
* Banking System Ver 0.8
* ������� ���� ���α׷�
* �ۼ��� : �̰��
* ��  �� : ���� ������(���� ����)
		   AccountHandler class�� �迭�� ����� ����(��ü ����) -> �迭 Ŭ����(BoundCheckPointPtrArray)
*/

#include "BankingCommonDecl.h"

int main(void)
{
	int choice, i = 0;
	AccountHandler accHandler;
	while (1)
	{
		accHandler.ShowMenu();
		std::cin >> choice;
		std::cout << "--------------\n" << std::endl;
		switch (choice)
		{
		case MAKE:
			accHandler.MakeAccount();
			break;
		case DEPOSIT:
			accHandler.DepositMoney();
			break;
		case WITHDRAW:
			accHandler.WithdrawMoney();
			break;
		case INQUIRE:
			accHandler.ShowAllAccInfo();
			break;
		case EXIT:
			std::cout << "���α׷��� �����մϴ�." << std::endl;
			return 0;
		default:
			std::cout << "Illegal selection" << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}