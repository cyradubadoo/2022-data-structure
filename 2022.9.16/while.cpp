#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cout << "输入想要转换的数字：";
	cin >> a;
	while (a != 0)
	{
		b = a % 2;
		a /= 2;
		cout << b; 
	}
	return 0;
}