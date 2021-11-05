#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	float A, B;
	cout << "Введите положительные числа A и B (A > B). На отрезке длины A размещено максимально возможное количество отрезков длины B (без наложений). Программа найдет длину незанятой части отрезка A." << endl;
	cout << "Введите A" << endl;
	cin >> A;
	cout << "Введите B" << endl;
	cin >> B;
	while (A > B) {
		A = A - B;
	}
	cout << A;
	return 0;
}