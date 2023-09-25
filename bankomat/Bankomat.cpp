#include "Bankomat.h"
#include <string>
#include <iostream>
using namespace std;
Bankomat::Bankomat()
{
	current_sum = one_day_max = one_day_min = 0;
	identification = "";
}
Bankomat::Bankomat(string identification, unsigned int current_sum, unsigned int one_day_min, unsigned int one_day_max)
{
	this->identification = identification;
	this->current_sum = current_sum;
	this->one_day_max = one_day_max;
	this->one_day_min = one_day_min;
}
unsigned int Bankomat::loading_sum(int money)
{
	int tmp = money;
	if (money > one_day_max || money < one_day_min)
	{
		cout << "You cant load to your bank account this amount of money" << endl;
		return current_sum;
	}
	if (money % 10 != 0)
	{
		cout << "You cant load to your bank account this amount of money" << endl;
		return current_sum;
	}
	int i = SIZE;
	while (tmp > 0)
	{
		if (tmp % nominal[i] == 0)
		{
			tmp -= nominal[i];
		}
		else
			i--;
	}
	if (tmp == 0)
		current_sum += money;
	cout << "Congratulations! You loaded " << money << " dollars to your bank account" << endl;
	return current_sum;
}
unsigned int Bankomat::withdraw_sum(int money)
{
	int tmp = money;
	if (money > one_day_max || money < one_day_min)
	{
		cout << "You cant withdraw from your bank account this amount of money" << endl;
		return current_sum;
	}
	if (money % 10 != 0)
	{
		cout << "You cant withdraw from your bank account this amount of money" << endl;
		return current_sum;
	}
	int i = SIZE;
	while (tmp > 0)
	{
		if (tmp % nominal[i] == 0)
		{
			tmp -= nominal[i];
		}
		else
			i--;
	}
	if (tmp == 0)
		current_sum -= money;
	cout << "Congratulations! You withdrawed " << money << " dollars from your bank account" << endl;
	return current_sum;
}
string Bankomat::convert_to_string()
{
	int tmp = current_sum;
	char digit;
	if (current_sum == 0)
		return "0";
	string rez = "";
	while (tmp > 0)
	{
		digit = '0' + (tmp % 10);
		rez+=digit;
		tmp /= 10;
	}
	reverse(rez.begin(),rez.end());
	return rez;
}
