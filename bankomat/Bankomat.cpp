#include "Bankomat.h"
#include <string>
#include <iostream>
using namespace std;
Bankomat::Bankomat()
{
	current_sum = one_day_max = one_day_min = 0;
	identification = "";
}
Bankomat::Bankomat(string identification, unsigned int current_sum, unsigned int one_day_min, unsigned int one_day_max,initializer_list <unsigned int>nominal)
{
	this->identification = identification;
	this->current_sum = current_sum;
	this->one_day_max = one_day_max;
	this->one_day_min = one_day_min;
	this->nominal = nominal;
}
unsigned int Bankomat::loading_sum(int money)
{
	if (money > one_day_max || money < one_day_min)
	{
		cout << "You cant load to your bank account this amount of money" << endl;
		return current_sum;
	}
	current_sum += money;
	cout << "Congratulations! You loaded " << money << " dollars from your bank account" << endl;
	return current_sum;
}
initializer_list <unsigned int> Bankomat:: getNominal()
{
	return nominal;
}
unsigned int Bankomat::withdraw_sum(int money)
{
	int tmp = money;
	bool flag = false;
	if (money > one_day_max || money < one_day_min)
	{
		cout << "You cant withdraw from your bank account this amount of money" << endl;
		return current_sum;
	}
	if (money % *(nominal.begin()) != 0)
	{
		cout << "You cant withdraw from your bank account this amount of money" << endl;
		return current_sum;
	}
	for (auto x = nominal.begin(); x != nominal.end(); x++)
	{
		if (money % *(x) == 0)
			flag = true;
	}
	if (flag)
	{
		current_sum -= money;
		cout << "Congratulations! You withdrawed " << money << " dollars from your bank account" << endl;

	}
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
	for (int i = 0; i < rez.length()/2; i++)
		swap(rez[i], rez[rez.length() - i-1]);
	/*reverse(rez.begin(),rez.end());*/
	return rez;
}
