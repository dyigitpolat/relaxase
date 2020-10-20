#pragma once

#include <string>

#include "dna_library.hpp"

class Relaxase
{
public:
    Relaxase();
    virtual ~Relaxase();

    char* retrieve_file( std::string fname );

private:
    DNALibrary* lib;
};