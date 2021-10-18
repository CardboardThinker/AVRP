#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int A, B, C;
	cout << "На плоскости расположены три точки: A, B, C. Программа определит, какая из двух последних точек (B или C) расположена ближе к A, и вывести эту точку и ее расстояние от точки A." << endl;
	cout << "Введите A" << endl;
	cin >> A;
	cout << "Введите B" << endl;
	cin >> B;
	cout << "Введите С" << endl;
	cin >> C;
	if (abs(B-A) < abs(C-A)) {
		C = abs(B - A);
		cout << "Точка B, AB = " << C << endl;
	}
	else if (abs(B - A) > abs(C - A)) {
		B = abs(C - A);
		cout << "Точка C, AC = " << B << endl;
	}
	else {
		B = abs(C - A);
		cout << "Точки B и C на одинаковом расстоянии от A; AC, AB = " << B << endl;
	}
	return 0;
}