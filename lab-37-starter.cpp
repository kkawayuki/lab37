// COMSC-210 | lab 36 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;
using std::map;

int sum_ascii(string);
int readInVals(string, map<int, list<string>>&);

int main()
{
    map<int, list<string>> hash_table; // intiialze hash table implemented via map
                                       // pairing: int (hash code) , list of string vals

    cout << readInVals("lab-37-data.txt",hash_table);

    return 0;
}

int sum_ascii(string val)
{
    int sum = 0;
    for (int i = 0; i < val.size(); i++) // handle as arr of chars
        sum += ((int)val[i]);

    return (sum);
}

int readInVals(string file, map<int, list<string>>&hash)
{
    ifstream in(file);

    if (!in.good()) // confirm file works
    {
        cout << "ERROR OPENING FILE";
        return (0);
    }

    string buf;
    int fileTotal = 0;

    while (getline(in, buf)) // read each into buf, call function
        fileTotal += sum_ascii(buf);

    return (fileTotal);
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
