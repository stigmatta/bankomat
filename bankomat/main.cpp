#include <iostream>
#include <string>
#include "Bankomat.h"
using namespace std;
int main()
{
	Bankomat a("ads", 25000, 100, 15000);
	cout << a.loading_sum(505)<<endl;
	cout << a.withdraw_sum(16000)<<endl;
	cout << a.convert_to_string();
}