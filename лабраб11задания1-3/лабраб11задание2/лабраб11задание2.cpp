#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int A, B, C;
	cout << "Введите три числа. Программа найдет сумму двух больших из них" << endl;
	cout << "Введите A" << endl;
	cin >> A;
	cout << "Введите B" << endl;
	cin >> B;
	cout << "Введите С" << endl;
	cin >> C;
	if (C < A && C < B) {
		C = A + B;
		cout << "Сумма двух больших чисел = " << C << endl;
	}
	else if (B < A && B < C) {
		B = A + C;
		cout << "Сумма двух больших чисел = " << B << endl;
	}
	else {
		A = B + C;
		cout << "Сумма двух больших чисел = " << A << endl;
	}
	return 0;
}