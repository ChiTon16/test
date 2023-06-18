#include <iostream>
#include <conio.h>
using namespace std;
const int MAX=100;
void init(int a[],int &sp);
int Push(int a[], int& sp, int x);
int Pop(int a[], int& sp, int& x);
int isFull(int a[], int sp); //kiem tra đầy
int isEmpty(int a[], int sp); //kiểm tra rỗng
void XuatStacktudinh(int a[], int sp);
int Chuyen10sang2(int a[], int &sp,int tp);

int main()
{
	int a[MAX];
	int sp;
	int chon, x, in=0;
	do
	{
		system("cls");
		cout << "Menu\n1.Khoi tao danh sach \n"
			<< "2.Them 1 phan tu \n"
			<< "3.Lay 1 phan tu\n"
			<< "4.Kiem tra stack da day chua\n"
			<< "5.Kiem tra stack co rong khong\n"
			<<"6.Xuat danh sach trong stack \n"
			<< "7.Dung stack chuyen sang he nhi phan\n"
		<< "8.Thoat \n";
		cin >> chon;
		switch (chon)
		{
		case 1:
		{
			init(a,sp);
			in = 1;
			cout << "Khoi tao danh sach thanh cong \n";
			break;
		}
		case 2:
		{
			if (in)
			{
				int x;
				cout << "Chon phan tu can them vao \n";
				cin >> x;
				if (Push(a, sp, x))
				{
					cout << "Successful\n";
				}
				else
					cout << "Failed \n";
			}
			else
				cout << "Vui long khoi tao danh sach \n";
			break;
		}
		case 3:
		{
			if (in)
			{
				int x;
				if (Pop(a, sp, x))
					cout << "Lay thanh cong " << x << " ra khoi danh sach \n";
				else
					cout << "Failed \n";
			}
			else
				cout << "Vui long khoi tao danh sach \n";
			break;
		}
		case 4:
		{
			if (in)
			{
				if (isFull(a, sp))
					cout << "Stack da day\n";
				else
					cout << "Stack chua day \n";
			}
			else
				cout << "Vui long khoi tao danh sach \n";
			break;
		}
		case 5:
		{

			if (in)
			{
				if (isEmpty(a, sp))
					cout << "Stack rong\n";
				else cout <<"Stack khong rong\n";
			}
			else
				cout << "Vui long khoi tao danh sach \n";
			break;
		}
		case 6:
		{
			if (in)
			{
				if (!isEmpty(a,sp))
				{
					cout << "Cac phan tu trong stack tu dinh xuong la\n";
					XuatStacktudinh(a, sp);
				}
				else
					cout << "Danh sach khong co phan tu\n";
			}
			else
				cout << "Vui long khoi tao danh sach \n";
			break;
		}
		case 7:
		{
			x = 11;
			int np = Chuyen10sang2(a, sp, x);
			if (np == INT_MIN)
				cout << "Qua trinh chuyen doi khong thanh cong\n";
			else
				cout << "He nhi phan cua " << x << " la " << np << endl;
			break;
		}
		default:
		{
			cout << "Ban chon thoat!\n";
			break;
		}
		}
		_getch();
	}
	while (chon>=1&&chon<=7);
	return 0;
}

void init(int a[], int& sp)
{
	sp = -1;
}

int Push(int a[], int& sp, int x)
{
	if (sp < MAX - 1)
	{
	a[++sp] = x;
	return 1;
	}
	return 0;
}

int Pop(int a[], int& sp, int& x)
{
	if (sp > -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

int isFull(int a[], int sp)
{
	if (sp == MAX - 1)
		return 1;
	return 0;
}

int isEmpty(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}

void XuatStacktudinh(int a[], int sp)
{
	for (int i = sp; i > -1; i--)
		cout << a[i] << endl;
	cout << endl;
}

int Chuyen10sang2(int a[], int &sp,int tp)
{
	init(a, sp);
	while (tp != 0)
	{
		int du = tp % 2;
		if (!Push(a, sp, du))
			return INT_MIN;
		tp /= 2;
	}
	int np = 0;
	while (!isEmpty(a, sp))
	{
		int so;
		if (!Pop(a, sp, so))
			return INT_MIN;
		np = np * 10 + so;
	}
	return np;
}