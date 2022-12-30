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
    int x,y,size;
    Orientation type;
    cout << "Введите координату x: ";
    cin >> x;
    Cursor cursor;
    cursor.getX();
    cursor.setX(x);
    cout << "Введите координату y: ";
    cin >> y;
    cursor.getY();
    cursor.setY(y);
    cout << "Введите вид курсора ( 0 - горизонтальный, 1 вертикальный):";
    int orientationInput;
    cin >> orientationInput;
    cursor.getType();
    type = (orientationInput == 0) ? Orientation::Horisontal : Orientation::Vertical;
    cout << "Введите размер курсора: ";
    cin >> size;
    cursor.getSize();
    cursor.setSize(size);
    cout << x << " " << y << " " << Orientation_Name[size_t(type)] << " " << size << endl;
}
