#include <iostream>

using namespace std;

void conversion(int n); //��nת��Ϊ����������ĵݹ麯������

int main()
{
    int a, b;
    cout << "������Ҫת�������֣�" ;
    cin >> a;
    cout << "ת���������Ϊ��";
    conversion(a); //��nת��Ϊ���������
    return 0;
}
    
//int x = 0;          //��������ֵ��0���Ĵ��� 
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