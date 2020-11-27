#include "dna_coder.hpp"
//#include "schifra_galois_field.hpp"
//#include "schifra_galois_field_polynomial.hpp"
//#include "schifra_sequential_root_generator_polynomial_creator.hpp"
#include "schifra_reed_solomon_encoder.hpp"
#include "schifra_reed_solomon_decoder.hpp"
#include "schifra_reed_solomon_block.hpp"
#include "schifra_error_processes.hpp"
#include <bits/stdc++.h>
#include <string.h>
#define RS_ROWS 14
using namespace std;

/* Finite Field Parameters */
const std::size_t field_descriptor = 8; //16;
const std::size_t generator_polynomial_index = 0;
const std::size_t generator_polynomial_root_count = 9830;

const char DNA[4] = {'A', 'C', 'G', 'T'};

DNACoder::DNACoder()
{
}

std::string DNACoder::ordToDNA(uint16_t ord) //16 bits
{
    std::string s = "";
    for (int i = 0; i < 8; i++)
    {
        s += DNA[ord % 4];
        ord = ord >> 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

std::string DNACoder::byteToDNA(char c) //8 bits
{
    std::string s = "";
    for (int i = 0; i < 4; i++)
    {
        s += DNA[c % 4];
        c = c >> 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

std::string DNACoder::symbolToDNA(unsigned char c1, unsigned char c2)
{
    std::string s = "";
    for (int i = 0; i < 4; i++)
    {
        s += DNA[c2 % 4];
        c2 = c2 / 4;
    }
    for (int i = 0; i < 4; i++)
    {
        s += DNA[c1 % 4];
        c1 = c1 / 4;
    }
    reverse(s.begin(), s.end());
    return s;
}

/* extracts $bitNumber-th bit from an input character string and
 * returns a 16-bit symbol with that bit in position $positioInSymbol (rest is 0)
 * */
uint16_t DNACoder::getBitByImportance(int positionInSymbol, int bitNumber, char *inputstring)
{
    int charNum = bitNumber / 8;
    int rem = bitNumber % 8;
    uint16_t temp = static_cast<uint16_t>(inputstring[charNum]);
    uint16_t mask = static_cast<uint16_t>(1) << (7 - rem);
    /*
    switch(rem){
        case 0:
            mask = 0x0080;
            break;
        case 1:
            mask = 0x0040;
            break;
        case 2:
            mask = 0x0020;
            break;
        case 3:
            mask = 0x0010;
            break;
        case 4:
            mask = 0x0008;
            break;
        case 5:
            mask = 0x0004;
            break;
        case 6:
            mask = 0x0002;
            break;
        case 7:
            mask = 0x0001;
            break;
    }*/

    temp = ((temp & mask) << (8 + rem)) >> positionInSymbol;
    return temp;
}

void DNACoder::fillRSMatrixByColumn(char *inputBytes, int inputSize, uint16_t RS_Matrix[][code_length])
{
    for (int i = 0; i < inputSize / 2; i++)
    {
        int row = i % RS_ROWS;
        int column = i / RS_ROWS;
        RS_Matrix[row][column] = (static_cast<unsigned char>(inputBytes[2 * i]) << 8) + static_cast<unsigned char>(inputBytes[2 * i + 1]);
    }

    if (inputSize % 2 != 0)
    {
        int ind = inputSize / 2;
        int row = ind % RS_ROWS;
        int column = ind / RS_ROWS;
        RS_Matrix[row][column] = static_cast<unsigned char>(inputBytes[2 * ind]) << 8;
    }
    std::cout << "End RSMatrixByColumn" << std::endl;
}

void DNACoder::fillRSMatrixByPriority(char *inputBytes, int inputSize, string priority_file, uint16_t RS_Matrix[][code_length])
{

    std::ifstream in_stream(priority_file);
    if (!in_stream)
    {
        std::cout << "Error: priority file could not be opened." << std::endl;
        return;
    }
    int priority_array_size = inputSize * 8;
    int *priority_array = new int[priority_array_size];
    std::string prio;
    int i = 0;
    while (std::getline(in_stream, prio) && i < priority_array_size)
        priority_array[i++] = atoi(prio.c_str());
    in_stream.close();
    assert(i == priority_array_size);

    int sortedarray_size = (inputSize + 1) / 2;
    uint16_t *sorted_input = new uint16_t[sortedarray_size];

    //Reordering the data
    for (int i = 0; i < (inputSize / 2); i++)
    {
        uint16_t inputsymbol = 0;
        uint16_t symbol;
        for (int j = 0; j < 16; j++)
        {
            symbol = getBitByImportance(j, priority_array[i * 16 + j], inputBytes);
            inputsymbol = inputsymbol | symbol;
        }
        sorted_input[i] = inputsymbol;
    }
    if (inputSize % 2 == 1)
    {
        uint16_t inputsymbol = 0;
        uint16_t symbol;
        for (int j = 0; j < 8; j++)
        {
            symbol = getBitByImportance(j, priority_array[(inputSize / 2) * 16 + j], inputBytes);
            inputsymbol = inputsymbol | symbol;
        }
        sorted_input[sortedarray_size] = inputsymbol;
    }

    //Putting the sorted data into RS_Matrix is alternate row major format
    int elementcounter = 0;
    int top_row = 0;
    int bottom_row = RS_ROWS - 1;
    int rows_to_fill = (sortedarray_size + data_length - 1) / data_length;
    if (rows_to_fill > RS_ROWS)
        rows_to_fill = RS_ROWS;
    int row;

    for (int i = 0; i < rows_to_fill; i++)
    {
        if (i % 2 == 1)
            row = top_row++;
        else
            row = bottom_row--;

        for (int j = 0; j < data_length; ++j)
        {
            if (elementcounter == sortedarray_size)
                break;
            RS_Matrix[row][j] = sorted_input[elementcounter];
            elementcounter++;
        }
    }

    delete[] priority_array;
    delete[] sorted_input;
}

int DNACoder::encode_file(string file_name, int file_size, int mapping_format, int skip_ECC_enable, string proirity_file, string output_file)
{
    std::cout << "Inside Encode file block" << std::endl;
    std::ifstream in_stream(file_name, std::ios::binary);
    if (!in_stream)
    {
        std::cout << "Error: input file could not be opened." << std::endl;
        return 1;
    }

    int inputsize = file_size;
    std::cout << "input size" + inputsize << std::endl;
    int total_symbols = RS_ROWS * code_length;
    int total_bytes = 2 * total_symbols;

    char *input_bytes = new char[inputsize];
    std::memset(&input_bytes[0], 0, inputsize);
    in_stream.read(&input_bytes[0], static_cast<std::streamsize>(inputsize));
    in_stream.close();

    int mapping = mapping_format;

    int skip_ECC = skip_ECC_enable;

    uint16_t RS_matrix[RS_ROWS][code_length];
    std::memset(&RS_matrix[0][0], 0, total_bytes);
    std::cout << "Before Mapping" << std::endl;
    if (mapping == 0)
        fillRSMatrixByColumn(input_bytes, inputsize, RS_matrix);
    // else fillRSMatrixByPriority(input_bytes, inputsize,  priority_file,  RS_matrix);

    delete[] input_bytes;

    /* Instantiate Finite Field and Generator Polynomials */

    /* const schifra::galois::field field(field_descriptor,
                                      schifra::galois::primitive_polynomial_size14,
                                      schifra::galois::primitive_polynomial14);
    std::cout << "After schifra::galois::field field" << std::endl;
    schifra::galois::field_polynomial generator_polynomial(field);
    std::cout << "Before Creation of sequential root generator" << std::endl;
    if (
            !schifra::make_sequential_root_generator_polynomial(field,
                                                            generator_polynomial_index,
                                                            generator_polynomial_root_count,
                                                            generator_polynomial)
      )
    {
        std::cout << "Error - Failed to create sequential root generator!" << std::endl;
        return 1;
    }*/

    /* Instantiate Encoder and Decoder (Codec) */
    //typedef schifra::reed_solomon::encoder<code_length,fec_length,data_length> encoder_t;
    //const encoder_t encoder(field, generator_polynomial);

    char output_matrix[RS_ROWS][2 * code_length];
    std::memset(&output_matrix[0][0], 0, total_bytes);
    std::cout << "Before ECC" << std::endl;
    if (!skip_ECC)
    {
        //  time_t start_encoder;
        // time (&start_encoder);
        // #pragma omp parallel for
        //for(int i=0; i<RS_ROWS; i++)
        //{

        /*Instantiate RS Block For Codec */

        //schifra::reed_solomon::block<code_length,fec_length> block;
        //schifra::reed_solomon::copy(&RS_matrix[i][0], code_length, block);
        /* Transform message into Reed-Solomon encoded codeword */

        //if (!encoder.encode(block))
        // {
        // std::cout << "Error - Critical encoding failure! "
        //      << "Msg: " << block.error_as_string()  << std::endl;
        //   return 1;
        //}

        //for(int j=0; j<code_length; j++){
        //uint16_t temp  = static_cast<uint16_t>(block.data[j] & 0xFFFF);
        //output_matrix[i][2*j]   = temp >> 8;
        // output_matrix[i][2*j+1] = temp & 0xFF;
        //}
        //}*/
        //time_t stop_encoder;
        //time(&stop_encoder);
        //std::cout << "Encoding \n";
        //std::cout << "-----" << stop_encoder-start_encoder << " seconds";
    }

    else
    { //skip RS
        for (int i = 0; i < RS_ROWS; i++)
        {
            schifra::reed_solomon::block<code_length, fec_length> block;
            schifra::reed_solomon::copy(&RS_matrix[i][0], code_length, block);
            for (int j = 0; j < data_length; j++)
            {
                uint16_t temp = static_cast<uint16_t>(block.data[j] & 0xFFFF);
                output_matrix[i][2 * j] = temp >> 8;
                output_matrix[i][2 * j + 1] = temp & 0xFF;
            }
        }
    }

    std::ofstream strand_file;
    strand_file.open(output_file);
    if (!strand_file)
    {
        std::cout << "Error: output file could not be created." << std::endl;
        return 1;
    }

    int write_length = code_length;
    if (skip_ECC)
        write_length = data_length;

    for (int i = 0; i < write_length; i++)
    {
        std::string s = ordToDNA(static_cast<uint16_t>(i));
        for (int j = 0; j < RS_ROWS; j++)
            s += symbolToDNA(static_cast<unsigned char>(output_matrix[j][2 * i]), static_cast<unsigned char>(output_matrix[j][2 * i + 1]));
        strand_file << s << std::endl;
    }
    strand_file.close();
    return 0;
}
int DNACoder::DNAtoOrd(std::string strand)
{
    int res = 0;
    for (int i = 0; i < 8; i++)
    {
        res = res << 2;
        switch (strand.at(i))
        {
        case 'A':
            res += 0;
            break;
        case 'C':
            res += 1;
            break;
        case 'G':
            res += 2;
            break;
        case 'T':
            res += 3;
            break;
        }
    }
    return res;
}

char DNACoder::DNAtoByte(std::string strand)
{
    char res = 0;
    for (int i = 0; i < 4; i++)
    {
        res = res << 2;
        switch (strand.at(i))
        {
        case 'A':
            res += 0;
            break;
        case 'C':
            res += 1;
            break;
        case 'G':
            res += 2;
            break;
        case 'T':
            res += 3;
            break;
        }
    }
    return res;
}

unsigned char DNACoder::DNAtoC1(std::string strand, int row)
{
    unsigned char res = 0;
    for (int i = 0; i < 4; i++)
    {
        res = res << 2;
        switch (strand.at(8 + 8 * row + i))
        {
        case 'A':
            res += 0;
            break;
        case 'C':
            res += 1;
            break;
        case 'G':
            res += 2;
            break;
        case 'T':
            res += 3;
            break;
        }
    }
    return res;
}

unsigned char DNACoder::DNAtoC2(std::string strand, int row)
{
    unsigned char res = 0;
    for (int i = 0; i < 4; i++)
    {
        res = res << 2;
        switch (strand.at(8 + 8 * row + i + 4))
        {
        case 'A':
            res += 0;
            break;
        case 'C':
            res += 1;
            break;
        case 'G':
            res += 2;
            break;
        case 'T':
            res += 3;
            break;
        }
    }
    return res;
}

uint8_t DNACoder::placeBitAccToPriority(int positionInChar, /*comes from the priority array(where the bit needs to be placed)*/
                                        int bitNumber,      /*The position of bit to be read from the decoded matrix(char)*/
                                        char *inputstring)
{
    int charNum = bitNumber / 8;
    int rem = bitNumber % 8;
    uint8_t temp = static_cast<uint8_t>(inputstring[charNum]);
    uint8_t mask = static_cast<uint8_t>(1) << (7 - rem);
    temp = ((temp & mask) << (rem)) >> positionInChar;
    return temp;
}

void DNACoder::WriteRSMatrixByPriority(int inputSize, string priority_file, char decoded_matrix[][2 * data_length], string output_file)
{
    std::ifstream in_stream(priority_file);
    if (!in_stream)
    {
        std::cout << "Error: priority file could not be opened." << std::endl;
        return;
    }

    int priority_array_size = inputSize * 8;
    int *priority_array = new int[priority_array_size];
    std::string prio;
    int i = 0;
    while (std::getline(in_stream, prio) && i < priority_array_size)
        priority_array[i++] = atoi(prio.c_str());
    in_stream.close();
    assert(i == priority_array_size);

    //Linearize the decoded data
    char *sortedarray = new char[inputSize];
    int elementcounter = 0;
    int top_row = 0;
    int bottom_row = RS_ROWS - 1;
    int rows_to_read = (inputSize / (data_length * 2)) + 1;
    if (rows_to_read > RS_ROWS)
        rows_to_read = RS_ROWS;
    int row;

    for (int i = 0; i < rows_to_read; i++)
    {
        if (i % 2 == 1)
            row = top_row++;
        else
            row = bottom_row--;

        for (int j = 0; j < data_length * 2; j++)
        {
            if (elementcounter == inputSize)
                break;
            elementcounter++;
            sortedarray[(i * data_length * 2) + j] = decoded_matrix[row][j];
        }
    }

    char *output_array = new char[inputSize];
    //Unpack the sorted array using priority to get the original input
    for (int i = 0; i < priority_array_size; i++)
    {
        int charnum = priority_array[i] / 8;
        int rem = priority_array[i] % 8;
        uint8_t outputchar = placeBitAccToPriority(rem, i, sortedarray);
        output_array[charnum] = static_cast<char>(static_cast<uint8_t>(output_array[charnum]) | outputchar);
    }

    //Write array to a file

    std::ofstream out_stream(output_file, std::ios::binary);
    if (!out_stream)
    {
        std::cout << "Error: output file could not be created." << std::endl;
        return;
    }
    for (int i = 0; i < inputSize; i++)
    {
        out_stream.write(&output_array[i], 1);
    }
    out_stream.close();
    delete[] output_array;
    delete[] sortedarray;
}
void DNACoder::WriteRSMatrixByColumn(int inputSize, char decoded_matrix[][data_length * 2], string output_file)
{

    std::ofstream out_stream(output_file, std::ios::binary);
    if (!out_stream)
    {
        std::cout << "Error: output file could not be created." << std::endl;
        return;
    }

    for (int i = 0; i < inputSize / 2; i++)
    {
        int row = i % RS_ROWS;
        int column = i / RS_ROWS;
        out_stream.write(&decoded_matrix[row][2 * column], 2);
    }

    if (inputSize % 2 != 0)
    {
        int ind = inputSize / 2;
        int row = ind % RS_ROWS;
        int column = ind / RS_ROWS;
        out_stream.write(&decoded_matrix[row][2 * column], 1);
    }

    out_stream.close();
}

int DNACoder ::decode_file(string file_name, int file_size, int mapping_format, int skip_ECC_enable, string proirity_def_file, string output_file)
{
    int inputSize = file_size;
    int total_symbols = RS_ROWS * code_length;
    int total_bytes = 2 * total_symbols;

    unsigned char input_bytes[RS_ROWS][2 * code_length];
    std::memset(&input_bytes[0], 0, total_bytes);

    std::ifstream in_stream(file_name);
    if (!in_stream)
    {
        std::cout << "Error: input file could not be opened." << std::endl;
        return 1;
    }

    int erasures[code_length] = {0};
    int erasure_count = code_length;

    std::string strand;
    while (std::getline(in_stream, strand))
    {
        int column = DNAtoOrd(strand);
        erasures[column] = 1;
        erasure_count--;
        for (int row = 0; row < RS_ROWS; row++)
        {
            input_bytes[row][2 * column] = DNAtoC1(strand, row);
            input_bytes[row][2 * column + 1] = DNAtoC2(strand, row);
        }
    }
    in_stream.close();

    schifra::reed_solomon::erasure_locations_t erasure_location_list;

    for (int i = 0; i < code_length; i++)
    {
        if (erasures[i] == 0)
            erasure_location_list.push_back(i);
    }

    uint16_t RS_matrix[RS_ROWS][code_length];
    std::memset(&RS_matrix[0][0], 0, total_bytes);

    for (int i = 0; i < RS_ROWS; i++)
        for (int j = 0; j < code_length; j++)
            RS_matrix[i][j] = (input_bytes[i][2 * j] << 8) + input_bytes[i][2 * j + 1];

    /* Instantiate Finite Field and Generator Polynomials */
    // const schifra::galois::field field(field_descriptor,
    //                                 schifra::galois::primitive_polynomial_size14,
    //                               schifra::galois::primitive_polynomial14);

    //schifra::galois::field_polynomial generator_polynomial(field);

    //if  (
    //  !schifra::make_sequential_root_generator_polynomial(field,
    //                                                    generator_polynomial_index,
    //                                                  generator_polynomial_root_count,
    //                                                generator_polynomial)
    //)
    //{
    //  std::cout << "Error - Failed to create sequential root generator!" << std::endl;
    // return 1;
    //}

    //typedef schifra::reed_solomon::decoder<code_length,fec_length,data_length> decoder_t;
    //const decoder_t RS_decoder(field, generator_polynomial_index);

    char decoded_matrix[RS_ROWS][2 * data_length];
    std::memset(&decoded_matrix[0][0], 0, 2 * RS_ROWS * data_length);

    int decoded[RS_ROWS];
    int detected[RS_ROWS];
    int corrected[RS_ROWS];

    int skip_ECC = skip_ECC_enable;

    if (!skip_ECC)
    {
        //#pragma omp parallel for
        //for(int i=0; i<RS_ROWS; i++)
        //{
        //  detected[i]=corrected[i]=0;
        // decoded[i]=1;
        /* Instantiate RS Block For Codec */
        //schifra::reed_solomon::block<code_length,fec_length> block;
        //schifra::reed_solomon::copy(&RS_matrix[i][0], code_length, block);

        //if (!RS_decoder.decode(block,erasure_location_list))
        //{
        //decoded[i]=0;
        //std::cout << "Row "<<i<<": Critical decoding failure, message= " << block.error_as_string() << std::endl;
        //}
        //detected[i]=block.errors_corrected;
        //corrected[i]=block.errors_corrected;
        //for(int j=0; j< data_length; j++){
        // uint16_t temp = static_cast<uint16_t>(block.data[j]);
        // decoded_matrix[i][2*j] = (temp >> 8) & 0xFF;
        //decoded_matrix[i][2*j+1] = temp & 0xFF;
        //}
        //}

        //for incorrectly decoded rows, copy the data before correction
        // for(int i=0; i<RS_ROWS; i++)
        //   if(decoded[i]==0)
        //   for(int j=0; j< data_length; j++)
        // {
        //uint16_t temp=RS_matrix[i][j];
        //decoded_matrix[i][2*j] = (temp >> 8) & 0xFF;
        //decoded_matrix[i][2*j+1] = temp & 0xFF;
        //}
    }

    else
    {
        for (int i = 0; i < RS_ROWS; i++)
        {
            schifra::reed_solomon::block<code_length, fec_length> block;
            schifra::reed_solomon::copy(&RS_matrix[i][0], code_length, block);
            for (int j = 0; j < data_length; j++)
            {
                uint16_t temp = static_cast<uint16_t>(block.data[j]);
                decoded_matrix[i][2 * j] = (temp >> 8) & 0xFF;
                decoded_matrix[i][2 * j + 1] = temp & 0xFF;
            }
        }
    }

    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "Row number |  decoded? | errors detected | errors corrected " << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;

    for (int i = 0; i < RS_ROWS; i++)
        std::cout << std::setw(7) << i << "    |" << std::setw(6) << decoded[i] << "     |" << std::setw(10) << detected[i] << "       |" << std::setw(10) << corrected[i] << std::endl;

    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\nErasures in each row: " << erasure_count << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;

    //if statement to either decode by column or priority

    int mapping = mapping_format;
    if (mapping == 0)
        WriteRSMatrixByColumn(inputSize, decoded_matrix, output_file);
    else
        WriteRSMatrixByPriority(inputSize, proirity_def_file, decoded_matrix, output_file);

    return 0;
}


std::vector<char> DNACoder::string_to_bytes(std::string text)
{
    std::vector<char> bytes;
    for(int i = 0; i < text.length(); i++)
    {
        bytes.push_back(text[i]);
    }
    bytes.push_back(0);

    return bytes;   
}