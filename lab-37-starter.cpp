// COMSC-210 | lab 37 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;
using std::map;

int gen_hash_index(string);
void readInVals(string, map<int, list<string>> &);
void output100(map<int, list<string>>);

int main()
{
    map<int, list<string>> hash_table; // intiialze hash table implemented via map
                                       // pairing: int (hash code) , list of string vals

    readInVals("lab-37-data.txt", hash_table); //read in all values to hash table
    output100(hash_table);

    //output first 100
    

    return 0;
}

int gen_hash_index(string val)
{
    int index = 0;
    for (int i = 0; i < val.size(); i++) // handle as arr of chars
        index += ((int)val[i]);

    return (index % 97); // generate hash index from ascii
}

void readInVals(string file, map<int, list<string>> &hash)
{
    ifstream in(file);

    if (!in.good()) // confirm file works
    {
        cout << "ERROR OPENING FILE";
        return;
    }

    string buf;

    while (getline(in, buf)) // read each into buf, call function
    {
        hash[gen_hash_index(buf)].push_back(buf); // push each buf string to list index hash_value
    }
}

void output100(map<int, list<string>> hash)
{
    int count = 0;
    for(auto it = hash.begin(); it!=hash.end() && count < 100; it++, count++)
    {
        cout << "Key: " << it->first << " Values: ";
        // for(const auto&val : it->second)
        // {
        //     cout << val << " ";
        // }
        // cout << '\n';
    }
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
