#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int i, j, N;
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
	cout << "Элементы массива, выведенные в нужной последовательности: ";
	j = N - 1;
	i = 0;
	while (i < N || j > 0) {
		cout << A[i] << " ";
		i = i + 1;
		cout << A[j] << " ";
		j = j - 1;
	}
	return 0;
}