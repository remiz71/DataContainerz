#include <iostream>

using namespace std;
#define delim "________________________________"
#define tab "\t"


class ForwardList
{
	int Size;
	Element* Head; //Голова списка , указывает на начальный элемент списка
public:
	int GetSize() { return Size; }
	ForwardList()
	{
		Head = nullptr; //Default Constructor создает пустой список.
						//Если голова указывает на ноль, то список пуст
						// т.е не содержить элементов и голове больше
						//НЕ на что указывать.
		Size = 0;
	}
	ForwardList(const initializer_list<int>& il):ForwardList() //Контейнер как наш ForwardList
	{														   // Обьект, который организует хранение других обьектов в памяти
															   // Методы : Begin() - возвращает итератор на начало контейнера
															   // end() - в конец контейнера
		cout << typeid(il.begin()).name() << endl;
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			this->push_back(*it);
		}

	}
	ForwardList(const ForwardList& other) :ForwardList()
	{
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
	}
	~ForwardList()
	{
		clear();
	}
	//Operators:

	ForwardList& operator=(const ForwardList& other)
	{
		//1. Delete old object's data
		while (Head)pop_front();
		//2. Byte-to-byte copying
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		return *this;
	}
	const int& operator[](const int index);


	// Adding elements
	void push_front(int Data) 
	{
		Element* New = new Element(Data);
		// прикрепили элемент к списку
		New->pNext = Head;
		// Говорим что Новый элемент - начальный
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
			while (temp->pNext)
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
				temp = temp->pNext; // копируем в темп адрес элемента, стоящего на месте, куда мы хотим вставить значение
				}
			temp->pNext = new Element(Data, temp->pNext);
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
				temp = temp->pNext; // копируем в темп адрес элемента, стоящего на месте, где мы хотим удалить  
			}
			Element* Delete = temp->pNext;
			temp->pNext = Delete->pNext;
			delete Delete;
			Size--;

		}
	}
	

	void print()const
	{
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	}
	void clear()
	{
		while (Size)
		{
			pop_front();
		}
	}
};

//#define BASE_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
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





#endif // BASE_CHECK

	ForwardList list = { 3,5,8,12,21 };
	list.print();
	ForwardList list2;
	list2 = list;
	cout << delim << endl;
	list2.print();

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

//Двусвязный список - список , каждый элемент которого иммеет указатель на пред. и след элемент.
// Это дает возможность ходить по списку в обоих направлениях. Уменьшает время поиска элемента в 2 раза
//У 2связнорго списка есть голова и хвост
// если список пуст, голова и хвост указывают на 0. Когда в списке появляется первый элемент,
//Он одновременно является и головой и хвостом списка. Являет первым и последним элементом списка.
//