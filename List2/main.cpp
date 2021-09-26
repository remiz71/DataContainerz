#include<iostream>
using namespace std;

//#define DEBUG

template<typename T>

class List
{
	class Element
	{
		T Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr) :Data(Data), pNext(pNext), pPrev(pPrev)
		{
#ifdef DEBUG
			cout << "EConstructor:\t" << this << endl;
#endif // DEBUG
		}
		~Element()
		{
#ifdef DEBUG
			cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

		}
		friend class List;
	}*Head, * Tail;
	/*Element* Head;
	Element* Tail;*/
	size_t size;
public:
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) :Temp(Temp)
		{
#ifdef DEBUG
			cout << "ITConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~Iterator()
		{
#ifdef DEBUG
			cout << "ITDesctructor:\t" << this << endl;
#endif // DEBUG

		}

		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}
		
		Iterator operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		bool operator==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator !=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}

		const int& operator*()const
		{
			return this->Temp->Data;
		}
		int& operator*()
		{
			return this->Temp->Data;
		}

	};
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}


	size_t get_size()const
	{
		return this->size;
	}
	List()
	{
		//Конструктор по умолчанию - создает пустой список.
		Head = Tail = nullptr;
		size = 0;
#ifdef DEBUG
		cout << "LConstructor:\t" << this << endl;
#endif // DEBUG
	}
	List(const initializer_list<T>& il):List()
	{
		for (T const* it = il.begin(); it != il.end(); it++)
		{
				push_back(*it);
		}
	}
	List(const List<T>& other) :List()
	{
		for (Element* Temp = other.Head; Temp; Temp++)push_back(Temp->Data);
#ifdef DEBUG
		cout << "LCopyConstructor:\t" << this << endl;
#endif // DEBUG
	}
	
	~List()
	{
		/*while (Head)pop_front();*/
		while (Tail) pop_back();
#ifdef DEBUG
		cout << "LDestructor:\t" << this << endl;
#endif // DEBUG

	}

	//						operators:

	List<T>& operator=(const List<T>& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp=Temp->pNext)push_back(Temp->Data);
#ifdef DEBUG
		cout << "LCopyAssigment:\t" << this << endl;
#endif // DEBUG

		return *this;
	}
	

	//						Adding elements:
	void push_front(T Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
		}
		else
		{
			/*Element* New = new Element(Data);
			New->pNext = Head;
			Head->pPrev = New;
			Head = New;*/
			Head = Head->pPrev = new Element(Data, Head);
		}
		size++;
	}
	void push_back(T Data)
	{
		if (!Head && !Tail)return push_front(Data);
		/*Element* New = new Element(Data);
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;*/
		Tail = Tail->pNext = new Element(Data,nullptr, Tail);
		size++;
	}

	//						Methods:
	void print()const
	{
		cout << "Адрес начала списка: " << Head << endl;
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
		cout << "Количество элементов списка: " << this->size << endl;
	}
	void reverse_print()const
	{
		cout << "Адрес конца списка: " << Tail << endl;
		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
			cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
		cout << "Количество элементов списка: " << this->size << endl;
	}
	//						Removing Elements
	void pop_front()
	{
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			return;
		}
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
		size--;
	}
	void pop_back()
	{
		if (Tail == Head) return pop_front();
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
		size--;
	}
	//						Inserting Elements
};
//#define BASE_CHECK
//#define ITERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		/*list.push_front(rand() % 100);*/
		list.push_back(rand() % 100);
	}
	list.print();
	list.reverse_print();
#endif // BASE_CHECK
#ifdef ITERATORS_CHECK
	List list = { 3,5,8,13,21 };
	list.print();
	List list2;
	list2 = list;
	for (List::Iterator it = list2.begin(); it != list2.end(); it++)
	{
		cout << *it << endl;
	}
#endif // ITERATORS_CHECK
	int arr[] = { 3,5,8,13,21 };
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	for (int i : arr) //Range-based for intended to work with only containers 
	{
		cout << i << "\t";
	}
	cout << endl;
	/*
	-------------------
	for(type i:container)
	{
			//i - iterator
	}
	*/
	List<int> list = { 0,1,1,2,3,5,8,13,21 };
	for (int i : list)
	{
		cout << i << "\t";
	}
	cout << endl;


}