// COMSC-210 | lab 37/38 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;
using std::map; // needed?

// function prototypes
int gen_hash_index(string);
void readInVals(string, map<int, list<string>> &);
void output100(map<int, list<string>>);
int printMenu();
void searchKey(map<int, list<string>>);
void addKey(map<int, list<string>> &);
void removeKey(map<int, list<string>> &);
void modifyKey(map<int, list<string>> &);

// helper function for modification
char operationSelect();

int main()
{
    map<int, list<string>> hash_table; // intiialze hash table implemented via map
                                       // pairing: int (hash code) , list of string vals

    readInVals("lab-37-data.txt", hash_table); // read in all values to hash table

    int choice = 0;
    while (choice != 6) // 6 to exit loop
    {
        choice = printMenu();
        switch (choice)
        {
        case (1):
            output100(hash_table);
            break;

        case (2):
            searchKey(hash_table);
            break;

        case (3):
            addKey(hash_table);
            break;

        case (4):
            removeKey(hash_table);
            break;

        case (5):
            modifyKey(hash_table);
            break;

        default: // shouldn't be possible due to range handling in printMenu()
            break;
        }
    }

    return 0;
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

int printMenu()
{
    int choice;
    cout << "\nHASH TABLE MENU--------\n1) Print first 100 values\n2) Search for key\n3) Add a key\n4) Remove a key\n5) Modify a Key\n6) Exit";
    cout << "\nYour choice --> ";
    cin >> choice;
    cout << '\n';
    return (choice);
}

int gen_hash_index(string val)
{
    int index = 0;
    for (int i = 0; i < val.size(); i++) // handle as arr of chars
        index += ((int)val[i]);

    return (index % 110000); // generate hash index from ascii, needs to be high number due to size of txt
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

void output100(map<int, list<string>> hash) // prints first 100 values, regardless of key, starts at 600ish because my hash is strange
{
    int count = 0;
    for (auto it = hash.begin(); it != hash.end() && count < 100; it++) // iterate through map
    {
        cout << "Key: " << it->first << ", Values: ";
        for (const auto &val : it->second) // iterate through DLL of map
        {
            cout << val << " ";
            count++; // increment value tracker
        }
        cout << '\n';
    }
}

void searchKey(map<int, list<string>> hash) // search map for specific key, prints values if found
{
    int val;

    cout << "Input key to find: ";
    cin >> val;

    auto search = hash.find(val);

    if (search != hash.end())
    {
        cout << "Found, has values: ";
        for (const auto &val : search->second) // iterate through DLL of map
        {
            cout << val << " ";
        }
        cout << '\n';
    }
    else
    {
        cout << "Could not find a node with that key.\n";
    }
}

void addKey(map<int, list<string>> &hash) // add a new key to push/pull values to/from
{
    int val;

    cout << "Input key to add: ";
    cin >> val;

    auto search = hash.find(val);

    if (search != hash.end())
    {
        cout << "ERROR: Key already exists\n";
    }
    else
    {
        hash[val]; // create key
        cout << "Successfully created key with index: " << val << '\n';
    }
}

void removeKey(map<int, list<string>> &hash) // remove key (and with it, related values)
{
    int val;

    cout << "Input key to remove: ";
    cin >> val;

    auto search = hash.find(val);

    if (search != hash.end())
    {
        hash.erase(val); // erase node at specified index
        cout << "Success.\n";
    }
    else
    {
        cout << "ERROR: Key doesn't exist!\n";
    }
}

void modifyKey(map<int, list<string>> &hash) // I assume to mean modify values corresponding to specific key
{
    int val;

    cout << "Input key to modify: ";
    cin >> val;

    auto search = hash.find(val);

    if (search != hash.end())
    {
        cout << "Found, has values: ";
        for (const auto &val : search->second) // iterate through DLL of map
        {
            cout << val << " ";
        }
        cout << '\n';

        // logic for changing values
        if (operationSelect() == 'A')
        {
            string buf;
            cin.ignore(); // clear cache

            cout << "Enter string value to append to key: ";
            getline(cin, buf);

            hash[val].push_back(buf);
            cout << "Success.\n";
        }
        else
        {
            int buf;
            cout << "Enter index of string value to remove: ";
            cin >> buf;

            int current = 0;
            for (auto it = hash[val].begin(); it != hash[val].end(); it++, current++) // iterate through hash map to find index
            {
                if (current == buf) // if arrived at index
                {
                    hash[val].erase(it);
                }
            }
        }
    }
    else
    {
        cout << "ERROR: Key doesn't exist!\n";
    }
}

char operationSelect() // for mode selection on modification
{
    char choice = 'N';
    while (choice != 'A' && choice != 'B') // input validation loop
    {
        cout << "A) Add value to key\nB) Remove value from key\nYour choice --> ";
        cin >> choice;
        if (choice != 'A' && choice != 'B')
        {
            cout << "ERROR: Valid inputs are 'A' or 'B', try again\n";
        }
    }
    return (choice);
}
