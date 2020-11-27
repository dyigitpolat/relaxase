#pragma once

#include <vector>
#include <string.h>
#include "dna_strand.hpp"
using namespace std;
const std::size_t code_length = 65535;
const std::size_t fec_length = 9830;
const std::size_t data_length = code_length - fec_length;

class DNACoder
{
public:
    DNACoder(); // default constructor
    int encode_file(string file_name, int file_size, int mapping_format, int skip_ECC_enable, string proirity_file, string output_file);
    int decode_file(string file_name, int file_size, int mapping_format, int skip_ECC_enable, string proirity_def_file, string output_file);

    std::vector<char> string_to_bytes(std::string text);

    std::string byteToDNA(char c);
    char DNAtoByte(std::string strand);

private:
    std::vector<DNAStrand> strands;
    std::string ordToDNA(uint16_t ord);
    std::string symbolToDNA(unsigned char c1, unsigned char c2);
    uint16_t getBitByImportance(int positionInSymbol, int bitNumber, char *inputstring);
    void fillRSMatrixByColumn(char *inputBytes, int inputSize, uint16_t RS_Matrix[][code_length]);
    void fillRSMatrixByPriority(char *inputBytes, int inputSize, string priority_file, uint16_t RS_Matrix[][code_length]);
    int DNAtoOrd(std::string strand);
    unsigned char DNAtoC1(std::string strand, int row);
    unsigned char DNAtoC2(std::string strand, int row);
    uint8_t placeBitAccToPriority(int positionInChar, /*comes from the priority array(where the bit needs to be placed)*/
                                  int bitNumber,      /*The position of bit to be read from the decoded matrix(char)*/
                                  char *inputstring);
    void WriteRSMatrixByPriority(int inputSize, string priority_file, char decoded_matrix[][2 * data_length], string output_file);
    void WriteRSMatrixByColumn(int inputSize, char decoded_matrix[][data_length * 2], string output_file);
};
