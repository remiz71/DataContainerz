#include "List.h"
#include "List.h"

List::List()
{
	Head = nullptr;
	Tail = nullptr;

	Size = 0;
}
List::List(const initializer_list<int>& il) :List() //Контейнер как наш ForwardList
{														   // Обьект, который организует хранение других обьектов в памяти
														   // Методы : Begin() - возвращает итератор на начало контейнера
														   // end() - в конец контейнера
	cout << typeid(il.begin()).name() << endl;
	for (int const* it = il.begin(); it != il.end(); it++)
	{
		this->push_back(*it);
	}

}
List::List(const List& other) :List()
{ 
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_back(Temp->Data);
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
				TempNext = TempNext->pNext; // Ищем элемент, стоящий следущим по индексу
			}
			Element* TempPrev = TempNext->pPrev; // Сохраняем предыдущий элемент
			Element* Temp = new Element(Data);
			TempPrev->pNext = Temp; // Записываем адрес темп в поле pNext пред элемента
			Temp->pNext = TempNext; // Записываем адрес след элемента в темп
			Temp->pPrev = TempPrev; // Записываем адрес пред элемент в темп
			TempNext->pPrev = Temp; //Записываем адрес темп в поле pPrev след элемента
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
		Del = Del->pNext; // Ищем элемент
	}
	Element* PrevD = Del->pPrev; // Создаем элемент стоящий после удаляемого
	Element* AfterD = Del->pNext; // Создаем элемент перед удаляемым
	if (index == 1) pop_front(); // Проверяем, не хотим ли мы удалить Head, если да то в Head пишем адрес след за ним элемента
	if (PrevD != 0 && Size != 0) PrevD->pNext = AfterD; // Проверяем , не Head ли предыдущий элемент? Если нет то переписываем адрес след элемента
	else if (AfterD != 0 && Size != 0) AfterD->pPrev = PrevD; // Проверяем, не Tail ли след элемент? Если нет, переписываем адрес пред элемента
	else if (index == Size) Tail = PrevD; // Проверяем, не хотим ли мы удалить Tail, если да то пишем в Tail адрес пред за ним элемента
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
	while (Size) pop_back();
}