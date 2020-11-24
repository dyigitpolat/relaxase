#pragma once

#include <vector>
#include <string.h>
#include "dna_strand.hpp"
using namespace std;

const std::size_t dcode_length = 65535;
const std::size_t fec_length  = 9830;
const std::size_t data_length = dcode_length - fec_length;

class DNADecoder
{
public:
    DNADecoder(); // default constructor
    int decode_file(string file_name,int file_size, int mapping_format, int skip_ECC_enable, char * proirity_def_file, char * output_file);
private:
   int DNAtoOrd(std::string strand);
   unsigned char DNAtoC1(std::string strand, int row);
   unsigned char DNAtoC2(std::string strand, int row);
   uint8_t placeBitAccToPriority(int positionInChar, /*comes from the priority array(where the bit needs to be placed)*/
                              int bitNumber,      /*The position of bit to be read from the decoded matrix(char)*/
                              char* inputstring);
   void WriteRSMatrixByPriority(int inputSize, char *priority_file, char decoded_matrix[][2*data_length],char *output_file);
   void WriteRSMatrixByColumn(int inputSize, char decoded_matrix[][data_length*2],char* output_file);
   
   
};
