#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int i, N;
	cout << "Введите размер массива N" << endl;
	cin >> N;
	int* mas;
    mas = new int [N];
	mas[0] = 1;
	cout << mas[0] << " ";
	for (i = 1; i < N; i++) {
		mas[i] = mas[i - 1] + 2;
		cout << mas[i] << " ";
	}
	return 0;
}