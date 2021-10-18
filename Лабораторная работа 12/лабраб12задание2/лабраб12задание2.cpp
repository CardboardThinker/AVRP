#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	string C;
	int i;
	cout << "Робот может перемещаться в четырех направлениях («N» — север, «W» — запад, «E» — юг, «S» — восток) и принимать три цифровые команды: 0 — продолжать движение, 1 — поворот налево, −1 — поворот направо. Введите символ C — исходное направление робота и целое число N — посланную ему команда. Программа выведет направление робота после выполнения полученной команды" << endl;
	cout << "введите изначальное направление робота" << endl;
	cin >> C;
	cout << "введите команду для робота" << endl;
	cin >> i;
	if (C == "N") {
		if (i > 0) {
			cout << "W";
		}
		else if (i < 0) {
			cout << "E";
		}
		else {
			cout << "N";
		}
	}
	if (C == "E") {
		if (i > 0) {
			cout << "N";
		}
		else if (i < 0) {
			cout << "S";
		}
		else {
			cout << "E";
		}
	}
	if (C == "S") {
		if (i > 0) {
			cout << "E";
		}
		else if (i < 0) {
			cout << "W";
		}
		else {
			cout << "S";
		}
	}
	if (C == "W") {
		if (i > 0) {
			cout << "S";
		}
		else if (i < 0) {
			cout << "N";
		}
		else {
			cout << "W";
		}
	}
	return 0;
}