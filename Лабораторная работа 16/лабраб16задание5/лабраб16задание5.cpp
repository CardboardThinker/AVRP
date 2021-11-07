#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int i, N;
	cout << "Введите размер массива N" << endl;
	cin >> N;
	int* A;
	A = new int[N];
	cout << "Изначальный массив: ";
	for (i = 0; i < N; i++) {
		A[i] = i;
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "Элементы массива с нечетными номерами, выведенные в порядке возрастания их номеров: ";
	for (i = 0; i < N; i=i+2) {
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "Элементы массива с четными номерами, выведенные в порядке убывания их номеров: ";
	for (i = N-(N%2+1); i > 0; i = i - 2) {
		cout << A[i] << " ";
	}
	return 0;
}