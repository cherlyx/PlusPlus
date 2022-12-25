#include <iostream> 

#include <string> 

using namespace std;

class Time {

public:

    int h;

    int m;

    int first;

    int second;

    int min;

    void read() {

        cin >> h >> m;

    }

    void display() {

        cout << "Время в минутах " << min << endl;

    }

    void minutes() {

        min = (first * 60) + second;

    }

};



int main()

{

    setlocale(LC_ALL, "Russian");



    Time clock;

    cout << "Введите часы и минуты";

    clock.read();

    clock.first = clock.h;

    clock.second = clock.m;

    if ((clock.first < 0) || (clock.second < 0)) {

        cout << "Введите число больше или равное нулю";

    }

    else {

        clock.minutes();

        clock.display();

    }

}