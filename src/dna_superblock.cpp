#include "dna_superblock.hpp"

DNASuperBlock::DNASuperBlock()
{
    
}

std::vector<DNAStrand> DNASuperBlock::retrieve_data() const
{
    return data_block.strands;
    //apply patches
}