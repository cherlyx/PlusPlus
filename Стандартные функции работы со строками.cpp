#include <iostream> 

#include <stdio.h> 

#include <string> 

using namespace std;

int main()

{

    setlocale(LC_ALL, "ru");

    string s;

    cout << "Введите русское предложение" << endl;

    cin >> s;

    int mins = INT_MAX, maxs = INT_MAX;

    s += " ";

    for (int i = 0; i < s.size(); ++i) {

        if (s[i] != ' ') {

            maxs = 1;

            while (s[++i] != ' ')

                maxs++;

        }

        mins = min(mins, maxs);

    }

    cout << mins << endl;

}