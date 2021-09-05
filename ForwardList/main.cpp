#include <iostream>
using namespace std;
#define delim "________________________________"

class Element
{
	int Data; // ����
	Element* pNext; //����� ���� ��������
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext){}
	~Element(){}
	friend class ForwardList;
};

class ForwardList
{
	int Size;
	Element* Head; //������ ������ , ��������� �� ��������� ������� ������
public:
	int GetSize() { return Size; }
	ForwardList()
	{
		Head = nullptr; //Default Constructor ������� ������ ������.
						//���� ������ ��������� �� ����, �� ������ ����
						// �.� �� ��������� ��������� � ������ ������
						//�� �� ��� ���������.
		Size = 0;
	}
	~ForwardList()
	{
		clear();
	}
	const int& operator[](const int index);


	// Adding elements
	void push_front(int Data) 
	{
		Element* New = new Element(Data);
		// ���������� ������� � ������
		New->pNext = Head;
		// ������� ��� ����� ������� - ���������
		Head = New;
		Size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			Head = new Element(Data);
		}
		else
		{
			Element* temp = this->Head;
			while (temp->pNext != nullptr)
			{
				temp = temp->pNext;
			}
			temp->pNext = new Element(Data);
		}
		Size++;
	 }
	
	void pop_front()
	{
		Element* temp = Head;

		Head = Head->pNext;

		delete temp;

		Size--;
	}
	void pop_back()
	{
		erase(Size - 1);
	}

	void insert(int Data, int index)
	{
		if (index==0)
		{
			push_front(Data);
		}
		else
		{
			Element* temp = this->Head; 
			for (int i = 0; i < index -1; i++)
				{
				temp = temp->pNext; // �������� � ���� ����� ��������, �������� �� �����, ���� �� ����� �������� ��������
				}
			Element* New = new Element(Data, temp->pNext);
			temp->pNext = New;
		}
	}
	void erase(int index)
	{
		if (index == 0)
		{
			pop_front();
		}
		else
		{
			Element* temp = this->Head;
			for (int i = 0; i < index - 1; i++)
			{
				temp = temp->pNext; // �������� � ���� ����� ��������, �������� �� �����, ��� �� ����� �������  
			}
			Element* Delete = temp->pNext;
			temp->pNext = Delete->pNext;
			delete Delete;
			Size--;

		}
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
	void clear()
	{
		while (Size)
		{
			pop_front();
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
		list.push_front(rand() % 100);
	}
	/*list.print();*/
	cout << "element test  " << list[2] << endl;
	/*list.push_back(5);
	list.push_back(10);
	list.print();
	list.pop_front();*/

	list.print();
	cout << delim << endl;
	cout << endl;
	cout << "Deleting the last element..." << endl;
	list.pop_back();
	cout << delim << endl;
	list.print();
	
	



}

const int& ForwardList::operator[](const int index)
{
	int counter = 0;
	Element *temp = this->Head;
	while (temp!=nullptr)
	{
		if (counter == index)
		{
			return temp->Data;
		}
		temp = temp->pNext;
		counter++;
	}

}
