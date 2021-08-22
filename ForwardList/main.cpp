#include <iostream>
using namespace std;

class Element
{
	int Data; // Знач
	Element* pNext; //Адрес след элемента
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
	Element* Head; //Голова списка , указывает на начальный элемент списка
public:
	ForwardList()
	{
		Head = nullptr; //Default Constructor создает пустой список.
						//Если голова указывает на ноль, то список пуст
						// т.е не содержить элементов и голове больше
						//НЕ на что указывать.
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
		// прикрепили элемент к списку
		New->pNext = Head;
		// Говорим что Новый элемент - начальный
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

