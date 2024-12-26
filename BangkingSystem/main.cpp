/*
* Banking System Ver 0.8
* 은행계좌 관리 프로그램
* 작성자 : 이경록
* 내  용 : 대입 연산자(깊은 복사)
		   AccountHandler class의 배열이 멤버로 선언(객체 저장) -> 배열 클래스(BoundCheckPointPtrArray)
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
			std::cout << "프로그램을 종료합니다." << std::endl;
			return 0;
		default:
			std::cout << "Illegal selection" << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}