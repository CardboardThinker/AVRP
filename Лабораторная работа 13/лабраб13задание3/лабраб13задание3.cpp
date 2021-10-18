#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int N, i = 1, s = 0;
	cout << "Введите целое число N (> 0). Программа найдет квадрат данного числа, используя для его вычисления следующую формулу: N2 = 1 + 3 + 5 + . . . + (2·N − 1). После добавления к сумме каждого слагаемого выводить текущее значение суммы" << endl;
	cin >> N;
	do {
		s = s + i;
		i = i + 2;
		cout << s << endl;
	} 
	while (i <= (N * 2 - 1));
	return 0;
}