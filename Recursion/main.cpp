#include <iostream>
using namespace std;
void elevator(int level)
{
		if (level == 0)return;
		cout << level << endl;
		elevator(level - 1);
}


int fact(int data)
{
	/*if (data == 0)return 1;
	else return data * fact(data - 1);*/
	return data == 0 ? 1 : data * fact(data - 1);
}

double power(double data, int pwr)
{
	/*if (pwr == 0) return 1;
	if (pwr < 0) return 1 / data * power(data, pwr + 1);
	if(pwr>0) return data * power(data, pwr - 1);*/
	return pwr==0?1:pwr < 0 ? 1 / data * power(data, pwr + 1) : data * power(data, pwr - 1);
}

//#define RECURSION_BASICS
//#define FACTORIAL_CHECK
#define POWER_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");
	double n;
	int pwr;
#ifdef RECURSION_BASICS
	cout << "Hello World" << endl;
	/*cout << "Number of floor : "; cin >> n;
	elevator(n);*/
#endif // RECURSION_BASICS

#ifdef FACTORIAL_CHECK
	cout << "Вычислить факториал числа : "; cin >> n;
	cout << "Факториал числа " << n << " = " << fact(n) << endl;
#endif // FACTORIAL_CHECK


#ifdef POWER_CHECK
	cout << "Введите основание : "; cin >> n;
	cout << "Введите показатель : "; cin >> pwr;

	cout << "Число " << n << " в степени " << pwr << " равно " << power(n, pwr) << endl;
}
#endif // POWER_CHECK
