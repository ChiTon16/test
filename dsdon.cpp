#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	int info;
	Node* link;
};

Node* first;
void init();
void insertFirst(int x);
void insertLast(int x);
Node* search(int x);
void processList();
int insert(int x,int y);
int DeleteFirst();
int DeleteLast();
int DeleteAfterNote(int x);

int main()
{
	int choose;
	bool check = false;
	do
	{
		system("cls");
		cout << "Menu\n1. Khoi tao danh sach \n"
			<< "2. Them vao dau danh sach \n"
			<< "3. Them vao cuoi danh sach \n"
			<< "4. Tim kiem ki tu trong danh sach \n"
			<< "5. Xuat danh sach \n"
			<< "6.Chen sau 1 so \n"
			<< "7.Xoa dau \n"
			<< "8.Xoa cuoi \n"
			<< "9.Xoa sau mot node \n"
			<< "10.Thoat \nBan chon: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			init();
			check = true;
			break;
		}
		case 2:
		{
			if (check)
			{
				int x;
				cout << "Nhap so can chen ";
				cin >> x;
				insertFirst(x);
				break;
			}
			else
			{
				cout << " Vui long khoi tao danh sach truoc \n";
				break;
			}
		}
		case 3:
		{
			if (check)
			{
				int x;
				cout << "Nhap so can chen ";
				cin >> x;
				insertLast(x);
				break;
			}
			else
			{
				cout << " Vui long khoi tao danh sach truoc \n";
				break;
			}
		}
		case 4:
		{
			if (check)
			{
				int x;
				cout << "Nhap so can tim ";
				cin >> x;
				if (search(x) != NULL)
					cout << "Co ton tai so can tim \n";
				break;
			}
			else
			{
				cout << " Vui long khoi tao danh sach truoc \n";
				break;
			}
		}
		case 5:
		{
			if (check)
			{
				processList();
				break;
			}
			else
			{
				cout << " Vui long khoi tao danh sach truoc \n";
				break;
			}
		}
		case 6:
		{
			if (check)
			{
				int x,y;
				cout << "Nhap so can chen ";
				cin >> x;
				cout << "Nhap gia tri de them vao sau ";
				cin >> y;
				if (insert(x, y))
				{
					cout << "Thanh cong \n";
				}
				else
					cout << "Failed \n";
				break;
			}
			else
			{
				cout << " Vui long khoi tao danh sach truoc \n";
				break;
			}
		}
		case 7:
		{
			if (check)
			{
				if (DeleteFirst())
				{
					cout << "Succesful \n";
				}
				else
					cout << "Failed \n";
				break;
			}
			else
			{
				cout << " Vui long khoi tao danh sach truoc \n";
				break;
			}
		}
		case 8:
		{
			if (check)
			{
				if (DeleteLast())
				{
					cout << "Succesful \n";
				}
				else
					cout << "Failed \n";
				break;
			}
			else
			{
				cout << " Vui long khoi tao danh sach truoc \n";
				break;
			}
		}
		case 9:
		{
			if (check)
			{
				int x;
				cout << "Nhap sau vi tri so can xoa ";
				cin >> x;
				if (DeleteAfterNote(x))
				{
					cout << "Successful \n";
				}
				else cout << "Failed \n";
				break;
			}
			else
			{
				cout << " Vui long khoi tao danh sach truoc \n";
				break;
			}
		}
		default:
		{
			cout << "Bye!";
		}
		}
		_getch();
	} while (choose >= 1 && choose <=9);
}

void insertFirst(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

void insertLast(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)
	{
		first = p;
	}
	else
	{
		Node* q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}

Node* search(int x)
{
	Node* p = first;
	while (p != NULL && p->info != x)
	{
		p = p->link;
	}
	return p;
}

void processList()
{
	Node* p = first;
	while (p != NULL)
	{
		cout << p->info<<endl;
		p = p->link;
	}
}

void init()
{
	first = NULL;
}

int insert(int x,int y)
{
	Node* p1 = search(y);
	if (p1 != NULL)
	{
		Node* p = new Node;
		p->info = x;
		p->link = p1->link;
		p1->link = p;
		return 1;
	}
	return 0;
}

int DeleteFirst()
{
	Node* p = first;
	if (p != NULL)
	{
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

int DeleteLast()
{
	if (first != NULL)
	{
		Node* q, * p;
		p = first;
		q = NULL;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
		{
			q->link = NULL;
			delete p;
		}
		else
		{
			first = NULL;
			delete p;
		}
		return 1;
	}
	return 0;
}

int DeleteAfterNote(int x)
{
	if (first != NULL)
	{
		Node* kq = search(x);
		if (kq == NULL)
		{
			return 0;
		}
		if (kq->link == NULL)
		{
			return 0;
		}
		Node* q = kq->link;
		kq->link = q->link;
		delete q;
		return 1;
	}
	return 0;
}