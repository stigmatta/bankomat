#pragma once
#include <string>
using namespace std;
class Bankomat
{
private:
	unsigned int current_sum, one_day_min, one_day_max;
	string identification;
	int SIZE;
	initializer_list<unsigned int> nominal;
public:
	Bankomat();
	Bankomat(string identification, unsigned int current_sum, unsigned int one_day_min, unsigned int one_day_max,initializer_list <unsigned int>nominal);
	unsigned int loading_sum(int money);
	unsigned int withdraw_sum(int money);
	string convert_to_string();
	initializer_list <unsigned int> getNominal();
};

