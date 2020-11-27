#pragma once

#include <vector>

#include "dna_sector.hpp"

struct LogicalAttributes
{
    int sector_id;
    VirtualAttributes virtual_attributes;
};

class DNAPool
{
public:
    DNAPool(); // default constructor
    LogicalAttributes add_file(const std::vector<DNAStrand> &strands);
    std::vector<DNAStrand> retrieve_file(const LogicalAttributes &la) const;
    int add_patch(const LogicalAttributes &la, const std::vector<DNAStrand> &strands, int num_attrib_strands);

    std::vector<DNASector> sectors;
private:
    int next_available_sector;
};