#pragma once

#include <vector>
#include <string.h>
#include "dna_strand.hpp"
using namespace std;
const std::size_t code_length = 65535;

class DNAEncoder
{
public:
    DNAEncoder(); // default constructor
    int encode_file(string file_name, int file_size, int mapping_format, int skip_ECC_enable, string proirity_file, string output_file );
private:
    std::vector<DNAStrand> strands;
    std::string ordToDNA(uint16_t ord);
    std::string symbolToDNA(unsigned char c1, unsigned char c2);
    uint16_t getBitByImportance(int positionInSymbol, int bitNumber, char* inputstring);
    void fillRSMatrixByColumn(char *inputBytes, int inputSize,  uint16_t RS_Matrix[][code_length]);
    void fillRSMatrixByPriority(char *inputBytes, int inputSize,  char *priority_file,  uint16_t RS_Matrix[][code_length]);
    
};
