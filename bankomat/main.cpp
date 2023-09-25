#include <iostream>
#include <string>
#include "Bankomat.h"
using namespace std;
int main()
{
	Bankomat a("ads", 25000, 10, 15000,{10,20,50});
	cout << a.loading_sum(50)<<endl;
	cout << a.withdraw_sum(30)<<endl;
	cout << a.convert_to_string();
}