#pragma once

#include <vector>

#include "dna_strand.hpp"

class DNABlock
{
public:
    DNABlock();
    virtual ~DNABlock();

private:
    std::vector<DNAStrand> strands;
};