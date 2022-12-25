include <iostream>

#include <string> 

using namespace std;

class cursor {

public:

    int x, y, size, vid, changex, changey, changesize, gashenie = 1;

    string changer;

    string vid1;

    void init() {

        if (0 > size > 15) {

            cout << "Введите корректные данные (размер) ";

            cin >> size;

        }

        if (vid > 1) {

            cout << "Введите корректные данные (вид курсора)";

            cin >> vid;

        }

        if (vid == 1) {

            vid1 = "вертикальный";

        }

        if (vid == 0) {

            vid1 = "горизонтальный";

        }

    }

    void read() {

        cout << "Введите координаты x = ";

        cin >> x;

        cout << "Введите координаты y = ";

        cin >> y;

        cout << "Введите вид курсора (1 - вертикальный, 0 - горизонтальный) ";

        cin >> vid;

        cout << "Введите размер курсора от 1 до 15 ";

        cin >> size;

    }

    void changexy() {

        cout << "если хотите изменить координаты курсора, нажмите k" << endl << "если хотите изменить размер курсора, нажмите x" << endl << "если хотите изменить вид курсора, нажмите v " << endl << "если хотите погасить курсор нажмите c" << endl << "если хотите восстановить курсор нажмите p" << endl;

        cin >> changer;

        if (changer == "k") {

            cout << "Введите новый x ";

            cin >> changex;

            x = changex;

            cout << "Введите новый y ";

            cin >> changey;

            y = changey;

        }

        if (changer == "x") {

            cout << "Введите новый размер";

            cin >> changesize;

            size = changesize;

        }

        if (changer == "v") {

            if (vid == 1) {

                vid1 = "горизонтальный";

                vid = 0;

            }

            else {

                vid1 = "вертикальный";

                vid = 1;

            }

        }

        if (changer == "c") {

            gashenie = 0;

        }

        if (changer == "p") {

            gashenie = 1;

        }

    }

    void display() {

        while (gashenie == 0) {

            cout << "Ваш курсор погашен " << endl;

            break;

        }

        if (gashenie == 1) {

            cout << " Координаты вашего курсора " << x << " " << y << endl << " Размер вашего курсора = " << size << endl << " Вид вашего курсора - " << vid1 << endl;

        }

    }



};

int main()

{

    setlocale(LC_ALL, "ru");

    cursor cursor;

    cursor.read();

    cursor.init();

    cursor.display();

    while (cursor.vid < 3) {

        cursor.changexy();

        cursor.init();

        cursor.display();

    }

    return 0;

}