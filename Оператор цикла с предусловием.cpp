#include <iostream> 

using namespace std;

int main()

{

    Ssetlocale(LC_ALL, "RUSSIAN")

        int N, K, i;

    cout << "Введите N - ";

    cin >> N;

    K = 0;

    i = 0;

    while (i < N) {

        K = K + 1;

        i = i + K;

    }

    cout << "сумма =" << i;

    cout << "число =" << K;



}