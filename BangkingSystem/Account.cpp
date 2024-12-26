#include "ACCOUNT.h"
#include <iostream>

ACCOUNT::ACCOUNT(const int& _accID, const char* _cusName, const int& _balance)
	: accID(_accID), balance(_balance)
{
	size_t strLen = strlen(_cusName) + 1;
	cusName = new char[strLen];
	strcpy_s(cusName, strLen, _cusName);
}
ACCOUNT::ACCOUNT(const ACCOUNT& acc) : accID(acc.accID), balance(acc.balance)
{
	size_t strLen = strlen(acc.cusName) + 1;
	cusName = new char[strLen];
	strcpy_s(cusName, strLen, acc.cusName);
}
ACCOUNT::~ACCOUNT()
{
	delete[] cusName;
}
int ACCOUNT::GetAccID() const
{
	return accID;
}
void ACCOUNT::DepositMoney(const int& money)
{
	balance += money;
}
int ACCOUNT::WithdrawMoney(const int& money)
{
	if (balance < money) return 0;
	balance -= money;
	return money;
}
void ACCOUNT::ShowAllAccInfo(void) const
{
	std::cout << "°èÁÂ ID : " << accID << std::endl;
	std::cout << "ÀÌ¸§ : " << cusName << std::endl;
	std::cout << "ÀÜ¾× : " << balance << "\n" << std::endl;
}

/*º¸Åë¿¹±Ý°èÁÂ*/

NormalAccount::NormalAccount(const int& _accID, const char* _cusName, const int& _balance, const int& _interestRate)
	:ACCOUNT(_accID, _cusName, _balance), interestRate(_interestRate) {}
void NormalAccount::DepositMoney(const int& money)
{
	ACCOUNT::DepositMoney(money + (money * (interestRate / 100.0)));
}

/*½Å¿ë½Å·Ú °èÁÂ*/

HighCreditAccount::HighCreditAccount(const int& _accID, const char* _cusName, const int& _balance, const int& _interestRate, const char& _creditRate)
	:NormalAccount(_accID, _cusName, _balance, _creditRate), creditRate(_creditRate) {}
void HighCreditAccount::DepositMoney(const int& money)
{
	NormalAccount::DepositMoney(money);
	ACCOUNT::DepositMoney(money * (creditRate / 100.0));
}