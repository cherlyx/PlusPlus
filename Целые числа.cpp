#include <iostream> 

using namespace std;



int main()

{

    setlocale(LC_ALL, "Russian");

    int i, s;

    cout << "Введите четырехзначное число = "; cin >> i;

    cout << "Произведение первых трёх и последней цифры = " << (i / 10) * (i % 10);

}