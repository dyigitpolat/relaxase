#include "dna_sector.hpp"
#include "relaxase_configuration.hpp"

DNASector::DNASector() :
    next_available_superblock(0)
{

}

VirtualAttributes DNASector::add_file(const std::vector<DNAStrand> &strands)
{
    VirtualAttributes va;
    int block_size = RelaxaseConfiguration::get_instance()->get_block_size();
    va.superblock_id = next_available_superblock;
    va.number_of_superblocks = strands.size() / block_size;
    va.number_of_superblocks += strands.size() % block_size == 0 ? 0 : 1;

    for(int i = 0; i < va.number_of_superblocks; i++)
    {
        DNASuperBlock sb;
        superblocks.push_back(sb);
        for(int j = 0; j < block_size; j++)
        {
            if(i*block_size + j < strands.size())
            {
                superblocks[next_available_superblock+i].data_block.strands.push_back(strands[i*block_size + j]);
            }
            else
            {
                break;
            }
        }
    }

    next_available_superblock += va.number_of_superblocks;

    return va;
}


std::vector<DNAStrand> DNASector::retrieve_file(const VirtualAttributes &va) const
{
    std::vector<DNAStrand> strands;
    for(int i = 0; i < va.number_of_superblocks; i++)
    {
        std::vector<DNAStrand> block_strands = superblocks[va.superblock_id + i].retrieve_data();
        for(int j = 0; j < block_strands.size(); j++)
        {
            strands.push_back(block_strands[j]);
        }
    }

    return strands;
}


int DNASector::add_patch(const VirtualAttributes &va, const std::vector<DNAStrand> &strands, int num_attrib_strands)
{
    int block_size = RelaxaseConfiguration::get_instance()->get_block_size();
    int num_update_blocks = RelaxaseConfiguration::get_instance()->get_blocks_per_superblock() - 1;

    for(int i = 0; i < va.number_of_superblocks; i++)
    {
        for( int k = 0; k < num_update_blocks; k++)
        {
            for(int j = 0; j < block_size; j++)
            {
                if(i*block_size*num_update_blocks + k*block_size + j < strands.size())
                {
                    superblocks[va.superblock_id+i]
                        .patch_blocks[k]
                        .strands
                        .push_back(strands[i*block_size*num_update_blocks + k*block_size + j]);
                }
                else
                {
                    break;
                }
            }
        }
    }

    return 0;
}