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
        for (const auto& im : baudot_map)
        {
            baudot_map_reversed.insert(make_pair(im.second, im.first));
        }
    }
/*////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdint>

    // Wav file header structure
    struct WAVHeader {
        char riff[4] = { 'R', 'I', 'F', 'F' };
        uint32_t overall_size;
        char wave[4] = { 'W', 'A', 'V', 'E' };
        char fmt_chunk_marker[4] = { 'f', 'm', 't', ' ' };
        uint32_t length_of_fmt = 16;
        uint16_t format_type = 1;
        uint16_t channels = 1;
        uint32_t sample_rate = 8000;
        uint32_t byterate;
        uint16_t block_align;
        uint16_t bits_per_sample = 8;
        char data_chunk_header[4] = { 'd', 'a', 't', 'a' };
        uint32_t data_size;
    };

    // Generates a sine wave tone for a given frequency and duration
    // the sine function returns values between -1 and 1, (sample + 1.0) shifts the range to 0 to 2. 
    // Multiplying by 127.5 scales this range to 0 to 255, which fits the range of an 8-bit unsigned integer (uint8_t).
    void generateTone(std::ofstream& file, double frequency, double duration, uint32_t sample_rate) {
        uint32_t num_samples = sample_rate * duration;
        for (uint32_t i = 0; i < num_samples; ++i) {
            double sample = sin(2.0 * M_PI * frequency * i / sample_rate);
            uint8_t sample_value = static_cast<uint8_t>((sample + 1.0) * 127.5);
            file.write(reinterpret_cast<const char*>(&sample_value), sizeof(sample_value));
        }
    }

    int main() {
        std::ofstream file("baudot.wav", std::ios::binary);

        WAVHeader header;
        header.sample_rate = 8000;
        header.byterate = header.sample_rate * header.channels * header.bits_per_sample / 8;
        header.block_align = header.channels * header.bits_per_sample / 8;

        // Estimate data size (for simplicity)
        header.data_size = 8000 * 5; // 5 seconds of audio
        header.overall_size = header.data_size + 36;

        file.write(reinterpret_cast<const char*>(&header), sizeof(header));

        double duration = 0.1; // Each tone duration (in seconds)
        Baudot tones are typically around 1100 Hz for marking (1) and 1500 Hz for spacing (0)

        double frequencies[] = { 1500, 1100 }; // Example frequencies for '0' and '1'

        // Example Baudot sequence (binary)
        int sequence[] = { 0, 1, 0, 1, 1, 0, 1, 0, 1 };

        for (int bit : sequence) {
            generateTone(file, frequencies[bit], duration, header.sample_rate);
        }

        file.close();
        std::cout << "Generated baudot.wav file" << std::endl;

        return 0;
    }
    This code sets up a basic WAV file and generates tones for '0' and '1' at 1000 Hz and 1400 Hz, respectively, 
    with each tone lasting 0.1 seconds. The sequence array represents a simple Baudot-like sequence. 
    You can modify the frequencies and duration as needed. 
    Have fun experimenting with it!
    */
};