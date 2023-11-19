#include <iostream>
#include <fstream>
#include <cstring>
#include<iomanip>

using namespace std;


typedef struct {
	char no[20];   //ͼ��ISBN
	char name[50];   //����
	double price;   //ͼ��۸�
}Book;

typedef struct {
	Book* elem;//����ռ�Ļ���ַ
	int length;//ͼ����е�ǰͼ��ĸ���
}SqList;

void Init(SqList& L);//��ʼ��
void ReadFromFile(SqList& L);//���ļ�
void WriteIntoFile(SqList& L, string file);//д�ļ�

void MainMenu();//��ʾ���˵�
void ShowAll(SqList& L);//ͼ�����
void Statistics(SqList& L);//ͼ��ͳ��
void Insert(SqList& L);//����
void Delete(SqList& L);//ɾ��
void Modify(SqList& L);//�۸����
void Sort(SqList& L);//�۸�����
void Inverse(SqList& L);//���򴢴�
void Quit();//�˳�

void SearchMenu();//��ʾ���Ҳ˵�
void SearchByPosition(SqList& L);//��λ�ò���
void SearchByName(SqList& L);//����������


int main() {
	MainMenu();
	return 0;
}

void MainMenu() {
	system("cls");
	printf("*******************ͼ�����ϵͳ*******************\n");
	printf("1)ͼ�����----------------------------------------1\n");
	printf("2)ͼ��ͳ��----------------------------------------2\n");
	printf("3)ͼ�����----------------------------------------3\n");
	printf("4)ͼ��ɾ��----------------------------------------4\n");
	printf("5)ͼ�����----------------------------------------5\n");
	printf("6)�۸����----------------------------------------6\n");
	printf("7)�۸�����----------------------------------------7\n");
	printf("8)���򴢴�----------------------------------------8\n");
	printf("9)�˳�--------------------------------------------9\n\n");
	printf("������������еĲ�����");

	SqList L;
	Init(L);
	ReadFromFile(L);
	int op;
	cin >> op;
	switch (op) {
	case 1: {//ͼ�����
		ShowAll(L);
		break;
	}
	case 2: {//ͼ��ͳ��
		Statistics(L);
		break;
	}
	case 3: {//ͼ�����
		Insert(L);
		break;
	}
	case 4: {//ͼ��ɾ��
		Delete(L);
		break;
	}
	case 5: {//ͼ�����
		SearchMenu();
		break;
	}
	case 6: {//�۸����
		Modify(L);
		break;
	}
	case 7: {//�۸�����
		Sort(L);
		break;
	}
	case 8: {//���򴢴�
		Inverse(L);
		break;
	}
	case 9: {//�˳�
		Quit();
		break;
	}
	default: {//�Ƿ�����
		printf("����ʧ�ܣ����������룡\n\n");
		system("pause");
		MainMenu();
		break;
	}
	}
	delete L.elem;//�ͷſռ�
}

void SearchMenu() {
	system("cls");
	printf("******************��ѡ����ҷ�ʽ******************\n");
	printf("1)��λ�ò���--------------------------------------1\n");
	printf("2)����������--------------------------------------2\n");
	printf("3)ȡ������----------------------------------------3\n\n");
	printf("������������еĲ�����");

	SqList L;
	Init(L);
	ReadFromFile(L);
	int op;
	cin >> op;
	switch (op) {
	case 1: {//��λ�ò���
		SearchByPosition(L);
		break;
	}
	case 2: {//����������
		SearchByName(L);
		break;
	}
	case 3: {//�������˵�
		MainMenu();
		break;
	}
	default: {//�Ƿ�����
		printf("����ʧ�ܣ����������룡\n\n");
		system("pause");
		SearchMenu();
		break;
	}
	}
	delete L.elem;
}


//��ʼ��
void Init(SqList& L) {
	L.elem = new Book[1000];
	if (!L.elem) {
		exit(-2);
	}
	L.length = 0;
}


//���ļ�
void ReadFromFile(SqList& L) {
	ifstream read("book.txt");

	if (!read) {
		exit(0);
	}

	char title[100];
	char noTitle[20], nameTitle[50], priceTitle[100];
	read >> title;
	read >> noTitle >> nameTitle >> priceTitle;

	Book book;
	while (read >> book.no >> book.name >> book.price) {
		L.elem[L.length] = book;
		L.length++;
	}

	read.close();
}


//д�ļ�
void WriteIntoFile(SqList& L, string file) {
	ofstream write(file);

	if (!write) {
		exit(0);
	}

	write << "������ҵ��ѧͼ��ݼ������ͼ���б�" << endl;
	write << "ISBN                      ����                 ����" << endl;

	for (int i = 0; i < L.length; i++) {
		write << std::left << setw(20) << L.elem[i].no << setw(40) << L.elem[i].name << L.elem[i].price << endl;
	}

	write.close();
}


//��ʾ����ͼ��
void ShowAll(SqList& L) {
	system("cls");

	if (L.length == 0) {
		printf("û��ͼ�顣\n\n");
	}
	else {
		printf("����ͼ����Ϣ���£�\n");
		printf("    ISBN                  ����                             ����\n");
		for (int i = 0; i < L.length; i++) {
			printf("%-20s%-40s%.2f\n", L.elem[i].no, L.elem[i].name, L.elem[i].price);
		}
		printf("=================================================================\n\n");
	}

	system("pause");
	MainMenu();
}


//ͼ��ͳ��
void Statistics(SqList& L) {
	system("cls");

	if (L.length == 0) {
		printf("û��ͼ�顣\n\n");
	}
	else {
		int i = L.length;
		printf("ͼ������Ϊ%d��\n", i);
	}

	system("pause");
	MainMenu();
}


//����
void Insert(SqList& L) {
	system("cls");

	int pos;
	Book book;

	printf("������Ҫ����ͼ���λ��(1-%d):", L.length);
	cin >> pos;

	while (pos < 1 || pos > L.length + 1) {
		printf("����λ�ò��Ϸ����������������λ�ã�");
		cin >> pos;
	}

	printf("������ͼ��ISBN��");
	cin >> book.no;
	printf("������ͼ��������");
	cin >> book.name;
	printf("������ͼ��۸�");
	cin >> book.price;

	for (int i = L.length - 1; i >= pos - 1; i--) {
		L.elem[i + 1] = L.elem[i];
	}
	L.elem[pos - 1] = book;
	L.length++;

	WriteIntoFile(L, "book.txt");
	printf("\n����ɹ���\n");

	system("pause");
	MainMenu();
}


//ɾ��
void Delete(SqList& L) {
	system("cls");

	int pos;

	printf("������Ҫɾ��ͼ���λ��(1-%d):", L.length);
	cin >> pos;

	while (pos < 1 || pos > L.length + 1) {
		printf("ɾ��λ�ò������ڣ�����������ɾ��λ�ã�");
		cin >> pos;
	}

	for (int i = pos; i <= L.length - 1; i++) {
		L.elem[i - 1] = L.elem[i];
	}
	L.length--;

	WriteIntoFile(L, "book.txt");
	printf("\nɾ���ɹ���\n");

	system("pause");
	MainMenu();
}


//�۸����
void Modify(SqList& L) {
	system("cls");

	for (int i = 0; i < L.length; i++) {
		if (L.elem[i].price < 45) {
			L.elem[i].price *= 1.2;
		}
		else {
			L.elem[i].price *= 1.1;
		}
	}

	printf("�۸���º��ͼ����Ϣ��\n");
	printf("    ISBN                  ����                             ����\n");
	for (int i = 0; i < L.length; i++) {
		printf("%-20s%-40s%.2f\n", L.elem[i].no, L.elem[i].name, L.elem[i].price);
	}
	printf("=================================================================\n\n");

	WriteIntoFile(L, "book-newprice.txt");
	printf("�۸���º��ͼ����Ϣ�Ѵ���book-newprice.txt\n\n");

	system("pause");
	MainMenu();
}


//�۸�����
void Sort(SqList& L) {
	system("cls");

	for (int i = 1; i < L.length; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (L.elem[i].price < L.elem[j].price) {
				swap(L.elem[i], L.elem[j]);
				i = j - 1;
			}
			else {
				break;
			}
		}
	}

	printf("�۸�������ͼ����Ϣ��\n");
	printf("    ISBN                  ����                             ����\n");
	for (int i = 0; i < L.length; i++) {
		printf("%-20s%-40s%.2f\n", L.elem[i].no, L.elem[i].name, L.elem[i].price);
	}
	printf("=================================================================\n\n");

	WriteIntoFile(L, "book-newsort.txt");
	printf("�۸�������ͼ����Ϣ�Ѵ���book-newsort.txt\n\n");

	system("pause");
	MainMenu();
}


//���򴢴�
void Inverse(SqList& L) {
	system("cls");

	Book b;
	for (int i = 0; i < L.length / 2; i++) {
		b = L.elem[i];
		L.elem[i] = L.elem[L.length - i - 1];
		L.elem[L.length - i - 1] = b;
	}

	printf("���򴢴���ͼ����Ϣ��\n");
	printf("    ISBN                  ����                             ����\n");
	for (int i = 0; i < L.length; i++) {
		printf("%-20s%-40s%.2f\n", L.elem[i].no, L.elem[i].name, L.elem[i].price);
	}
	printf("=================================================================\n\n");

	WriteIntoFile(L, "book-newinverse.txt");
	printf("���򴢴���ͼ����Ϣ�Ѵ���book-newinverse.txt\n\n");

	system("pause");
	MainMenu();
}


//�˳�
void Quit() {
	system("cls");

	printf("�Ƿ��˳���y/n��");
	char op;
	cin >> op;
	if (op == 'n' || op == 'N') {
		MainMenu();
	}
	else if (op == 'y' || op == 'Y') {
		exit(0);
	}
	else if (op != 'y' || op != 'Y' || op != 'n' || op != 'N') {
		cout << "����������������룡" << endl;
		system("pause");
		Quit();
	}
}

//��λ�ò���
void SearchByPosition(SqList& L) {
	system("cls");

	int pos;
	printf("������Ҫ����ͼ���λ��(1-%d):", L.length);
	cin >> pos;

	while (pos < 1 || pos > L.length) {
		printf("����λ�ò������ڣ����������룺");
		cin >> pos;
	}

	printf("������Ϣ���£�\n");
	printf("    ISBN                  ����                             ����\n");
	printf("%-20s%-40s%.2f\n", L.elem[pos - 1].no, L.elem[pos - 1].name, L.elem[pos - 1].price);

	system("pause");
	MainMenu();
}


//����������
void SearchByName(SqList& L) {
	system("cls");

	char name[50];
	printf("������Ҫ����ͼ�������:");
	cin >> name;

	SqList tmp;
	Init(tmp);

	for (int i = 0; i < L.length; i++) {
		if (strcmp(L.elem[i].name, name) == 0) {
			tmp.elem[tmp.length] = L.elem[i];
			tmp.length++;
		}
	}

	if (tmp.length == 0) {
		printf("\n�Բ��𣬲��޴��顣\n");
	}
	else {
		printf("\n������Ϣ���£�\n");
		printf("    ISBN                  ����                             ����\n");
		for (int i = 0; i < tmp.length; i++) {
			printf("%-20s%-40s%.2f\n", tmp.elem[i].no, tmp.elem[i].name, tmp.elem[i].price);
		}
	}

	delete tmp.elem;

	system("pause");
	MainMenu();
}