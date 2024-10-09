#include <windows.h>
#include <iostream>
#include <bitset>
#include <map>
#include <regex>
#include <string>

using namespace std;
/**
* C++ Telex Baudot Class
* UNDER CONSTRUCTION
*/
class Baudot
{

public:
    Baudot() { fill_BaudotMap(); }

private:
    multimap<string, string> baudot_map;
    multimap<string, string> baudot_map_reversed;

    void fill_BaudotMap()
    {
        // Baudot code (CCITT-1) mapping
        baudot_map.insert(pair <string, string>( "A", "11000"));
        baudot_map.insert(pair <string, string>( "B", "10011"));
        baudot_map.insert(pair <string, string>( "C", "01110"));
        baudot_map.insert(pair <string, string>( "D", "10010"));
        baudot_map.insert(pair <string, string>( "E", "10000"));
        baudot_map.insert(pair <string, string>( "F", "10110"));
        baudot_map.insert(pair <string, string>( "G", "01011"));
        baudot_map.insert(pair <string, string>( "H", "00101"));
        baudot_map.insert(pair <string, string>( "I", "01100"));
        baudot_map.insert(pair <string, string>( "J", "11010"));
        baudot_map.insert(pair <string, string>( "K", "11110"));
        baudot_map.insert(pair <string, string>( "L", "01001"));
        baudot_map.insert(pair <string, string>( "M", "00111"));
        baudot_map.insert(pair <string, string>( "N", "00110"));
        baudot_map.insert(pair <string, string>( "O", "00011"));
        baudot_map.insert(pair <string, string>( "P", "01101"));
        baudot_map.insert(pair <string, string>( "Q", "11101"));
        baudot_map.insert(pair <string, string>( "R", "01010"));
        baudot_map.insert(pair <string, string>( "S", "10100"));
        baudot_map.insert(pair <string, string>( "T", "00001"));
        baudot_map.insert(pair <string, string>( "U", "11100"));
        baudot_map.insert(pair <string, string>( "V", "01111"));
        baudot_map.insert(pair <string, string>( "W", "11001"));
        baudot_map.insert(pair <string, string>( "X", "10111"));
        baudot_map.insert(pair <string, string>( "Y", "10101"));
        baudot_map.insert(pair <string, string>( "Z", "10001"));
        baudot_map.insert(pair <string, string>( " ", "00100")); // Space

        // Numbers 0 to 9
        baudot_map.insert(pair <string, string>( "0", "11111"));
        baudot_map.insert(pair <string, string>( "1", "11011"));
        baudot_map.insert(pair <string, string>( "2", "10111"));
        baudot_map.insert(pair <string, string>( "3", "10011"));
        baudot_map.insert(pair <string, string>( "4", "01111"));
        baudot_map.insert(pair <string, string>( "5", "01011"));
        baudot_map.insert(pair <string, string>( "6", "00111"));
        baudot_map.insert(pair <string, string>( "7", "00011"));
        baudot_map.insert(pair <string, string>( "8", "01101"));
        baudot_map.insert(pair <string, string>( "9", "01001"));

        // Special characters
        baudot_map.insert(pair <string, string>( "-", "00011"));
        baudot_map.insert(pair <string, string>( "?", "11001"));
        baudot_map.insert(pair <string, string>( ":", "01110"));
        baudot_map.insert(pair <string, string>( "$", "01001"));
        baudot_map.insert(pair <string, string>( "!", "01101"));
        baudot_map.insert(pair <string, string>( "&", "11010"));
        baudot_map.insert(pair <string, string>( "#", "10100"));
        baudot_map.insert(pair <string, string>( "(", "11110"));
        baudot_map.insert(pair <string, string>( ")", "01001"));
        baudot_map.insert(pair <string, string>( ".", "11100"));
        baudot_map.insert(pair <string, string>( ",", "00110"));
        baudot_map.insert(pair <string, string>( "\"", "01010"));
        baudot_map.insert(pair <string, string>( ";", "01111"));
        baudot_map.insert(pair <string, string>( "/", "11101"));
        baudot_map.insert(pair <string, string>( "=", "01001"));

        // invert baudot_map
        for (const auto& it : baudot_map)
        {
            baudot_map_reversed.insert(make_pair(it.second, it.first));
        }
    }
};