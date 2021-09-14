#include <iostream>
#include "Element.h"
#include "List.h"
using namespace std;
#define tab "\t"
#define delim "--------------------------------"


int main()
{

	setlocale(LC_ALL, "Russian");

	int n; cout << " Enter the size of list: "; cin >> n;
	/*List list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand()%100);
	}
	list.print();
	cout << delim << endl;
	list.push_back(60);
	list.print();
	cout << delim << endl;
	list.insert(1,4);*/
	cout << typeid(List).name() << endl;
	
	
	return 0;
}