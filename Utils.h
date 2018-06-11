#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <fstream>
#include "Json.hpp"
using namespace std;
using nlohmann::json;

class Utils
{
public:
    json j; // avoid global variables
    Utils();
    list<string> split_String(const string & input, char delimiter);
    string get_Item_At_Index_From_List(list<string> input, int index);
    int get_ListSize(list<string> input);
    string lower_To_Upper(const string in);
    void print_Menu();
    int string_Input_To_Numbers(string in);
    bool read_JSON_Dictionary(string path);
    ~Utils();
};

