#include <iostream>
#include <string>
using namespace std;
enum class Orientation { Horisontal, Vertical };
string Orientation_Name[]{ "Horisontal", "Vertical" };
class Cursor {
    size_t x, y;
    Orientation type;
    size_t size;
    bool sleep;
    friend ostream& operator<<(ostream& ofs, const Cursor& v) { // перегрузка вывода
        ofs << v.x << " " << v.y << " " << Orientation_Name[size_t(v.type)] << " " << v.size << '\n';
        return ofs;
    }

public:
    Cursor() : // конструктор по умолчанию
        x{ 0 }, y{ 0 }, type{ Orientation::Horisontal }, size{ 0 } {}

    Cursor(size_t x1, size_t y1, Orientation type1, size_t size1, bool sleep1) : // конструктор инициализации объекта
        x{ x1 }, y{ y1 }, type{ type1 }, size{ size1 }, sleep{ sleep1 } {}

    size_t getX() {
        return x;
    }

    size_t getY() {
        return y;
    }

    Orientation getType() {
        return type;
    }

    size_t getSize() {
        return size;
    }

    void setX(size_t x1) {
        if (!sleep) x = x1;
    }

    void setY(size_t y1) {
        if (!sleep) y = y1;
    }

    void setOrientation(Orientation type1) {
        if (!sleep) type = type1;
    }

    void setSize(size_t size1) {
        if (!sleep) size = size1;
    }

    void block() {
        sleep = 1;
    }

    void unblock() {
        sleep = 0;
    }

    Cursor(const Cursor& v) : //конструктор копирования
        x{ v.x }, y{ v.y }, type{ v.type }, size{ v.size }, sleep{ v.sleep } {}

    ~Cursor() {}

};
int main() {
    Cursor cursor1; // создание объекта по умолчанию
    Cursor cursor2(1, 1, Orientation::Vertical, 1, 0); // создание объекта с параметрами
    Cursor* cursor3 = new Cursor[3]; // создание массива объектов
    cout << cursor2.getX() << ' ' << cursor2.getY() << ' ' << Orientation_Name[size_t(cursor2.getType())] << ' ' << cursor2.getSize() << '\n';
    cursor2.setX(2);
    cursor2.setY(2);
    cursor2.setOrientation(Orientation::Horisontal);
    cursor2.setSize(2);
    cout << cursor2;
    cursor2.block();
    cursor2.setX(3);
    cursor2.setY(3);
    cursor2.setOrientation(Orientation::Vertical);
    cursor2.setSize(3);
    cout << cursor2;
    cursor2.unblock();
    cursor2.setX(3);
    cursor2.setY(3);
    cursor2.setOrientation(Orientation::Vertical);
    cursor2.setSize(3);
    cout << cursor2;
    Cursor cursor4 = cursor2; // конструктор копирования 
    cout << cursor4;
    cout << cursor3[0];
    delete[] cursor3;
}