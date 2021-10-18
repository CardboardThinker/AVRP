#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int N, i=0;
	float a=1.1, s=1;
	cout << "Введите целое число N (> 0). Найти произведение 1.1 · 1.2 · 1.3 · . . . (N сомножителей)." << endl;
	cin >> N;
	while (i < N) {
		s = s * a;
		a = a + 0.1;
		i = i + 1;
	}
	cout << s << endl;
	return 0;
}