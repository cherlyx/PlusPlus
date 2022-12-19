#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
class Pair {
private:
    int a, b;
public:
    int GetA() {
        return a;
    }
    int GetB() {
        return b;
    }
    explicit Pair(int c, int d) {
        a = c;
        b = d;
    }
    void Print(){
        cout << "rub =  " << a << " kopeyki = " << b << endl;
    }
    void multiply(int x) {
        a = a * x;
        b = b * x;
        while (b > 99) {
            b = b - 100;
            a += 1;
        }
    }
    Pair plus(Pair cd) {
        Pair result = *new Pair(a+b, cd.GetA() + cd.GetB());
        return result;
    }
};
class Money : public Pair {
public:
    explicit Money(int c, int d):Pair(c, d) {
        if (d > 99 || d < 0) {
            cout << "Введены неправильные значения, копеек не должно быть больше 100";
            exit(0);
        }   
    }
    Money plus(Money cd) {
        double kopeyki1 = ((GetA() * 100.0) + (cd.GetA() * 100.0)) + GetB() + cd.GetB();
        int rubles = kopeyki1/100.0;
        int kopeyki = round(((kopeyki1 / 100.0)-rubles)*100.0);
        Money result = *new Money(rubles,kopeyki);
        return result;
    }
    Money Minus(Money cd) {
       double moneyminus = ((GetA() * 100.0) - (cd.GetA() * 100.0)) + GetB() - cd.GetB();
       int rubminus = moneyminus / 10000;
       int kopeykiminus = round(((moneyminus / 100.0) - rubminus) * 100.0);
       Money result = *new Money(rubminus, kopeykiminus);
       return result;
    }
    Money Del(Money cd) {
        int adel = GetA();
        int bdel = GetB();
        int asec = cd.GetA();
        int bsec = cd.GetB();
        int delcef = adel % asec;
        int rubdel = (adel / asec)+(delcef/100);
        int kopeykidel = bdel/bsec;
        Money result = *new Money(rubdel, kopeykidel);
        return result;
    }
    
};
int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите пару чисел a,b ";
    int a, b;
    cin >> a >> b;
    Money para = *new Money(a,b);
    para.Print();
    cout << "Введите на какое число хотите умножить пару чисел (a,b) ";
    int x;
    cin >> x;
    para.multiply(x);
    para.Print();
    cout << "Введите значения пары (c,d)";
    int c, d;
    cin >> c >> d;
    cout << "Результат сложения: " << endl;
    Money paracd = *new Money(c,d);
    Money resultplus = para.plus(paracd);
    resultplus.Print();
    cout << "Результат вычитания: " << endl;
    Money resultminus = para.Minus(paracd);
    resultminus.Print();
    cout << "Результат деления: " << endl;
    Money resultdel = para.Del(paracd);
    resultdel.Print();
}
