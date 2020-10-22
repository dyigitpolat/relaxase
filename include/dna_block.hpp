#pragma once

#include <vector>

#include "dna_strand.hpp"

class DNABlock
{
public:
    DNABlock(); // default constructor

private:
    std::vector<DNAStrand> strands;
};