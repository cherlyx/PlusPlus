#include <iostream> 

using namespace std;



int main()

{

    setlocale(LC_ALL, "Russian");

    int a1, a2, a3, a4;

    cout << "Введите a1,a2,a3,a4 3 из которых будут равными";

    cin >> a1 >> a2 >> a3 >> a4;

    if (a1 != a2 && a1 != a3)

        cout << "a1 не равен остальным";

    if (a2 != a1 && a2 != a3)

        cout << "a2 не равен остальным";

    if (a3 != a1 && a3 != a2)

        cout << "a3 не равен остальным";

    else

        cout << "a4 не равен остальным";

}