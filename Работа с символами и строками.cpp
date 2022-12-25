#include <iostream> 

#include <stdio.h> 

#include <string> 

using namespace std;

int main()

{

    setlocale(LC_ALL, "ru");

    cout << "Введите число которое хотите перевернуть " << endl;

    int n;

    string s;

    cin >> n;

    s = to_string(n);

    for (int i = s.size(); i >= 0; i--) {

        cout << s[i] << " ";

    }

}