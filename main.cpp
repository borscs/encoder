// StringEncoder.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <fstream>
#include <list>

//Custom includes
#include "Encoder.h"
#include "Utils.h"

using namespace std;


int main()
{
    Utils *h = new Utils();
    //Reading the JSON file location
    string path;
    cout << "JSON file location: "; // string duplication why no a variable?
    cin >> path;
    //Runs only when the JSON reading was successful
    while (!h->read_JSON_Dictionary(path)) {
        cout << "ERROR: Invalid coding table!" << endl;
        cout << "JSON file location: ";  // string duplication
        cin >> path;
    }
    if (!h->read_JSON_Dictionary(path)) {
       cout << "ERROR: Can't read the JSON dictionary! Restart the program and try again!" << endl;
    }
    //It throws an error if the reading was unsuccessful
    else {
        Encoder *encoder = new Encoder(h->j);
        string input;
        h->print_Menu();

        string somestring;
        getline(cin, somestring);
        getline(cin, input);
        list<string> input_Parts = h->split_String(input, ' ');
        string cmd = h->get_Item_At_Index_From_List(input_Parts, 0);
        string text_Input;
        string file_in;
        string file_out;

        //Converts all letters to uppercase
        cmd = h->lower_To_Upper(cmd);
        int cmd_Int = h->string_Input_To_Numbers(cmd);

        if (cmd == "ENCODE" || cmd == "DECODE") {
            text_Input = h->get_Item_At_Index_From_List(input_Parts, 1);
        }
        else if (cmd == "ENCODEFILE" && cmd == "DECODEFILE") {
            file_in = h->get_Item_At_Index_From_List(input_Parts, 1);
            file_out = h->get_Item_At_Index_From_List(input_Parts, 2);
        }
        while (cmd_Int > 0) {
            switch (cmd_Int) {
            case 1:
                //ENCODE
            {
                encoder->Encoder_T( text_Input, 1);
            }
                break;
            case 2:
                //DECODE
            {
                encoder->Encoder_T(text_Input, 2);
            }
                break;
            case 3:
                //ENCODE_FILE
            {
                encoder->Encoder_F(file_in, file_out, 3);
            }
                break;
            case 4:
                //DECODE_FILE
            {
                encoder->Encoder_F(file_in, file_out, 4);
            }
                break;
            }
            h->print_Menu();
            cout << "> ";
            getline(cin, input);
            input_Parts = h->split_String(input, ' ');
            cmd = h->get_Item_At_Index_From_List(input_Parts, 0);


            if (cmd == "ENCODE" || cmd == "DECODE") {
                text_Input = h->get_Item_At_Index_From_List(input_Parts, 1);
            }
            else if (cmd == "ENCODEFILE" || cmd == "DECODEFILE") {
                text_Input = "";
                file_in = h->get_Item_At_Index_From_List(input_Parts, 1);
                file_out = h->get_Item_At_Index_From_List(input_Parts, 2);
            }
            cmd = h->lower_To_Upper(cmd);
            cmd_Int = h->string_Input_To_Numbers(cmd);
        }

    }
    return 0;
}
