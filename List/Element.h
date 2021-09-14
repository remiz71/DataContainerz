#pragma once
#ifndef ELEMENT
#define ELEMENT
class Element
{
	int Data;
	Element* pNext; // pointer of next element
	Element* pPrev; // pointer of previous element
public:
	Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr);
	~Element();
	friend class List;
};
#endif