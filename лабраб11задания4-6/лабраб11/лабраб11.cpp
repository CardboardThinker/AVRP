#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int A;
	cout << "Введите целое положительное число от 1 до 999, чтобы проверить его на четность и значность" << endl;
	cin >> A;
	if ((A % 2) == 0) {
		cout << "четное ";
	}
	else {
		cout << "нечетное ";
	}
	if ((A / 100) >= 1) {
		cout << "трехзначное ";
	}
	else if ((A / 10) >= 1) {
		cout << "двухзначное ";
	}
	else {
		cout << "однозначное ";
	}
	cout << "число";
	return 0;
}
