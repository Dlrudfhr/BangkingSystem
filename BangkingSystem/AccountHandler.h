#pragma once

#include "BoundCheckPointPtrArray.h"

/*Handler*/
class AccountHandler
{
private:
	BoundCheckPointPtrArray customer;
public:
	AccountHandler();
	void ShowMenu(void);
	void MakeAccount(void);
	void MakeNormal();
	void MakeHighCredit();
	void DepositMoney(void);
	void WithdrawMoney();
	void ShowAllAccInfo(void);
};