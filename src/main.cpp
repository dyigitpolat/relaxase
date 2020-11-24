#include <iostream>
#include "relaxase.hpp"
#include "relaxase_client.hpp"
#include "dna_coder.hpp"

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
    DNACoder coder;
    coder.encode_file("test/test_data/example_encrypt.dat", 10000, 0, 1 , "test/test_data/proirity_file.txt", "test/test_data/encoded_file.txt"); //output_file.txt contains encoded DNA strands
    std::cout << "Finished encoding" << std::endl;
    coder.decode_file("test/test_data/encoded_file.txt",10000,0,1, "test/test_data/proirity_file.txt", "test/test_data/decoded_file.dat"); //decoded_output.txt contains decoded data
    std::cout << "Finished decoding" << std::endl;
    r.retrieve_file("test/test_data/decoded_file",ou);
    std::cout << "Finished decryption" << std::endl;
    return 0;
}
