#include <iostream>
using namespace std;
int sign(float &x) {
	if (x == 0) {
		x = 0;
	}
	else if (x > 0) {
		x = 1;
	}
	else {
		x = -1;
	}
	return x;
}
int main(int) {
	setlocale(LC_ALL, "Russian");
	int sum;
	float A, B;
	cout << "Введите A" << endl;
	cin >> A;
	cout << "Введите B" << endl;
	cin >> B;
	sign(A);
	sign(B);
	sum = A + B;
	cout << "sign(A)+sign(B)=" << sum;
	return 0;
}