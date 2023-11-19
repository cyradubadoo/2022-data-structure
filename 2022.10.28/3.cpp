#include "iostream"
#include "istream"
#include "cstring"
#include <stdlib.h>
#include <string>
using namespace std;

#define MAXLEN 5000 //串的最大长度
typedef struct
{
    char* ch;   //存储串的一维数组
    int length; //串的当前长度
} HString;

void InputRule(HString ip[], int n)
{ //输入n条规则，并将其中的n个ip地址存放到ip数组

    for (int i = 0; i < n; i++)
    {
        char* temp = new char[MAXLEN];
        cin.getline(temp, 300);//读取一整行
        int len = strlen(temp);
        ip[i].ch = new char[MAXLEN];
        int j = 16, k = 0;
        while (temp[j] != ' ')
        {
            ip[i].ch[k++] = temp[j++];
        }
        ip[i].length = k;
    }
    string s;
    getline(cin, s);
}

void InputLog(HString& log, int m)
{ //输入m条日志，并合并存放到log
    int j = 0;
    for (int i = 0; i < m - 1; i++)
    {
        char* temp = new char[MAXLEN];
        cin.getline(temp, 500);
        int len = strlen(temp);
        for (int k = 0; k < len; k++) log.ch[j++] = temp[k];
    }
    log.length = j;
}

int Index_BF(HString S, HString T)
{   //简单模式匹配算法,S为主串(目标串)，T为子串(模式串)。
    //匹配成功返回主串中所含子串第一次出现的位置，否则返回-1。
    int slen = S.length, tlen = T.length;
    for (int i = 0; i < slen; i++)
    {
        int begin = i;
        for (int j = 0; j < tlen; j++)
        {
            if (S.ch[begin] != T.ch[j])
                break;
            else
            {
                begin++;
                if (j + 1 == T.length)
                    return 1;
            }
        }
    }
    return -1;
}


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
    for (int i = 0; i < n; i++)
    {
        char* temp = new char[MAXLEN];
        cin.getline(temp, 300);
        int len = strlen(temp);
        ip[i].ch = new char[MAXLEN];
        int j = 16, k = 0;
        while (temp[j] != ' ')
        {
            ip[i].ch[k++] = temp[j++];
        }
        ip[i].length = k;
    }
    string s;
    getline(cin, s);




}

void InputLog(HString& log, int m)
{//输入m条日志，并合并存放到log，返回log的length
    int j = 0;
    for (int i = 0; i < m; i++)
    {
        char* temp = new char[MAXLEN];
        cin.getline(temp, 500);

        int len = strlen(temp);
        for (int k = 0; k < len; k++)
            log.ch[j++] = temp[k];
    }
    log.length = j;


}

void GetNext(HString pattern, int* next)
{//求模式串pattern的next函数值并存入数组next
    int j = 0;
    next[0] = 0;
    for (int i = 1; i < pattern.length; i++) {
        while (j > 0 && pattern.ch[i] != pattern.ch[j]) {
            j = next[j - 1];
        }
        if (pattern.ch[i] == pattern.ch[j]) {
            j++;
        }
        next[i] = j;
    }
}

int Index_KMP(HString target, HString pattern, int* next)
{//KMP匹配算法,target为主串，pattern为子串。
//匹配成功返回主串中所含子串第一次出现的位置，否则返回-1。
//调用GetNext函数获取模式串的next数组
    GetNext(pattern, next);
    int j = 0;
    for (int i = 0; i < target.length; i++)
    {
        while (j > 0 && target.ch[i] != pattern.ch[j])
        {
            j = next[j - 1];
        }
        if (target.ch[i] == pattern.ch[j])
        {
            j++;
        }
        if (j == pattern.length)
        {
            return (i - pattern.length + 1);
        }
    }
    return -1;
}



#include<iostream>
#include<string.h>
using namespace std;


void getNext(int* next, string s2)
{
    int j = 0;
    next[0] = 0;
    for (int i = 1; s2[i] != '\0'; i++)
    {
        while (s2[j] != s2[i] && j > 0)
        {
            j = next[j - 1];
        }
        if (s2[j] == s2[i])
            j++;
        next[i] = j;
    }
}

int strstr(string s1, string s2)
{//查找子串第一次出现的位置
    int* next = new int[100];
    int j = 0;
    next[0] = 0;
    getNext(next, s2);
    for (int i = 0; s1[i] != '\0'; i++)
    {
        while (s1[i] != s2[j] && j > 0)
        {
            j = next[j - 1];
        }
        if (s1[i] == s2[j])
            j++;
        if (j == s2.size())
            return (i - s2.size() + 1);
    }
    return -1;

}