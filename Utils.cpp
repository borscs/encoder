
#include "Utils.h"


Utils::Utils() {
    stringstream ss();
}

list<string> Utils::split_String(const string &input, char delimiter) {
    string innerinput = "";
    innerinput = input;
    stringstream ss(innerinput);
    string item;
    list<string> tokens;
    while (getline(ss, item, delimiter)) {
        tokens.push_back(item);
    }
    return tokens;
}

string Utils::get_Item_At_Index_From_List(list<string> input, int index) {
    list<string>::iterator it = input.begin();
    advance(it, index);
    return *it;
}

int Utils::get_ListSize(list<string> input) {
    return input.size();
}
//A simple function to convert lower to uppercase letters. This way it works always given the user enters the right word.
string Utils::lower_To_Upper(const string in) { // use std::toupper
    string tempOut;
    for (unsigned int i = 0; i < in.size(); i++) {
        if (in[i] == 'a') tempOut += "A";
        else if (in[i] == 'b') tempOut += "B";
        else if (in[i] == 'c') tempOut += "C";
        else if (in[i] == 'd') tempOut += "D";
        else if (in[i] == 'e') tempOut += "E";
        else if (in[i] == 'f') tempOut += "F";
        else if (in[i] == 'g') tempOut += "G";
        else if (in[i] == 'h') tempOut += "H";
        else if (in[i] == 'i') tempOut += "I";
        else if (in[i] == 'j') tempOut += "J";
        else if (in[i] == 'k') tempOut += "K";
        else if (in[i] == 'l') tempOut += "L";
        else if (in[i] == 'm') tempOut += "M";
        else if (in[i] == 'n') tempOut += "N";
        else if (in[i] == 'o') tempOut += "O";
        else if (in[i] == 'p') tempOut += "P";
        else if (in[i] == 'q') tempOut += "Q";
        else if (in[i] == 'r') tempOut += "R";
        else if (in[i] == 's') tempOut += "S";
        else if (in[i] == 't') tempOut += "T";
        else if (in[i] == 'u') tempOut += "U";
        else if (in[i] == 'v') tempOut += "V";
        else if (in[i] == 'w') tempOut += "W";
        else if (in[i] == 'x') tempOut += "X";
        else if (in[i] == 'y') tempOut += "Y";
        else if (in[i] == 'z') tempOut += "Z";
        else tempOut += in[i];

    }
    return tempOut;
}

//Prints a simple menu for the user with the available options.
void Utils::print_Menu() {
    cout << "Welcome! What would you like to make?" << endl;
    cout << "ENCODE <text>: Encodes a given string based on a JSON Dictionary" << endl;
    cout << "DECODE <text>: Decodes an encoded string using a JSON Dictionary" << endl;
    cout << "ENCODEFILE <file-to-encode> <output-file>: Reads a text file and then encodes it into a second file" << endl;
    cout << "DECODEFILE <encoded-file> <output-file>: Reads an encded text file then decodes it int a second file" << endl;
    cout << "EXIT: Terminates the program" << endl;
    cout << "> ";
}

int Utils::string_Input_To_Numbers(string in)
{
    if (in == "ENCODE") {
        return 1;
    }
    else if (in == "DECODE") {
        return 2;
    }
    else if (in == "ENCODE_FILE") {
        return 3;
    }
    else if (in == "DECODE_FILE") {
        return 4;
    }
    else if (in == "EXIT") {
        return 0;
    }
    else return 0;
}

bool Utils::read_JSON_Dictionary(string path)
{
    ifstream file(path);
    if (file.is_open()) {
        file >> j;
        return true;
    }
    else return false; // no need for the else
}



Utils::~Utils()
{

}
