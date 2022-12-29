#include <iostream> 

#include <string> 

using namespace std;

enum class Orientation { Horisontal, Vertical };

string Orientation_Name[]{ "Горизонтальный", "Вертикальный" };

class Cursor {


    size_t x, y;

    Orientation type;

    size_t size;

    bool sleep;

    friend ostream& operator<<(ostream& ofs, const Cursor& v) {

        ofs << v.x << " " << v.y << " " << Orientation_Name[size_t(v.type)] << " " << v.size << '\n';

        return ofs;

    }
public:
    void read() {
        cout << "Введите координату x: ";
        cin >> x;
        cout << "Введите координату y: ";
        cin >> y;
        cout << "Введите тип курсора (0 горизонтальный, 1 вертикальный): ";
        int orientationInput;
        cin >> orientationInput;
        type = (orientationInput == 0) ? Orientation::Horisontal : Orientation::Vertical;
        cout << "Введите размер курсора: ";
        cin >> size;
        cout << "Введите статус сна курсора (0 не погашен, 1 погашен): ";
        cin >> sleep;
    }
    void print() const {
        cout << x << " " << y << " " << Orientation_Name[size_t(type)] << " " << size << endl;
    }

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
    Cursor() : x{ 0 }, y{ 0 }, type{ Orientation::Horisontal }, size{ 0 }, sleep{ 0 } {}
    ~Cursor() {}
};

int main() {
    setlocale(LC_ALL, "RU");
    Cursor cursor;
    cursor.read();
    cursor.print();
}
