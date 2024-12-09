// COMSC-210 | lab 36 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
using namespace std;

int sum_ascii(string);

int main()
{
    char a = 'A';
    cout << a << endl;
    cout << (int)a << endl; // prints ASCII values
    int b = 66;
    cout << b << endl;
    cout << (char)b << endl;

    // test run, should output 65
    cout << sum_ascii("A");

    //(65+65) = 130
    cout << '\n' << sum_ascii("AA");

    return 0;
}

int sum_ascii(string val)
{
    int sum = 0;
    for (int i = 0; i < val.size(); i++) // handle as arr of chars
        sum += ((int)val[i]);

    return (sum);
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
