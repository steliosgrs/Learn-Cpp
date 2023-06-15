#include <iostream>
#include <cstring>
#include <vector>
#include <string>
class myEntry{
    myEntry();
    ~myEntry();

private:
    std::vector< std::pair <std::string,std::string> > Finding;
};

class myDict{
    std::vector<myEntry> dict;

public:
    myDict();

    ~myDict();

    void PrintString();
    char *GetString();
    int Size();

};

myDict ::~myDict() { delete[] string; }

myDict ::myDict()
{
    size = 1;
    string = new char[size];
    strcpy(string, " ");
}
