#pragma once

#include <string>

class DNAStrand
{
public:
    DNAStrand(int address, std::string data); // default constructor

    int address;
    std::string data;
};