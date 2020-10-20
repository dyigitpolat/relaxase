#pragma once

#include <string>

class DNAStrand 
{
public:
    DNAStrand();
    virtual ~DNAStrand();

private:
    std::string data;
};