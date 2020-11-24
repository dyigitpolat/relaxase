#pragma once
#include <stdio.h>
#include <string.h>
using namespace std;

class RelaxaseClient
{
public:
    RelaxaseClient(); // default constructor
    int add_new_file(string file_name, uint8_t *in);
    int retrieve_file(string file_name, uint8_t *in);

private:
    void write_to_binary_file(string fname, uint8_t p_Data);
    void encrypt_cbc(uint8_t *in);
    void decrypt_cbc(uint8_t *in);
};
