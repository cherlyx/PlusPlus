#include <iostream> 

using namespace std;

int main()

{

    setlocale(LC_ALL, "Russian");

    int X, A, Y, Count;

    cout << "Введите кол-во кг и цену конфет";

    cin >> X >> A;

    Count = A / X;

    cout << "Введите кол-во кг. требуемых к покупке Y=";

    cin >> Y;

    cout << "Цена 1 кг = " << Count << endl << " Цена за Y кг = " << Y * Count;

}