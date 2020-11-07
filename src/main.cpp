#include <iostream>
#include "relaxase.hpp"
#include "relaxase_client.hpp"

int main()
{
    std::cout << "Welcome to relaxase!!" << std::endl;
    RelaxaseClient r;
    r.file_access("example");
    return 0;
}
