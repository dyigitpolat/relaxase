#pragma once

#include <vector>

#include "dna_block.hpp"

class DNASuperBlock
{
public:
    DNASuperBlock(); // default constructor

private:
    std::vector<DNABlock> strands;
};
