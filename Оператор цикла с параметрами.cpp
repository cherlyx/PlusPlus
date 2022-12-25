#include <iostream> 

#include <math.h> 

using namespace std;

int main()

{

	setlocale(LC_ALL, "Russian");

	int n, k;

	double summ = 0;

	cout << "Введите k,n > 0";

	cin >> k >> n;

	for (; n > 0; n--) {

		summ = pow(n, k) + summ;

	}

	cout << summ;

}