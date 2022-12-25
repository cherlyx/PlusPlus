#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class MyExcept1 {}; 

class MyExcept2 { 
    string msg;
public:
    MyExcept2(const string& s) : msg(s) {}
    const char* message() const { return msg.c_str(); }
};

class MyExcept3 : public invalid_argument { 
    double num;
public:
    MyExcept3(const string msg, double n) : invalid_argument(msg), num(n) {}
    double arg() const { return num; }
};

bool is_leapYear1(int year) {
    if (year <= 0) throw "Неправильный год";
    return (!(year % 4) && (year % 100)) || (!(year % 400));
}

bool is_leapYear2(int year) throw() {
    if (year <= 0) throw "Неправильный год";
    return (!(year % 4) && (year % 100)) || (!(year % 400));
}

bool is_leapYear3(int year) throw(invalid_argument) {
    if (year <= 0)
        throw invalid_argument("Неправильный год");
    return (!(year % 4) && (year % 100)) || (!(year % 400));
}
bool is_leapYear4(int year) throw(MyExcept1) {
    if (year <= 0)
        throw MyExcept1();
    return (!(year % 4) && (year % 100)) || (!(year % 400));
}

bool is_leapYear5(int year) throw(MyExcept2) {
    if (year <= 0)
        throw MyExcept2("Неправильный год");
    return (!(year % 4) && (year % 100)) || (!(year % 400));
}

bool is_leapYear6(int year) throw(MyExcept3) {
    if (year <= 0)
        throw MyExcept3("Неправильный год", year);
    return (!(year % 4) && (year % 100)) || (!(year % 400));
}

void launcher(bool (*func)(int)) {
    int year;
    cout << "Введите год >> ";
    cin >> year;
    cout << "Високосный год? " << func(year) << " (0 - Нет, 1 - Да)" << endl;
}

int main() {
    cout << "Функция определяет, является ли год високосным годом. Введите год" << endl;

    try {
        launcher(is_leapYear1);
    }
    catch (...) {
        cout << "В функции is_leapYear1 произошло исключение" << endl;
    }

    try {
        launcher(is_leapYear2);
    }
    catch (...) {
        cout << "В функции is_leapYear2 произошло исключение" << endl;
    }

    try {
        launcher(is_leapYear3);
    }
    catch (invalid_argument& e) {
        cout << e.what() << endl;
    }

    try {
        launcher(is_leapYear4);
    }
    catch (MyExcept1) {
        cout << "В функции is_leapYear4 произошло исключение" << endl;
    }

    try {
        launcher(is_leapYear5);
    }
    catch (MyExcept2& e) {
        cout << e.message() << endl;
    }

    try {
        launcher(is_leapYear6);
    }
    catch (MyExcept3& e) {
        cout << e.what() << " " << e.arg() << endl;
    }
}