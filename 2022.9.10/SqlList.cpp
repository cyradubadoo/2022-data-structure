#include <iostream>
#include <fstream>
#include <cstring>
#include<iomanip>

using namespace std;


typedef struct {
	char no[20];   //图书ISBN
	char name[50];   //书名
	double price;   //图书价格
}Book;

typedef struct {
	Book* elem;//储存空间的基地址
	int length;//图书表中当前图书的个数
}SqList;

void Init(SqList& L);//初始化
void ReadFromFile(SqList& L);//读文件
void WriteIntoFile(SqList& L, string file);//写文件

void MainMenu();//显示主菜单
void ShowAll(SqList& L);//图书浏览
void Statistics(SqList& L);//图书统计
void Insert(SqList& L);//插入
void Delete(SqList& L);//删除
void Modify(SqList& L);//价格更新
void Sort(SqList& L);//价格排序
void Inverse(SqList& L);//逆序储存
void Quit();//退出

void SearchMenu();//显示查找菜单
void SearchByPosition(SqList& L);//按位置查找
void SearchByName(SqList& L);//按书名查找


int main() {
	MainMenu();
	return 0;
}

void MainMenu() {
	system("cls");
	printf("*******************图书管理系统*******************\n");
	printf("1)图书浏览----------------------------------------1\n");
	printf("2)图书统计----------------------------------------2\n");
	printf("3)图书插入----------------------------------------3\n");
	printf("4)图书删除----------------------------------------4\n");
	printf("5)图书查找----------------------------------------5\n");
	printf("6)价格更新----------------------------------------6\n");
	printf("7)价格排序----------------------------------------7\n");
	printf("8)逆序储存----------------------------------------8\n");
	printf("9)退出--------------------------------------------9\n\n");
	printf("请输入您想进行的操作：");

	SqList L;
	Init(L);
	ReadFromFile(L);
	int op;
	cin >> op;
	switch (op) {
	case 1: {//图书浏览
		ShowAll(L);
		break;
	}
	case 2: {//图书统计
		Statistics(L);
		break;
	}
	case 3: {//图书插入
		Insert(L);
		break;
	}
	case 4: {//图书删除
		Delete(L);
		break;
	}
	case 5: {//图书查找
		SearchMenu();
		break;
	}
	case 6: {//价格更新
		Modify(L);
		break;
	}
	case 7: {//价格排序
		Sort(L);
		break;
	}
	case 8: {//逆序储存
		Inverse(L);
		break;
	}
	case 9: {//退出
		Quit();
		break;
	}
	default: {//非法输入
		printf("输入失败，请重新输入！\n\n");
		system("pause");
		MainMenu();
		break;
	}
	}
	delete L.elem;//释放空间
}

void SearchMenu() {
	system("cls");
	printf("******************请选择查找方式******************\n");
	printf("1)按位置查找--------------------------------------1\n");
	printf("2)按书名查找--------------------------------------2\n");
	printf("3)取消查找----------------------------------------3\n\n");
	printf("请输入您想进行的操作：");

	SqList L;
	Init(L);
	ReadFromFile(L);
	int op;
	cin >> op;
	switch (op) {
	case 1: {//按位置查找
		SearchByPosition(L);
		break;
	}
	case 2: {//按书名查找
		SearchByName(L);
		break;
	}
	case 3: {//返回主菜单
		MainMenu();
		break;
	}
	default: {//非法输入
		printf("输入失败，请重新输入！\n\n");
		system("pause");
		SearchMenu();
		break;
	}
	}
	delete L.elem;
}


//初始化
void Init(SqList& L) {
	L.elem = new Book[1000];
	if (!L.elem) {
		exit(-2);
	}
	L.length = 0;
}


//读文件
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


//写文件
void WriteIntoFile(SqList& L, string file) {
	ofstream write(file);

	if (!write) {
		exit(0);
	}

	write << "北京林业大学图书馆计算机类图书列表" << endl;
	write << "ISBN                      书名                 定价" << endl;

	for (int i = 0; i < L.length; i++) {
		write << std::left << setw(20) << L.elem[i].no << setw(40) << L.elem[i].name << L.elem[i].price << endl;
	}

	write.close();
}


//显示所有图书
void ShowAll(SqList& L) {
	system("cls");

	if (L.length == 0) {
		printf("没有图书。\n\n");
	}
	else {
		printf("所有图书信息如下：\n");
		printf("    ISBN                  书名                             定价\n");
		for (int i = 0; i < L.length; i++) {
			printf("%-20s%-40s%.2f\n", L.elem[i].no, L.elem[i].name, L.elem[i].price);
		}
		printf("=================================================================\n\n");
	}

	system("pause");
	MainMenu();
}


//图书统计
void Statistics(SqList& L) {
	system("cls");

	if (L.length == 0) {
		printf("没有图书。\n\n");
	}
	else {
		int i = L.length;
		printf("图书总数为%d。\n", i);
	}

	system("pause");
	MainMenu();
}


//插入
void Insert(SqList& L) {
	system("cls");

	int pos;
	Book book;

	printf("请输入要插入图书的位置(1-%d):", L.length);
	cin >> pos;

	while (pos < 1 || pos > L.length + 1) {
		printf("插入位置不合法，请重新输入插入位置：");
		cin >> pos;
	}

	printf("请输入图书ISBN：");
	cin >> book.no;
	printf("请输入图书书名：");
	cin >> book.name;
	printf("请输入图书价格：");
	cin >> book.price;

	for (int i = L.length - 1; i >= pos - 1; i--) {
		L.elem[i + 1] = L.elem[i];
	}
	L.elem[pos - 1] = book;
	L.length++;

	WriteIntoFile(L, "book.txt");
	printf("\n插入成功！\n");

	system("pause");
	MainMenu();
}


//删除
void Delete(SqList& L) {
	system("cls");

	int pos;

	printf("请输入要删除图书的位置(1-%d):", L.length);
	cin >> pos;

	while (pos < 1 || pos > L.length + 1) {
		printf("删除位置不不存在，请重新输入删除位置：");
		cin >> pos;
	}

	for (int i = pos; i <= L.length - 1; i++) {
		L.elem[i - 1] = L.elem[i];
	}
	L.length--;

	WriteIntoFile(L, "book.txt");
	printf("\n删除成功！\n");

	system("pause");
	MainMenu();
}


//价格更新
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

	printf("价格更新后的图书信息：\n");
	printf("    ISBN                  书名                             定价\n");
	for (int i = 0; i < L.length; i++) {
		printf("%-20s%-40s%.2f\n", L.elem[i].no, L.elem[i].name, L.elem[i].price);
	}
	printf("=================================================================\n\n");

	WriteIntoFile(L, "book-newprice.txt");
	printf("价格更新后的图书信息已存入book-newprice.txt\n\n");

	system("pause");
	MainMenu();
}


//价格排序
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

	printf("价格排序后的图书信息：\n");
	printf("    ISBN                  书名                             定价\n");
	for (int i = 0; i < L.length; i++) {
		printf("%-20s%-40s%.2f\n", L.elem[i].no, L.elem[i].name, L.elem[i].price);
	}
	printf("=================================================================\n\n");

	WriteIntoFile(L, "book-newsort.txt");
	printf("价格排序后的图书信息已存入book-newsort.txt\n\n");

	system("pause");
	MainMenu();
}


//逆序储存
void Inverse(SqList& L) {
	system("cls");

	Book b;
	for (int i = 0; i < L.length / 2; i++) {
		b = L.elem[i];
		L.elem[i] = L.elem[L.length - i - 1];
		L.elem[L.length - i - 1] = b;
	}

	printf("逆序储存后的图书信息：\n");
	printf("    ISBN                  书名                             定价\n");
	for (int i = 0; i < L.length; i++) {
		printf("%-20s%-40s%.2f\n", L.elem[i].no, L.elem[i].name, L.elem[i].price);
	}
	printf("=================================================================\n\n");

	WriteIntoFile(L, "book-newinverse.txt");
	printf("逆序储存后的图书信息已存入book-newinverse.txt\n\n");

	system("pause");
	MainMenu();
}


//退出
void Quit() {
	system("cls");

	printf("是否退出？y/n：");
	char op;
	cin >> op;
	if (op == 'n' || op == 'N') {
		MainMenu();
	}
	else if (op == 'y' || op == 'Y') {
		exit(0);
	}
	else if (op != 'y' || op != 'Y' || op != 'n' || op != 'N') {
		cout << "输入错误，请重新输入！" << endl;
		system("pause");
		Quit();
	}
}

//按位置查找
void SearchByPosition(SqList& L) {
	system("cls");

	int pos;
	printf("请输入要查找图书的位置(1-%d):", L.length);
	cin >> pos;

	while (pos < 1 || pos > L.length) {
		printf("查找位置不不存在，请重新输入：");
		cin >> pos;
	}

	printf("查找信息如下：\n");
	printf("    ISBN                  书名                             定价\n");
	printf("%-20s%-40s%.2f\n", L.elem[pos - 1].no, L.elem[pos - 1].name, L.elem[pos - 1].price);

	system("pause");
	MainMenu();
}


//按书名查找
void SearchByName(SqList& L) {
	system("cls");

	char name[50];
	printf("请输入要查找图书的书名:");
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
		printf("\n对不起，查无此书。\n");
	}
	else {
		printf("\n查找信息如下：\n");
		printf("    ISBN                  书名                             定价\n");
		for (int i = 0; i < tmp.length; i++) {
			printf("%-20s%-40s%.2f\n", tmp.elem[i].no, tmp.elem[i].name, tmp.elem[i].price);
		}
	}

	delete tmp.elem;

	system("pause");
	MainMenu();
}