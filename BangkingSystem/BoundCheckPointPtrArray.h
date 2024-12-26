#pragma once

#include "Account.h"

typedef ACCOUNT* ACCOUNT_PTR;
class BoundCheckPointPtrArray
{
private:
	ACCOUNT_PTR* customer;
	int arrLen;
	int customerCnt;
public:
	BoundCheckPointPtrArray(const int& _arrLen);
	~BoundCheckPointPtrArray();
	ACCOUNT_PTR& operator[](const int& idx) const;
	void MakeAccount(ACCOUNT_PTR arr);
	const int& GetCustomercnt() const;
};