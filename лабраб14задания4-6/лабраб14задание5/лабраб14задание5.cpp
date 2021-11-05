#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int A,B;
	cout << "Даны целые положительные числа A и B. Найти их наибольший общий делитель (НОД), используя алгоритм Евклида" << endl;
	cout << "Введите A" << endl;
	cin >> A;
	cout << "Введите B" << endl;
	cin >> B;
	while (A != B) {
		if (B > A) {
			B = B - A;
		}
		else {
			A = A - B;
		}
	}
	cout << "НОД = " << A << endl;
	return 0;
}