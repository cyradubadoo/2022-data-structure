#include "iostream"
#include "istream"
#include "cstring"
#include <stdlib.h>
#include <string>
using namespace std;

#define MAXLEN 5000 //������󳤶�
typedef struct
{
    char* ch;   //�洢����һά����
    int length; //���ĵ�ǰ����
} HString;

void InputRule(HString ip[], int n)
{ //����n�����򣬲������е�n��ip��ַ��ŵ�ip����

    for (int i = 0; i < n; i++)
    {
        char* temp = new char[MAXLEN];
        cin.getline(temp, 300);//��ȡһ����
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
{ //����m����־�����ϲ���ŵ�log
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
{   //��ģʽƥ���㷨,SΪ����(Ŀ�괮)��TΪ�Ӵ�(ģʽ��)��
    //ƥ��ɹ����������������Ӵ���һ�γ��ֵ�λ�ã����򷵻�-1��
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


#define MAXLEN 5000			//������󳤶�
typedef struct {
    char* ch;			//�洢����һά����
    int length;				//���ĵ�ǰ����   
}HString;


void InputRule(HString ip[], int n)
{//����n�����򣬲������е�n��ip��ַ��ŵ�ip���� 
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
{//����m����־�����ϲ���ŵ�log������log��length
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
{//��ģʽ��pattern��next����ֵ����������next
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
{//KMPƥ���㷨,targetΪ������patternΪ�Ӵ���
//ƥ��ɹ����������������Ӵ���һ�γ��ֵ�λ�ã����򷵻�-1��
//����GetNext������ȡģʽ����next����
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
{//�����Ӵ���һ�γ��ֵ�λ��
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