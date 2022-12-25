#include <iostream>
using namespace std;
const int arr_size = 15;
class Array
{
    unsigned char arr[arr_size];
    int size = 0;

protected:
    void Sum(Array arr2)
    {
        if (size >= arr2.size)
        {
            for (int i = 0; i < arr2.size; i++)
            {
                arr[i] += arr2.arr[i];
            }
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                arr[i] += arr2.arr[i];
            }
        }
    }
public:
    int get_size()
    {
        return size;
    }

    Array(int size, unsigned char data = '0')
    {
        if (size <= arr_size)
        {
            this->size = size;
        }

        arr[0] = data;
    }
    unsigned char& operator[] (int index)
    {
        if (index < size && index >= 0)
            return arr[index];
    }

    virtual void ArraySum(Array arr2)
    {
        Sum(arr2);
        cout << "\nClass Array";

    }
};
class Array2 :public Array
{
public:
    Array2(int size, unsigned char data = '0') :Array(size, data) {};
    void ArraySum(Array arr2) override
    {
        Sum(arr2);
        cout << endl << "Class Array2 ";
    }
};
class Array3 :public Array2
{
public:
    Array3(int size, unsigned char data = '0') :Array2(size, data) {};
    void ArraySum(Array arr2) override
    {
        Sum(arr2);
        cout << endl <<  "Class Array3 ";
    }
};
class Money
{
    long int rubles;
    int penny;
    int pennyToRubles(int penny)
    {
        if (abs(penny) < 100)
            return penny;
        if (abs(penny) >= 100)
        {
            int penny_out = penny % 100;
            rubles += penny / 100;
            return penny_out;
        }
    }
public:
    Money(long int rubles, int penny)
    {
        this->rubles = rubles;
        this->penny = penny;
        this->penny = pennyToRubles(penny);
    }
    int getPenny()
    {
        return penny;
    }
    long int getRubles()
    {
        return rubles;

    }
    void Print()
    {
        cout << "P: " << rubles << "K: " << penny;
    }
    void PrintShort()
    {
        cout << rubles << "." << penny;
    }
    Money& operator += (Money c2)
    {
        rubles += c2.rubles;
        penny += c2.penny;
        penny = pennyToRubles(penny);
        return *this;
    }
    Money& operator -= (Money c2)
    {
        rubles -= c2.rubles;
        penny -= c2.penny;
        penny = pennyToRubles(penny);
        return *this;
    }
    Money& operator *= (int c2)
    {
        rubles *= c2;
        penny *= c2;
        penny = pennyToRubles(penny);
        return *this;
    }
    friend Money operator+(Money c1, Money c2);
    friend Money operator-(Money c1, Money c2);
};
Money operator + (Money c1, Money c2)
{
    Money out_money(c1.rubles, c1.penny);
    out_money.rubles += c2.rubles;
    out_money.penny += c2.penny;
    out_money.penny = out_money.pennyToRubles(out_money.penny);
    return out_money;
}
Money operator -(Money c1, Money c2)
{
    Money out_money(c1.rubles, c1.penny);
    out_money.rubles -= c2.rubles;
    out_money.penny -= c2.penny;
    out_money.penny = out_money.pennyToRubles(out_money.penny);
    return out_money;
}
class Hex
{
private:
    char intToLetter(int n)
    {
        switch (n)
        {
        case 0:return '0';
        case 1:return '1';
        case 2:return '2';
        case 3:return '3';
        case 4:return '4';
        case 5:return '5';
        case 6:return '6';
        case 7:return '7';
        case 8:return '8';
        case 9:return '9';
        case 10:return 'A';
        case 11:return 'B';
        case 12:return 'C';
        case 13:return 'D';
        case 14:return 'E';
        case 15:return 'F';
        default:
            break;
        }
    }
    int HexToInt(char hex[])
    {
        int len = strlen(hex);
        int i = 0;
        int ch = 0;
        int n = 0;
        int res = 0;
        for (i = 0; i < len; ++i)
        {
            ch = tolower(hex[i]);
            if (ch >= 'a' && ch <= 'f')
            {
                n = ch - 'a' + 10;
            }
            else
            {
                n = ch - '0';
            }
            res += n * pow(16, len - i - 1);
        }
        return res;
    }
    unsigned char* IntToHex(int num)
    {
        unsigned char a[100];
        int celoe = num / 16;
        int ost = num % 16;
        int j = 0;
        while (celoe > 15)
        {
            a[j] = intToLetter(ost);
            ost = celoe % 16;
            celoe = celoe / 16;
            j++;
        }
        a[j] = intToLetter(ost);
        j++;
        a[j] = intToLetter(celoe);
        unsigned char a_out[100];
        int z = 0;
        for (int i = j; i >= 0; i--)
        {
            a_out[z] = a[i];
            z++;
        }
        a_out[z] = '\0';
        return a_out;
    }
    unsigned char arr[100];
    int num;
public:
    Hex(char hex[])
    {
        num = HexToInt(hex);

        unsigned char* ar = IntToHex(num);
        int i = 0;
        while (ar[i] != '\0')
        {
            arr[i] = ar[i];
            i++;
        }
        arr[i] = '\0';
    }
    Hex(int number)
    {
        num = number;
        unsigned char* ar = IntToHex(num);
        int i = 0;
        while (ar[i] != '\0')
        {
            arr[i] = ar[i];
            i++;
        }
        arr[i] = '\0';
    }
    int getInt()
    {
        return num;
    }
    unsigned char* getHex()
    {
        return arr;
    }
    void  PrintInt()
    {
        cout << num;
    }
    void PrintHex()
    {
        int i = 0;
        while (arr[i] != '\0')
        {
            cout << arr[i];
            i++;
        }
    }


    friend Hex operator+(Hex c1, Hex c2);
    friend Hex operator-(Hex c1, Hex c2);
};
Hex operator+(Hex c1, Hex c2)
{

    return Hex(c1.num + c2.num);
}
Hex operator-(Hex c1, Hex c2)
{
    return Hex(c1.num - c2.num);
}
int main()
{
    Array ar1(5, '1');
    ar1[0] = '2';
    Array2 ar2(5, '1');
    ar2.ArraySum(ar1);
    cout << endl << ar2[0];
    Array3 ar3(5, '6');
    ar3.ArraySum(ar2);
    ar3.Array::ArraySum(ar2);
    cout << endl << ar3[0];
    cout << endl << "--------------------------------------------";
    Money m1(1, 102);
    cout << endl;
    m1.PrintShort();
    Money m2(5, 5);
    m1 = m1 + m2;
    cout << endl;
    m1.PrintShort();
    cout << endl;
    m1 = m1 - m2;
    m1.PrintShort();
    m1 *= 5;
    cout << endl;
    m1.PrintShort();
    m1 = m1 - Money(11, 110);
    cout << endl;
    m1.PrintShort();
    char dig[4] = { 'A','F','F' };
    cout << endl << "--------------------------------------------";
    Hex h(dig);
    cout << endl;
    h.PrintHex();
    Hex h1(10);
    Hex h2(16);
    h1 = h1 + h2;
    cout << endl;
    h1.PrintHex();
}
