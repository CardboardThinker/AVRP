#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int j, i, A, B;
	cout << "Введите целые положительные числа A и B (A < B). Программа выведет все целые числа от A до B включительно; при этом каждое число будет выводиться столько раз, каково его значение " << endl;
	cout << "Введите A" << endl;
	cin >> A;
	cout << "Введите B" << endl;
	cin >> B;
	for (i = A; i <= B; i++) {
		for (j = 1; j <= i; j++) {
			cout << i << " ";
	}
	}
	return 0;
}