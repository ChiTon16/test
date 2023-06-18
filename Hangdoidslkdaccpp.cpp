// Hang doi pphap tinh tien
#include <iostream>
#include <conio.h>
using namespace std;
#define Max 100

void init(int a[], int& front, int& rear);
int Push(int a[], int& front, int& rear, int x);
int Pop(int a[], int& front, int& rear, int& x);

int main()
{
	int a[Max];
	int chon, in = 0, x,front, rear;
	do
	{
		system("cls");
		cout << "Menu\n1.Khoi tao danh sach\n"
			<< "2.Them phan tu ra khoi danh sach\n"
			<< "3.Lay phan tu ra khoi danh sach \n"
			<< "4.Thoat\n";
		cin >> chon;
		switch (chon)
		{
		case 1:
		{
			init(a,front,rear);
			in = 1;
			cout << "Khoi tao thanh cong\n";
			break;
		}
		case 2:
		{
			if (in)
			{
				cout << "Nhap so can them vao\n";
				cin >> x;
				if (Push(a,front,rear,x))
					cout << "Da them thanh cong\n";
				else
					cout << "Them khong thanh cong\n";
			}
			else
				cout << "Vui long khoi tao danh sach truoc\n";
			break;
		}
		case 3:
		{
			if (in)
			{
				if (Pop(a, front, rear, x))
					cout << "Da lay " << x << " ra khoi hang doi\n";
				else
					cout << "Hang doi rong khong lay duoc gi \n";
			}
			else
				cout << "Vui long khoi tao danh sach truoc\n";
			break;
		}
		default:
		{
			cout << "Ban chon thoat\n";
			break;
		}
		}
		_getch();
	} while (chon >= 1 && chon <= 3);
	return 0;
}

void init(int a[], int& front, int& rear)
{
	front = rear = -1;
}

int Push(int a[], int& front, int& rear, int x)
{
	if (rear - front == Max - 1)
		return 0;
	if (front == -1)
		front = 0;
	if (rear == Max - 1)
	{
		for (int i = front; i <= rear; i++)
			a[i - front] = a[i];
		rear = Max - 1-front;
		front = 0;
	}
	a[++rear] = x;
	return 1;
}

int Pop(int a[], int& front, int& rear, int& x)
{
	if (front != -1)
	{
		x = a[front++];
		if (front > rear)
		{
			front = -1;
			rear = -1;
		}
		return -1;
	}
	return 0;
}