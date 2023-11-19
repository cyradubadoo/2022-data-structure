#include <iostream>

using namespace std;

int main()
{
    int a;
    cout << "输入想要转换的数字：";
    cin >> a;
    int d[100], len = 0;
    do {
        d[len++] = a % 2;
        a /= 2;
    } while (a != 0);
    cout << "转换后的数字为：";
    for (int i = len - 1; i >= 0; i--) {
        cout << d[i];
    }
    return 0;
}