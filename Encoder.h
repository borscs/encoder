#pragma once
#include <iostream>
#include <string>
#include <list>

//Custom includes
#include "Json.hpp"

using namespace std;
using nlohmann::json;

class Encoder
{
public:


    void Encoder_T(const string textToEncode, int mode);
    void Encoder_F(const string file_in, const string file_out, int mode);
    Encoder(json dict);
    ~Encoder();
    string encode(string in);
    void changejsonorder();
    string decode(string in);

};
