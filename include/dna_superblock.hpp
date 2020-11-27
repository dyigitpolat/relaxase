#pragma once

#include <vector>

#include "dna_block.hpp"

class DNASuperBlock
{
public:
    DNASuperBlock(); // default constructor

    std::vector<DNAStrand> retrieve_data() const;

    DNABlock data_block;
    std::vector<DNABlock> patch_blocks;
    
};
