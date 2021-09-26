#include <iostream>
using namespace std;
void elevator(int level)
{
		if (level == 0)return;
		cout << level << endl;
		elevator(level - 1);
}

void main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Hello World"<<endl;
	int n;
	cout << "Number of floor : "; cin >> n;
	elevator(n);
}