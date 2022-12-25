#include <iostream> 

using namespace std;



int main() {

    setlocale(LC_ALL, "Russian");

    int n, m;

    cout << "Достоинство:";

    cin >> n;

    cout << "Масть:";

    cin >> m;



    switch (n) {

    case 6:

        cout << "шестёрка ";

        break;

    case 7:

        cout << "семёрка ";

        break;

    case 8:

        cout << "восьмёрка ";

        break;

    case 9:

        cout << "девятка ";

        break;

    case 10:

        cout << "десятка ";

        break;

    case 11:

        cout << "валет ";

        break;

    case 12:

        cout << "дама ";

        break;

    case 13:

        cout << "король ";

        break;

    case 14:

        cout << "туз ";

        break;

    }



    switch (m) {

    case 1:

        cout << "пик" << endl;

        break;

    case 2:

        cout << "треф" << endl;

        break;

    case 3:

        cout << "бубен" << endl;

        break;

    case 4:

        cout << "червей" << endl;

        break;

    }

}