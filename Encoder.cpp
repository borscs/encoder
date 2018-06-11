
#include "Encoder.h"
#include "Utils.h"

json js;

list<pair<string, string>> js_revers;
int opcion_Mode;
Utils *h = new Utils();


void Encoder::Encoder_T(const string textToEncode, int mode)
{

    opcion_Mode = mode;
    cout << "> ";
    string outputString;
    switch (opcion_Mode) {
    case 1:
    {
        outputString = encode(textToEncode);
        break;
    }
    case 2:
    {
        outputString = decode(textToEncode);
        break;
    }
    }
    cout << outputString << endl;
}

void Encoder::Encoder_F(const string file_in, const string file_out, int mode) {

    opcion_Mode = mode;
    switch (opcion_Mode) {
    case 3:
    {
        ifstream f_in(file_in); // no need for code duplication
        ofstream f_out(file_out);
        if (f_in.good()) {
            string str;
            while (getline(f_in, str))
            {
                f_out << encode(str) << endl;
            }
            f_out.close();
        }
        else {
            cout << "Invalid input file" << endl;
        }
        break;
    }

    case 4:
    {
        ifstream f_in(file_in);
        ofstream f_out(file_out);
        if (f_in.good()) {
            string str;
            while (getline(f_in, str))
            {
                //cout << str << endl;
                f_out << decode(str) << endl;
            }
            f_out.close();

        }
        else {
            cout << "INVALID INPUT FILE!" << endl;
        }
        break;
    }
    }
}

Encoder::Encoder(json dict)
{
    js = dict;
    changejsonorder();

}

Encoder::~Encoder()
{
}

string Encoder::encode(string in)
{
    string out;
    int badChars = 0;
    for (unsigned i = 0; i < in.size(); i++) {
        string actChar(1, in[i]);
        if (js.find(actChar) == js.end()) {
            badChars++;
        }
    }
    if (badChars < 1) {
        for (int i = 0; i < in.size(); i++) {
            string actChar(1, in[i]);
            if (js.find(actChar) != js.end()) {
                string encodedChar = js[actChar];
                out += encodedChar;
            }
        }
    }
    else {
        cout << "ERROR: Undefined characters in the given string!" << endl;
    }
    return out;
}
void Encoder::changejsonorder() {
    list<pair<string, string>> lista;
    for (auto it = js.begin(); it != js.end(); it++)
    {
        string k = it.key();
        string v = it.value();
        pair<string, string> a = make_pair(v, k);
        js_revers.push_back(a);
    }
}
string Encoder::decode(string in) {

    string out="";
    string bemenet = "";
    for (int i = 0; i < in.size(); i++)
    {

        bemenet += in[i];
        for (auto it = js_revers.begin(); it != js_revers.end(); it++)
        {
            pair < string, string> o = *it;
            if (bemenet == o.first)
            {
                out += o.second;
                bemenet = "";

            }
        }
    }

    return out;
}
