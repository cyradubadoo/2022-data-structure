#include <iostream>

using namespace std;

void conversion(int n); //将n转换为二进制输出的递归函数声明

int main()
{
    int a, b;
    cout << "输入想要转换的数字：" ;
    cin >> a;
    cout << "转换后的数据为：";
    conversion(a); //将n转换为二进制输出
    return 0;
}
    
//int x = 0;          //用于特殊值“0”的处理 
void conversion(int n)
{

   // if (x == 0 && n == 0)cout << "0";
    if (n < 1)
        return;
    else
    {
       // x++;
        conversion(n / 2);
        cout<<n % 2;
        return;
    }
}