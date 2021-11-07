#include <iostream>
using namespace std;
int Quarter(float& x, float& y) {
	int c = 0;
	if (x > 0 && y > 0) {
		c = 1;
	}
	if (x < 0 && y > 0) {
		c = 2;
	}
	if (x < 0 && y < 0) {
		c = 3;
	}
	if (x > 0 && y < 0) {
		c = 4;
	}
	cout << "Номер координатной четверти: " << c << endl;
	return x, y;
}
int main(int) {
	setlocale(LC_ALL, "Russian");
	float x, y;
	int i;
	for (i = 0; i < 3; i++) {
		cout << "Введите x" << endl;
		cin >> x;
		cout << "Введите y" << endl;
		cin >> y;
		Quarter(x, y);
	}
	return 0;
}