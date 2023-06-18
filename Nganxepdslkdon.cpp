#include <iostream>
#include<conio.h>
using namespace std;

struct Node
{
	int info;
	Node* link;
};

Node *sp;
void init();
void Push(int x);
int Pop(int& x);
int isEmpty();
void process_Stack();
void delete_Stack();
int convert10to2(int tp);

int main()
{
	int chon, in = 0, x,n;
	do
	{
		system("cls");
		cout << "Menu\n1.Khoi tao danh sach\n"
			<< "2.Them phan tu\n"
			<< "3.Lay phan tu\n"
			<< "4.Kiem tra co rong hay khong\n"
			<< "5.Xuat\n"
			<< "6.Chuyen he 2 sang he 10 \n"
			<< "7.Thoat\n";
		cin >> chon;
		switch (chon)
		{
		case 1:
		{
			init();
			in = 1;
			cout << "Khoi tao thanh cong\n";
			break;
		}
		case 2:
		{
			if (in)
			{
				int x;
				cout << "Nhap so can them\n";
				cin >> x;
				Push(x);
				cout << "Da chen\n";
			}
			else
				cout << "Vui long khoi tao danh sach\n";
			break;
		}
		case 3:
		{
			if (in)
			{
				int x;
				if (Pop(x))
				{
					cout << "Da lay " << x << " ra khoi danh sach \n";
				}
				else
					cout << "Khong co gi de lay\n";
			}
			break;
		}
		case 4:
		{
			if (in)
			{
				int x;
				if (isEmpty())
				{
					cout << "Stack rong\n";
				}
				else
					cout << "Stack khong rong\n";
			}
			else
				cout << "Vui long khoi tao danh sach\n";
			break;
		}
		case 5:
		{
			if (in)
			{
				process_Stack();
			}
			else
				cout << "Vui long khoi tao danh sach\n";
			break;
		}
		case 6:
		{
			cout << "Nhap gia tri thap phan can chuyen sang nhi phan \n";
			int tp;
			cin >> tp;
			n = convert10to2(tp);
			if (n != INT_MIN)
				cout << "He nhi phan tuong ung la " << n << endl;
			else
				cout << "Chuyen khong thanh cong\n";
			break;
		}
		default:
		{
			delete_Stack();
			cout << "Ban chon thoat\n";
			break;
		}
		}
		_getch();
	} while (chon >= 1 && chon <= 6);
	return 0;
}

void init()
{
	sp = NULL;
}

void Push(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int Pop(int &x)
{
	if (sp != NULL)
	{
		Node* p = sp;
		x = p->info;
		sp = sp->link;
		delete p;
		return 1;
	}
	return 0;
}

int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
}

void process_Stack()
{
	cout << "Cac phan tu trong stack la \n";
	Node* p = sp;
	while (p != NULL)
	{
		cout << p->info << endl;
		p = p->link;
	}
}

int convert10to2(int tp)
{
	if (sp != NULL)
		delete_Stack();
	int np = 0;
	while (tp != 0)
	{
		int du = tp % 2;
		Push(du);
		tp /= 2;
	}
	int x;
	while (!isEmpty())
	{
		if (!Pop(x))
			return INT_MIN;
		np = np * 10 + x;
	}
	return np;
}

void delete_Stack()
{
		while (sp != NULL)
		{
			Node* p = sp;
			sp = sp->link;
			delete p;
		}
		cout << "Xoa toan bo stack thanh cong \n";
}