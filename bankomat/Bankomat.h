#pragma once
#include <string>
using namespace std;
class Bankomat
{
private:
	unsigned int current_sum, one_day_min, one_day_max;
	string identification;
	static const int SIZE = 7;
	unsigned int nominal[SIZE]{10,20,50,100,200,500,1000};
public:
	Bankomat();
	Bankomat(string identification, unsigned int current_sum, unsigned int one_day_min, unsigned int one_day_max);
	unsigned int loading_sum(int money);
	unsigned int withdraw_sum(int money);
	string convert_to_string();
};

