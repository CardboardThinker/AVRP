#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int A;
	cout << "Введите целое число, чтобы проверить его на четность и знак" << endl;
	cin >> A;
	if (A > 0) {
		cout << "положительное ";
	}
	else if (A < 0) {
		cout << "отрицательное ";
	}
	else {
		cout << "нулевое ";
	}
	if ((A % 2) == 0 && A != 0) {
		cout << "четное ";
	}
	else if (A != 0) {
		cout << "нечетное ";
	}
	cout << "число";
	return 0;
}
