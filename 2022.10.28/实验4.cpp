#include <iostream>
#include <string.h>
#define MAXSIZE 100
using namespace std;
typedef struct
{                               //��������������ʽ
	int weight;                 //����Ȩֵ
	int parent, lchild, rchild; //����˫�ס����ӡ��Һ��ӵ��±�
} HTNode, * HuffmanTree;         //��̬��������洢��������
typedef char** HuffmanCode;     //������������
int Search(char a[], char ch)
{ //�����������ַ�ch���ڵ�λ�ã����������±꣬���򷵻�-1
	int len = strlen(a);
	for (int i = 0; i < len; ++i)
	{
		if (a[i] == ch)
			return i;
	}
	return -1;
}
void Sort(char a[], int b[], int len)
{ //��ASCII��ð������
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
				swap(b[i], b[j]);
			}
		}
	}
}
void Select_min(HuffmanTree HT, int n, int& s1, int& s2)
{
	// ��HT[k](1��k��i-1����ѡ��������˫����Ϊ0��Ȩֵ��С�Ľ�㣬������������HT�е����s1��s2
	int temp1 = 0, temp2 = 0;
	for (int i = 1; i < n + 1; i++) {
		if (HT[i].parent == 0 && HT[i].weight < HT[temp1].weight) {
			temp1 = i;
		}
	}
	for (int i = 1; i < n + 1; i++) {
		if (HT[i].parent == 0 && HT[i].weight < HT[temp2].weight && i != temp1) {
			temp2 = i;
		}
	}
	s1 = temp1;
	s2 = temp2;
}
int m;
void CreateHuffmanTree(HuffmanTree& HT, int n, int b[])
{ //�����������HT
	int i;
	if (n <= 1) return;
	m = 2 * n - 1;
	HT = new HTNode[m + 1];  // 0�ŵ�Ԫδ��
	for (i = 1; i < m + 1; i++) {
		HT[i].weight = 0;
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (i = 1; i < n + 1; i++) HT[i].weight = b[i - 1];
	int s1, s2;
	HT[0].weight = 1024;  // ��ѡ0�ŵ�Ԫ 
	for (i = n + 1; i < m + 1; i++) {
		Select_min(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n)
{ //��Ҷ�ӵ���������ÿ���ַ��Ĺ��������룬�洢�ڱ����HC��
	HC = new char* [n + 1];
	char* cd = new char[n];
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; i++) {
		int start = n - 1;
		int c = i;
		int f = HT[i].parent;
		while (f != 0) {
			--start;
			if (HT[f].lchild == c) cd[start] = '0';
			else cd[start] = '1';
			c = f; f = HT[f].parent;
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &cd[start]);
	}
	delete cd;
}
void CharFrequency(char ch[], char a[], int b[], int& j)
{ //ͳ�ƴ�Ƶ
	int chlen = strlen(ch);
	int flag = 1, num;
	j = 0;
	for (int i = 0; i < chlen; ++i)
	{
		flag = 1;
		int alen = strlen(a);
		for (int k = 0; k < alen; ++k)
		{
			if (ch[i] == a[k])
			{
				flag = 0;
				b[k]++;
				break;
			}
		}
		if (flag)
		{
			a[j] = ch[i];
			b[j]++;
			j++;
		}
	}
}
void PrintHT(HuffmanTree HT)
{ //������������Ĵ洢�ṹ����̬
	for (int i = 1; i <= m; ++i) {
		cout << i << ' ' << HT[i].weight << ' ' << HT[i].parent << ' ' << HT[i].lchild << ' ' << HT[i].rchild << '\n';
	}
}
void PrintHC(HuffmanCode HC, char a[], int j)
{ //���ÿ���ַ��Ĺ���������
	for (int i = 0; i < j; i++) {
		cout << a[i] << ':' << HC[i + 1];
		if (i != j - 1) cout << ' ';
		else cout << endl;
	}
}


#include<iostream>
using namespace std;
typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
void CreateBiTree(BiTree& T, char S[], int& i)
{////������������
	if (S[i] == '0') T = NULL;
	else
	{
		T = new BiTNode;
		T->data = S[i];
		CreateBiTree(T->lchild, S, ++i);
		CreateBiTree(T->rchild, S, ++i);
	}
}
int Compare(BiTree T1, BiTree T2)
{//�ж����ö������Ƿ���ȣ�����ȷ���0����ȷ���1	
	if (T1 == NULL && T2 == NULL)
		return 1;
	else if (T1 == NULL || T2 == NULL)
		return 0;
	if (T1->data != T2->data)
		return 0;
	return Compare(T1->lchild, T2->lchild) && Compare(T2->rchild, T1->rchild);
}






#include<iostream>
#include<cstring>
using namespace std;
typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
void CreateBiTree(BiTree& T, char S[], int& i)
{//������������
	if (S[i] == '0') T = NULL;
	else
	{
		T = new BiTNode;
		T->data = S[i];
		CreateBiTree(T->lchild, S, ++i);
		CreateBiTree(T->rchild, S, ++i);
	}
}
void ChangeRL(BiTree& T)
{//���������Һ��ӵĽ���
	if (T && (T->lchild || T->rchild))
	{
		BiTree t = new BiTNode;
		t = T->lchild;
		T->lchild = T->rchild;
		T->rchild = t;
		ChangeRL(T->lchild);
		ChangeRL(T->rchild);
	}
}
void PreOrderTraverse(BiTree T)
{//�������
	if (!T) return;
	cout << T->data;
	if (T->lchild) PreOrderTraverse(T->lchild);
	if (T->rchild) PreOrderTraverse(T->rchild);

}



#include<iostream>
#include <string.h>
using namespace std;
typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
void CreateBiTree(BiTree& T, char S[], int& i)
{//������������
	if (S[i] == '0') T = NULL;
	else {
		T = new BiTNode;
		T->data = S[i];
		CreateBiTree(T->lchild, S, ++i);
		CreateBiTree(T->rchild, S, ++i);
	}
}
void DoubleTraverse(BiTree T)
{//˫�����������T�ĵݹ��㷨
	if (!T) return;
	cout << T->data;
	if (T->lchild)
		DoubleTraverse(T->lchild);
	cout << T->data;
	if (T->rchild)
		DoubleTraverse(T->rchild);
}



#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

BiTree CreateBiTree(int& pos, char* str)
{ // ������������
	if (str[pos] == '0') return NULL;
	BiTNode* root = new BiTNode;
	root->data = str[pos];
	root->lchild = CreateBiTree(++pos, str);
	root->rchild = CreateBiTree(++pos, str);
	return root;

}

int Width(BiTree T)
{// �������T�����
	queue<BiTNode*> qu;
	if (!T) return 0;
	qu.push(T);
	int maxlen = 0;
	while (!qu.empty()) {
		int num = qu.size();
		maxlen = max(num, maxlen);
		BiTNode* cur = new BiTNode;
		for (int i = 0; i < num; ++i) {
			cur = qu.front();
			qu.pop();
			if (cur->lchild) qu.push(cur->lchild);
			if (cur->rchild) qu.push(cur->rchild);
		}
	}
	return maxlen;
}





#include<iostream>
#define MAXSIZE 100
using namespace std;
typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
int len = 0;
BiTree ans[MAXSIZE];
BiTree node;
void CreateBiTree(BiTree& T, char S[], int& i)
{//������������
	if (S[i] == '0') T == NULL;
	else {
		T = new BiTNode;
		T->data = S[i];
		CreateBiTree(T->lchild, S, ++i);
		CreateBiTree(T->rchild, S, ++i);
	}
}

int GetMaxLen(BiTree T)
{
	if (!T) return 0;
	return 1 + max(GetMaxLen(T->lchild), GetMaxLen(T->rchild));
}

int m = 0, flag = 0;

void getLongPath(BiTree T, BiTree l[], int& longest)
{
	if (T)
	{
		ans[longest] = T;
		if (!T->lchild && !T->rchild && m == 1 + longest && !flag)
		{
			l[++longest] = T;
			flag = 1;
			return;
		}
		if (flag) return;
		l[++longest] = T;
		getLongPath(T->lchild, l, longest);
		getLongPath(T->rchild, l, longest);
		longest--;
	}
}
void LongestPath(BiTree T, BiTree l[], int& longest)
{//�������·�������
	m = GetMaxLen(T);
	flag = 0;
	getLongPath(T, l, longest);
	longest = m;

}




#include<iostream>
using namespace std;
typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
void CreateBiTree(BiTree& T, char S[], int& i)
{//������������
	if (S[i] == '0') T = NULL;
	else
	{
		T = new BiTNode;
		T->data = S[i];
		CreateBiTree(T->lchild, S, ++i);
		CreateBiTree(T->rchild, S, ++i);
	}
}
void AllPath(BiTree T, char path[], int pathlen)
{//������Ҷ�ӽ�㵽������·�������
   //pathlen = 0;
	if (T != NULL)
	{
		if (T->lchild == NULL && T->rchild == NULL)
		{
			cout << T->data;
			for (int i = pathlen - 1; i >= 0; i--)
				cout << path[i];
			cout << endl;
		}
		else
		{
			path[pathlen] = T->data;
			pathlen++;
			AllPath(T->lchild, path, pathlen);
			AllPath(T->rchild, path, pathlen);
			pathlen--;
		}
	}

}



#include<iostream>
#include<string.h>
using namespace std;
typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
void CreateBiTree(BiTree& T, char S[], int& i)
{//������������
	if (S[i] == '0') T = NULL;
	else {
		T = new BiTNode;
		T->data = S[i];
		CreateBiTree(T->lchild, S, ++i);
		CreateBiTree(T->rchild, S, ++i);
	}
}
void PreOrderTraverse(BiTree T)
{//���������������
	if (!T) return;
	cout << T->data;
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}
void InOrderTraverse(BiTree T)
{//���������������
	if (!T) return;
	InOrderTraverse(T->lchild);
	cout << T->data;
	InOrderTraverse(T->rchild);
}
void PostOrderTraverse(BiTree T)
{//�������ĺ������
	if (!T) return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	cout << T->data;
}



#include<iostream>
#include<string.h>
using namespace std;

typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
void CreateBiTree(BiTree& T, char S[], int& i)
{//������������
	if (S[i] == '0') T = NULL;
	else
	{
		T = new BiTNode;
		T->data = S[i];
		CreateBiTree(T->lchild, S, ++i);
		CreateBiTree(T->rchild, S, ++i);
	}
}
void Count(BiTree T, int& a, int& b, int& c)
{//��������������ͳ��
	if (!T) return;
	else if (!T->lchild && !T->rchild) ++a;
	else if ((!T->rchild && T->lchild) || (!T->lchild && T->rchild)) ++b;
	else ++c;
	Count(T->lchild, a, b, c);
	Count(T->rchild, a, b, c);

}



#include<iostream>
#include <string.h>
using namespace std;
typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
void CreateBiTree(BiTree& T, char S[], int& i)
{//������������
	if (S[i] == '0') T = NULL;
	else
	{
		T = new BiTNode;
		T->data = S[i];
		CreateBiTree(T->lchild, S, ++i);
		CreateBiTree(T->rchild, S, ++i);
	}
}
int Depth(BiTree T)
{//�������߶ȵļ���
	if (!T) return 0;
	else
	{
		int m = Depth(T->lchild);
		int n = Depth(T->rchild);
		if (m > n) return (m + 1);
		else return (n + 1);
	}
}




#include<iostream>
#include<ctype.h>
#define MAXSIZE 100
using namespace std;
typedef struct BiTNode
{//��������˫����洢��ʾ
	double data;          //���������
	char op;
	struct BiTNode* lchild, * rchild;    //���Һ���ָ��
}BiTNode, * BiTree;
typedef struct
{//�ַ�ջ�Ĵ洢�ṹ
	char* base;     //ջ��ָ��
	char* top;       //ջ��ָ��
	int stacksize;   //ջ���õ��������
}SqStack1;

typedef struct
{//���ջ�Ĵ洢�ṹ
	BiTree* base;
	BiTree* top;
	int stacksize;
}SqStack2;

void InitStack1(SqStack1& s)
{//�ַ�ջ�ĳ�ʼ��
	s.base = new char[MAXSIZE];
	if (!s.base) exit(-1);
	s.top = s.base;
	s.stacksize = MAXSIZE;
}
void InitStack2(SqStack2& s)
{//���ջ�ĳ�ʼ��
	s.base = new BiTree[MAXSIZE];
	if (!s.base) exit(-1);
	s.top = s.base;
	s.stacksize = MAXSIZE;
}
void Push1(SqStack1& s, char ch)
{//�ַ���ջ����
	*s.top++ = ch;
}

void Push2(SqStack2& s, BiTree t)
{//�����ջ����
	*s.top++ = t;
}

void Pop1(SqStack1& s)//
{//�ַ���ջ����
	--s.top;
}

void Pop2(SqStack2& s)//
{//����ջ����
	--s.top;
}

char GetTop(SqStack1 s)
{//ȡ�ַ�ջ��ջ��Ԫ��
	return *(s.top - 1);
}

BiTree GetTop2(SqStack2 s)
{//ȡ�ַ�ջ��ջ��Ԫ��
	return *(s.top - 1);
}

bool EmptyStack(SqStack1 s)
{//ջ���пղ���
	return s.top == s.base;
}

char Precede(char a, char b)
{//�ȽϷ������ȼ�
	if (a == '(' && b == ')' || a == '=' && b == '=') return '=';
	else if (a == '=' || a == '(' || b == '(' || ((a == '+' || a == '-') && (b == '*' || b == '/')))
		return '<';
	return '>';
}

double Operate(double a, char ch, double b)
{//���������������Ӧ����ֵ���
	double ret = 0;
	char op = ch;
	if (op == '+') ret = a + b;
	else if (op == '-') ret = a - b;
	else if (op == '*') ret = a * b;
	else if (op == '/') ret = a / b;
	return ret;
}
bool IsCharacter(char ch)
{//�ж�ch�Ƿ�Ϊ+��-��*��/��(��)��= ������ַ������򷵻�true
	return !isdigit(ch);
}

double InOrder(BiTree T)
{//�������������������ʽ��ֵ
	if (!T) return 0;
	if (!T->lchild && !T->rchild) return T->data;
	int lv = InOrder(T->lchild), rv = InOrder(T->rchild);
	return Operate(lv, T->op, rv);
}

void CreateBT(char ch[], BiTree& t, SqStack1 optr, SqStack2 expt)
{//����������

	int i = 0;
	while (ch[i]) {
		char c = ch[i];
		if (isdigit(c)) {
			BiTree numnode = new BiTNode;
			numnode->data = c - '0';
			numnode->lchild = numnode->rchild = NULL;
			Push2(expt, numnode);
		}
		else {
			if (Precede(GetTop(optr), c) == '<') {
				Push1(optr, c);
			}
			else if (Precede(GetTop(optr), c) == '>')
			{
				while (Precede(GetTop(optr), c) == '>') {
					BiTree opnode = new BiTNode;
					opnode->op = GetTop(optr); Pop1(optr);
					opnode->lchild = GetTop2(expt); Pop2(expt);
					opnode->rchild = GetTop2(expt); Pop2(expt);

					Push2(expt, opnode); t = opnode;

					char top = GetTop(optr);
					if (top == '=' || top == '(') break;
				}

				if (GetTop(optr) == '(') Pop1(optr);
				else Push1(optr, c);
			}
			else {
				Pop1(optr);
			}
		}
		++i;
	}
}