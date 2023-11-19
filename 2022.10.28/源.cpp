
#include "iostream"
#include "cstring"
#include<stdlib.h>
using namespace std;


#define MAXLEN 5000			//串的最大长度
typedef struct {
    char* ch;			//存储串的一维数组
    int length;				//串的当前长度   
}HString;


void InputRule(HString ip[], int n)
{//输入n条规则，并将其中的n个ip地址存放到ip数组 
    int num = n;
    HString temp;
    temp.ch = new char[MAXLEN];
    while (num > 0) {
        int i = 0;
        for (i = 0; i < n; i++) {
            cin >> temp.ch[i];
        }
        for (i = 0; i < n; i++) {

        }
    }

}

void InputLog(HString& log, int m)
{//输入m条日志，并合并存放到log

}

int Index_BF(HString S, HString T)
{//简单模式匹配算法,S为主串(目标串)，T为子串(模式串)。
//匹配成功返回主串中所含子串第一次出现的位置，否则返回-1。
    for (int i = 0; i < S.length; i++) {
        int n = i;
        for (int j = 0; j < T.length; j++) {
            if (S.ch[n] != T.ch[j]) break;
            else {
                n++;
                if (j + 1 == T.length) return 1;
            }
        }
    }
    return -1;
}



int main()
{
    int n, m;
    cin >> n >> m;
    getchar();


    HString ip[5000];//ip数组存放n个ip地址 
    InputRule(ip, n);

    HString log;
    log.ch = (char*)malloc(sizeof(char) * 5000);
    strcpy(log.ch, "");
    log.length = 0;
    InputLog(log, m);

    for (int i = 0; i < n; i++)
    {
        if (Index_BF(log, ip[i]) != -1)
        {
            cout << "Intrusion." << endl;
            return 0;
        }
    }
    cout << "No Intrusion." << endl;
    return 0;

}