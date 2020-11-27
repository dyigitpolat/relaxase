#pragma once

#include <vector>
#include <string>
#include <inttypes.h>

#include "dna_superblock.hpp"
#include "dna_patch.hpp"

struct VirtualAttributes
{
    int superblock_id;
    int number_of_superblocks;
};


class DNASector
{
public:
    DNASector(); // default constructor

    int sector_id;
    std::vector<DNASuperBlock> superblocks;
    VirtualAttributes add_file(const std::vector<DNAStrand> &strands);
    std::vector<DNAStrand> retrieve_file(const VirtualAttributes &va) const;
    int add_patch(const VirtualAttributes &va, const std::vector<DNAStrand> &strands, int num_attrib_strands);

private:
    int next_available_superblock;
};