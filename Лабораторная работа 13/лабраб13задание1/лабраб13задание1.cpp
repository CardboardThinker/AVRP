#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	float a,i=0.1;
	cout << "Введите вещественное число — цена 1 кг конфет. Программа выведет стоимость 0.1, 0.2, . . . , 1 кг конфет." << endl;
	cin >> a;
	while (i <= 1) {
		cout << "цена " << i << " кг конфет = " << a * i << endl;
		i = i + 0.1;
	}
	cout << "цена " << i << " кг конфет = " << a * i << endl;
	return 0;
}