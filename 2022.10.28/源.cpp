
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
{//����m����־�����ϲ���ŵ�log

}

int Index_BF(HString S, HString T)
{//��ģʽƥ���㷨,SΪ����(Ŀ�괮)��TΪ�Ӵ�(ģʽ��)��
//ƥ��ɹ����������������Ӵ���һ�γ��ֵ�λ�ã����򷵻�-1��
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


    HString ip[5000];//ip������n��ip��ַ 
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