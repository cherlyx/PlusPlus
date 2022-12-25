#include <iostream>

#include <vector>

using namespace std;

int main() {

	setlocale(LC_ALL, "ru");

	cout << "Введите последовательность целых чисел, которая кончится отрицательным числом ";

	vector<int> numbers;

	int n;

	while (cin >> n && n >= 0) {

		numbers.push_back(n);

	}

	cout << "Введите k-ый элемент перед которым будет стоять 0: ";

	int k;

	cin >> k;

	for (int i = k - 1; i < numbers.size(); i += k) {

		numbers.insert(numbers.begin() + i, 0);

	}

	cout << "Последовательность с 0 после K-ого элемента: ";

	for (int number : numbers) {

		cout << number << " ";

	}

	return 0;

}