#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int N, i = 0;
	float A, s = 0;
	cout << "Введите вещественное число A и целое число N (> 0). Используя один цикл, найти значение выражения 1 - A + A^2 - A^3 + . . . +- A^N" << endl;
	cout << "Введите A" << endl;
	cin >> A;
	cout << "Введите N" << endl;
	cin >> N;
	do {
		s = s + pow(-A, i);
		i = i + 1;
	} while (i <= N);
	cout << "значение выражения = " << s << endl;
	return 0;
}