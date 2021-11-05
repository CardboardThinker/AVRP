#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int N, F=0, f1 = 0 ,f2 = 1, K = 2;
	cout << "Дано целое число N (> 1), являющееся числом Фибоначчи: N = F от K. Найти целое число K — порядковый номер числа Фибоначчи N." << endl;
	cout << "Введите N" << endl;
	cin >> N;
	while (F < N) {
		F = f1 + f2;
		f1 = f2;
		f2 = F;
		K = K + 1;
	}
	cout << "K = " << K << endl;
	return 0;
}