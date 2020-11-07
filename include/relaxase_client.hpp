#pragma once
#include <stdio.h>
#include <string.h>
using namespace std;

class RelaxaseClient 
{
public:
    RelaxaseClient(); // default constructor
    int file_access(string file_name); // File Access 
    

private:
    void write_to_binary_file( string fname,uint8_t p_Data); // Write Encrypted data to a binary file
    void encrypt_cbc(uint8_t *in); // cbc encryption 
    void decrypt_cbc(uint8_t *in); //cbc decryption
};
