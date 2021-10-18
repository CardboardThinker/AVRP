#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int x,y;
	cout << "Введите координаты точки, не лежащей на координатных осях OX и OY. Программа определит номер координатной четверти, в которой находится данная точка" << endl;
	cout << "Введите x" << endl;
	cin >> x;
	cout << "Введите y" << endl;
	cin >> y;
	if (x > 0) {
		if (y > 0) {
			cout << "1";
		}
		else {
			cout << "4";
		}
	}
	else {
		if (y > 0) {
			cout << "2";
		}
		else {
			cout << "3";
		}
	}
return 0;
}