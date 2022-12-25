#include <iostream> 

#include <math.h> 

using namespace std;



int main()

{

    setlocale(LC_ALL, "Russian");

    int N;

    int f = 0;

    cout << "Введите размер массива N  ";

    cin >> N;

    int k = 0;

    int m = 0;

    int s = 0;

    int* arr_a = new int[N];

    int* arr_b = new int[N];

    for (int i = 0; i < N; i++) {

        cout << "Введите элемент массива " << s + 1;

        s += 1;

        cin >> m;

        arr_a[i] = m;

    }

    cout << "Ваш массив a - ";

    for (int i = 0; i < N; i++) {

        cout << arr_a[i] << " ";

    }

    int sum = 0;

    cout << "Ваш массив b - ";

    for (int i = 0; i < N; i++) {

        arr_b[i] = 0;

        for (int k = i; k < N; k++)

            arr_b[i] += arr_a[k];

        cout << arr_b[i];

    }

    return 0;

}