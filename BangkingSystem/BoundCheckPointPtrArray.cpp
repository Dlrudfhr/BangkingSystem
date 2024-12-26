#include "BoundCheckPointPtrArray.h"
#include <iostream>

using namespace std;

BoundCheckPointPtrArray::BoundCheckPointPtrArray(const int& _arrLen) : arrLen(_arrLen), customerCnt(0)
{
	customer = new ACCOUNT_PTR[arrLen];
}
BoundCheckPointPtrArray::~BoundCheckPointPtrArray()
{
	delete[] customer;
}
ACCOUNT_PTR& BoundCheckPointPtrArray::operator[](const int& idx) const
{
	if (arrLen <= idx || idx < 0)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return customer[idx];
}
void BoundCheckPointPtrArray::MakeAccount(ACCOUNT_PTR arr)
{
	if (customerCnt >= arrLen)
	{
		cout << "�� �̻� ���¸� ���� �� �����ϴ�." << endl;
		exit(1);
	}
	customer[customerCnt++] = arr;
	cout << "���� ���� �Ϸ�, ���� ���� �� : " << customerCnt << endl;
}
const int& BoundCheckPointPtrArray::GetCustomercnt() const
{
	return customerCnt;
}