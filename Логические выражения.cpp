#include <iostream> 

using namespace std;

int main()

{

	setlocale(LC_ALL, "ru");

	int a, b, c;

	cout << "Введите число a,b,c ";

	cin >> a >> b >> c;

	cout << "Логическое высказывание = " << ((a + b > c) && (c + a > b) && (b + c > a));

}