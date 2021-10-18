#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int A,B;
	cout << "Введите A и B. Если их значения не равны, то программа присвоит каждой переменной большее из этих значений, а если равны, то присвоит переменным нулевые значения." << endl;
	cout << "Введите A" << endl;
	cin >> A;
	cout << "Введите B" << endl;
	cin >> B;
	if (A == B) {
		A = 0;
		B = 0;
		cout << "A = " << A << endl;
		cout << "B = " << B << endl;
	}
	else if (A > B) {
		B = A;
        cout << "A = " << A << endl;
		cout << "B = " << B << endl;
	}
	else {
		A = B;
		cout << "A = " << A << endl;
		cout << "B = " << B << endl;
	}
	return 0;
}