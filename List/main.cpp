#include <iostream>
using namespace std;
#define tab "\t"
#define delim "--------------------------------"

class Element
{
	int Data;
	Element* pNext; // pointer of next element
	Element* pPrev; // pointer of previous element
public:
	Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) :Data(Data), pNext(pNext), pPrev(pPrev) {};
	~Element(){}
	friend class List;
};

class List
{
	int Size;
	Element* Head;
	Element* Tail;
	int GetSize(){ return Size; };
public:
	List()
	{
		Head = nullptr;
		Tail = nullptr;

		Size = 0;
	} //Default constrctor
	~List()
	{
		clear();
	}

		// Methods
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pPrev = 0;
		New->pNext = Head;
		if (Head != 0)Head->pPrev = New;
		if (Size == 0)Head = Tail = New;
		else Head = New;
		Size++;
	}
	void push_back(int Data)
	{
		Element* New = new Element(Data);
		New->pNext= nullptr;
		New->pPrev = Tail;
		if (Tail != 0)Tail->pNext = New;
		if (Size == 0)Tail = Head = New;
		else Tail = New;
		Size++;
	}

	void pop_front()
	{
		Element* Del = Head;
		Head = Head->pNext;
		Head->pPrev = nullptr;
		delete Del;
		Size--;
	}
	void pop_back()
	{
		erase(Size);
	}

	void insert(int Data, int index)
	{
		if (index == 1)push_front(Data);
		else if (index < 1 || index > Size)cout << "Error" << endl;
		else
		{
			if (index <= Size / 2)
			{
				Element* TempNext = this->Head;
				for (int i = 1; i < index; i++)
				{
					TempNext = TempNext->pNext;
				}
				Element* TempPrev = TempNext->pPrev;
				Element* Temp = new Element(Data);
				TempPrev->pNext = Temp;
				Temp->pNext = TempNext;
				Temp->pPrev = TempPrev;
				TempNext->pPrev = Temp;
				delete Temp;
			}
			else
			{
				Element* TempPrev = this->Tail;
				for (int i = Size; i > index; i--)
				{
					TempPrev = TempPrev->pPrev;
				}
				Element* TempNext = TempPrev->pNext;
				Element* Temp = new Element(Data);
				TempPrev->pNext = Temp;
				Temp->pNext = TempNext;
				Temp->pPrev = TempPrev;
				TempNext->pPrev = Temp;
				delete Temp;

			}
			
		}
		Size++;
		
	}
	void erase(int index)
	{
		Element* Del = Head;
		for (int i = 1; i < index; i++)
		{
			Del = Del->pNext;
		}
		Element* PrevD = Del->pPrev;
		Element* AfterD = Del->pNext;
		if (PrevD != 0 && Size != 0) PrevD->pNext = AfterD;
		if (AfterD != 0 && Size != 0) AfterD->pPrev = PrevD;
		if (index == 1) Head = AfterD;
		if (index == Size) Tail = PrevD;
		delete Del;
		Size--;

	}

	void print()
	{
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp->pPrev << " pPrev " << Temp << tab << Temp->Data << tab << Temp->pNext << " pNext " << endl;
	}
	void clear()
	{
		while (Size) pop_front();
	}

};

int main()
{

	setlocale(LC_ALL, "Russian");

	int n; cout << " Enter the size of list: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand()%100);
	}
	list.print();
	//cout << delim << endl;
	//list.push_back(60);
	//list.print();
	cout << delim << endl;
	list.erase(1);
	list.print();
	
	return 0;
}