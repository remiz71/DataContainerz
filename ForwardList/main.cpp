#include <iostream>
using namespace std;

class Element
{
	int Data; // ����
	Element* pNext; //����� ���� ��������
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};

class ForwardList
{
	Element* Head; //������ ������ , ��������� �� ��������� ������� ������
public:
	ForwardList()
	{
		Head = nullptr; //Default Constructor ������� ������ ������.
						//���� ������ ��������� �� ����, �� ������ ����
						// �.� �� ��������� ��������� � ������ ������
						//�� �� ��� ���������.
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	// Adding elements

	void pushFront(int Data) 
	{
		Element* New = new Element(Data);
		// ���������� ������� � ������
		New->pNext = Head;
		// ������� ��� ����� ������� - ���������
		Head = New;
	}

	void print()const
	{
		Element* Temp = Head;
		while (Temp)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n; cout << " Enter the size of list: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.pushFront(rand() % 100);
	}
	list.print();




}

