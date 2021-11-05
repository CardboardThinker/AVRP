#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int K=0,N,S=0;
	cout << "Введите целое число N (> 1). Программа выведет наименьшее из целых чисел K, для которых сумма 1 + 2 + . . . + K будет больше или равна N, и саму эту сумму." << endl;
	cout << "Введите N" << endl;
	cin >> N;
	while (S < N) {
		K = K + 1;
		S = S + K;
	}
	cout << "K = " << K << endl;
	cout << "сумма = " << S;
	return 0;
}