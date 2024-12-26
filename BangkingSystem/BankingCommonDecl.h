#pragma once

#include <iostream>
#include "AccountHandler.h"
#define MAX_BUF_SIZE 100
#define NAME_LEN 20

using namespace std;

enum CHOICE
{
	MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT
};
enum CREDIT_LEVEL
{
	LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2
};
enum ACCOUNT_KIND
{
	NORMAL_ACCOUNT = 1, HIGHCREDIT_ACCOUNT = 2
};