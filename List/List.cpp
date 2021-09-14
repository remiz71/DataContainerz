#include "List.h"
#include "List.h"

List::List()
{
	Head = nullptr;
	Tail = nullptr;

	Size = 0;
}
List::~List()
{
	clear();
}

// Methods

void List::push_front(int Data)
{
	Element* New = new Element(Data);
	New->pPrev = 0;
	New->pNext = Head;
	if (Head != 0)Head->pPrev = New;
	if (Size == 0)Head = Tail = New;
	else Head = New;
	Size++;
}
void List::push_back(int Data)
 {
	 Element* New = new Element(Data);
	 New->pNext = nullptr;
	 New->pPrev = Tail;
	 if (Tail != 0)Tail->pNext = New;
	 if (Size == 0)Tail = Head = New;
	 else Tail = New;
	 Size++;
 }
void List::pop_front()
{
		Element* Del = Head;
		Head = Head->pNext;
		Head->pPrev = nullptr;
		delete Del;
		Size--;
}
void List::pop_back()
{
	erase(Size);
}
void List::insert(int Data, int index)
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

		}

	}
	Size++;

}
void List::erase(int index)
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
void List::print()
{
	for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		cout << Temp->pPrev << " pPrev " << Temp << tab << Temp->Data << tab << Temp->pNext << " pNext " << endl;
}
void List::clear()
{
	while (Size) pop_front();
}