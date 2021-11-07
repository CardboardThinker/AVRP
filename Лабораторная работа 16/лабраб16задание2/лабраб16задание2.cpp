#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int i, N, A, D;
	cout << "Введите размер массива N" << endl;
	cin >> N;
	cout << "Введите первый член массива A" << endl;
	cin >> A;
	cout << "Введите знаменатель геометрической прогрессии массива D" << endl;
	cin >> D;
	int* mas;
	mas = new int[N];
	for (i = 0; i < N; i++) {
		mas[i] = A*pow(D,i);
		cout << mas[i] << " ";
	}
	return 0;
}