#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int i, j, N, A, B;
	cout << "Введите размер массива N" << endl;
	cin >> N;
	cout << "Введите первый член массива A" << endl;
	cin >> A;
	cout << "Введите второй член массива B" << endl;
	cin >> B;
	int* mas;
	mas = new int[N];
	mas[0] = A;
	cout << mas[0] << " ";
	mas[1] = B;
	cout << mas[1] << " ";
	for (i = 2; i < N; i++) {
		mas[i] = 0;
		for (j = 0; j < i; j++) {
			mas[i] = mas[i] + mas[j];
		}
		cout << mas[i] << " ";
	}
	return 0;
}