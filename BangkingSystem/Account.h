#pragma once

/*°èÁÂ*/
class ACCOUNT
{
private:
	int accID;
	char* cusName;
	int balance;
public:
	ACCOUNT(const int& _accID, const char* _cusName, const int& _balance);
	ACCOUNT(const ACCOUNT& acc);
	virtual ~ACCOUNT();
	int GetAccID() const;
	virtual void DepositMoney(const int& money);
	int WithdrawMoney(const int& money);
	void ShowAllAccInfo(void) const;
};

class NormalAccount : public ACCOUNT
{
private:
	int interestRate;
public:
	NormalAccount(const int& _accID, const char* _cusName, const int& _balance, const int& _interestRate);
	virtual void DepositMoney(const int& money);
};

class HighCreditAccount : public NormalAccount
{
private:
	const int creditRate;
public:
	HighCreditAccount(const int& _accID, const char* _cusName, const int& _balance, const int& _interestRate, const char& _creditRate);
	virtual void DepositMoney(const int& money);
};
