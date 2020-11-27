#include "dna_superblock.hpp"
#include "relaxase_configuration.hpp"

DNASuperBlock::DNASuperBlock()
{
    int num_update_blocks = RelaxaseConfiguration::get_instance()->get_blocks_per_superblock() - 1;
    for(int i = 0; i < num_update_blocks; i++)
    {
        DNABlock b;
        patch_blocks.push_back(b);
    }
}

std::vector<DNAStrand> DNASuperBlock::retrieve_data() const
{
    return data_block.strands;
    //apply patches
}