#include <iostream>
using namespace std;
float Fact2(int& N) {
	int i, f = 1;
	if ((N % 2) == 0) {
		for (i = 2; i <= N; i=i+2) {
			f = f * i;
		}
	}
	else {
		for (i = 1; i <= N; i = i + 2) {
			f = f * i;
		}
	}
	cout << f;
	return N;
}
int main(float) {
	setlocale(LC_ALL, "Russian");
	int N;
		cout << "Введите N" << endl;
		cin >> N;
		Fact2(N);
	return 0;
}