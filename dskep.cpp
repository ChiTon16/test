#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	int info;
	Node* next, * previous;
};

Node* first, * last;
void init();
void process_list();
void process_list_begin_last();
void insert_first(int x);
void insert_last(int x);
int delete_first();
int delete_last();
int count_Note();
Node* search(int x);


int main()
{
	int chon, x, in = 0;
	do
	{
		system("cls");
		cout << "Menu\n1.Khoi tao danh sach\n"
			<< "2.Xuat danh sach \n"
			<< "3.Xuat nguoc danh sach\n"
			<<"4.Tim kiem\n"
			<< "5.Chen dau\n"
			<< "6.Chen cuoi\n"
			<< "7.Xoa dau\n"
			<< "8.Xoa cuoi\n"
			<<"9.Dem so phan tu\n"
			<< "10.Thoat\n";
		cin >> chon;
		switch (chon)
		{
		case 1:
		{
			init();
			in = 1;
			cout << "Successful";
			break;
		}
		case 2:
		{
			if (in)
			{
				process_list();
			}
			else
				cout << "Vui long khoi tao danh sach \n";
			break;
		}
		case 3:
		{
			if (in)
			{
				process_list_begin_last();
			}
			else
				cout << "Vui long khoi tao danh sach \n";
			break;
		}
		case 4:
		{
			if (in)
			{
				int x;
				cout << "Nhap phan tu cam tim \n";
				cin >> x;
				if (search(x))
				{
					cout << x << " co ton tai \n";
				}
				else
					cout << x << "khong ton tai \n";
			}
			else
				cout << "Vui long khoi tao danh sach \n";
			break;
		}
		case 5:
		{
			if (in)
			{
				int x;
				cout << "Nhap ki tu can chen \n";
				cin >> x;
				insert_first(x);
				cout << "OK\n";
			}
			else
				cout << "Vui long khoi tao danh sach \n";
			break;
		}
		case 6:
		{
			if (in)
			{
				int x;
				cout << "Nhap ki tu can chen \n";
				cin >> x;
				insert_last(x);
				cout << "OK\n";
			}
			else
				cout << "Vui long khoi tao danh sach \n";
			break;
		}
		case 7:
		{
			if (in)
			{
				if (delete_first())
					cout << "Successful\n";
				else
					cout << "Failed\n";
			}
			else
				cout << "Vui long khoi tao danh sach \n";
			break;
		}
		case 8:
		{
			if (in)
			{
				if (delete_last())
				{
					cout << "Successful\n";
				}
				else
					cout << "Failed\n";
			}
			else
				cout << "Vui long khoi tao danh sach \n";
			break;
		}
		case 9:
		{
			if (in)
			{
				cout << "Co " << count_Note() << " ki tu \n";
			}
			else
				cout << "Vui long khoi tao danh sach \n";
			break;
		}
		default:
		{
			cout << "Ban chon thoat\n";
			break;
		}
		}
		_getch();
	} while (chon >= 1 && chon <= 9);;
	return 0;
}

void init()
{
	first = NULL;
	last = NULL;
}

void process_list()
{
	cout << "Cac phan tu tu dau den cuoi \n";
	Node* p = first;
	while (p!=NULL)
	{
		cout << p->info << " ";
		p = p->next;
	}
	cout << endl;
}

void process_list_begin_last()
{
	cout << "Cac phan tu tu cuoi den dau \n";
	Node* p = last;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->previous;
	}
	cout << endl;
}

void insert_first(int x)
{
	Node* p = new Node;
	p->info = x;
	p->previous = NULL;
	p->next = first;
	if (first != NULL)
	{
		first->previous = p;
	}
	else
	{
		last = p;
	}
	first = p;
}

void insert_last(int x)
{
	Node* p = new Node;
	p->info = x;
	p->next = NULL;
	p->previous = last;
	if (last != NULL)
	{
		last->next = p;
	}
	else
		first = p;
	last = p;
}

int delete_first()
{
	if (first != NULL)
	{
		Node* p = first;
		first = first->next;
		if (first == NULL)
		{
			last = NULL;
		}
		else
			first->previous = NULL;
		delete p;
		return 1;
	}
	return 0;
}

int delete_last()
{
	if (last != NULL)
	{
		Node* p = last;
		last = last->previous;
		if (last == NULL)
		{
			first == NULL;
		}
		else
			last->next = NULL;
		delete p;
		return 1;
	}
	return 0;
}

Node* search(int x)
{
	Node* p = first;
	while (p != NULL && p->info != x)
	{
		p = p->next;
	}
	return p;
}

int count_Note()
{
	int count = 0;
	Node* p = first;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}