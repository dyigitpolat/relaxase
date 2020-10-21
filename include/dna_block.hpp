#pragma once

#include <vector>

#include "dna_strand.hpp"

class DNABlock
{
public:
    DNABlock(); // default constructor
    DNABlock(const DNABlock& other); // 1. copy constructor
    DNABlock& operator=(const DNABlock& other); // 2. copy assignment
    virtual ~DNABlock(); // 3. destructor

private:
    std::vector<DNAStrand> strands;
};