#include <iostream>
using namespace std;
float RingS(float& R1,float& R2) {
	const double PI = 3.141592653589793;
	float r;
	r = PI * R1 * R1 - PI * R2 * R2;
	cout << r << endl;
	return R1, R2;
}
int main(float) {
	setlocale(LC_ALL, "Russian");
	float R1, R2;
	int i;
	for (i = 0; i < 3; i++) {
		cout << "Введите радиус внешнего круга" << endl;
		cin >> R1;
		cout << "Введите радиус внутреннего круга" << endl;
		cin >> R2;
		RingS(R1, R2);
	}
	return 0;
}