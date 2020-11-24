#include <iostream>
#include "relaxase.hpp"
#include "relaxase_client.hpp"
//#include "dna_encoder.hpp"
#include "dna_decoder.hpp"

int main()
{
    std::cout << "Welcome to relaxase!!" << std::endl;
    RelaxaseClient r;
    uint8_t input[1000000];
    uint8_t *in= &input[0];
    uint8_t output[1000000];
    uint8_t *ou= &output[0];
    int count=r.add_new_file("example",in);
   
    //r.retrieve_file("example",in);
    std::cout << "Finished encryption" << std::endl;
    //DNAEncoder encoder;
    //encoder.encode_file("example_encrypt.dat", 10000, 0, 1 , "proirity_file.txt", "output_file.txt"); //output_file.txt contains encoded DNA strands
    std::cout << "Finished encoding" << std::endl;
    DNADecoder decoder;
    decoder.decode_file("output_file.txt",10000,0,1, "proirity_file.txt", "decoded_output.dat"); //decoded_output.txt contains decoded data
    r.retrieve_file("decoded_output",ou);
    return 0;
}
