#include <iostream>
using namespace std;
void power3(float &A, float &B) {
	B = A * A * A;
}
int main(void) {
	int i;
	float A[5] = { 0.5 , 1, -2, 0.25, 7};
	for (i = 0; i < 5; i++) {
		power3(A[i], A[i]);
		cout << A[i] << endl;
	}
		return 0;
}