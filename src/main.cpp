#include <iostream>
#include "relaxase.hpp"
#include "relaxase_client.hpp"

int main()
{
    std::cout << "Welcome to relaxase!!" << std::endl;
    RelaxaseClient r;
    uint8_t input[1000000];
    uint8_t *in= &input[0];
    int count=r.add_new_file("example",in);
    r.retrieve_file("example",in);
    return 0;
}
