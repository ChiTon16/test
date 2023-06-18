#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	int info;
	Node* link;
};

Node* front, * rear;

void init();
void Push(int x);
int Pop(int &x);
int isEmpty();
void deleteAllQueue();

int main()
{
	int chon, in=0, x;
	do
	{
		system("cls");
		cout << "Menu\n1.Khoi tao danh sach\n"
			<< "2.Them phan tu\n"
			<< "3.Lay phan tu\n"
			<< "4.Kiem tra co rong hay khong\n"
			<< "5.Xoa toan bo\n"
			<< "6.Thoat\n";
		cin >> chon;
		switch (chon)
		{
		case 1: 
		{
			init();
			cout << "Khoi tao thanh cong \n";
			in = 1;
			break;
		}
		case 2:
		{
			if (in)
			{
				int x;
				cout << "Nhap so can them vao \n";
				cin >> x;
				Push(x);
				cout << "Successful\n";
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
				if (Pop(x))
					cout << "Da lay so " << x << " ra khoi hang doi \n";
				else
					cout << "Khong lay duoc! Khong co gi \n";
			}
			else
				cout << "Vui long khoi tao danh sach \n";
			break;
		}
		case 4:
		{
			if (in)
			{
				if (isEmpty())
					cout << "Hang doi rong \n";
				else
					cout << "Hang doi khong rong\n";
			}
			else
				cout << "Vui long khoi tao danh sach \n";
			break;
		}
		case 5:
		{
			if (in)
			{
				deleteAllQueue();
			}
			else
				cout << "Vui long khoi tao danh sach \n";
			break;
		}
		default:
		{
			cout << "Thi ra may chon thoat\n";
		}
		}
		_getch();
	} while (chon >= 1 && chon <= 5);
	return 0;
}

void init()
{
	front = NULL;
	rear = NULL;
}

void Push(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

int Pop(int& x)
{

	if (front != NULL)
	{
		Node* p = front;
		x = p->info;
		front = front->link;
		return 1;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

int isEmpty()
{
	if (front == NULL)
		return 1;
	return 0;
}

void deleteAllQueue()
{
	if (front != NULL)
	{
		while (front != NULL)
		{
			Node* p = front;
			front = front->link;
			delete p;
		}
		cout << "Xoa thanh con me no cong \n";
	}
	else
		cout << "Co cai me gi dau ma xoa \n";
}