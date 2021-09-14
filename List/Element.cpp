#include "Element.h"

Element::Element(int Data, Element* pNext, Element* pPrev) :Data(Data), pNext(pNext), pPrev(pPrev) {};
Element::~Element() {}