#pragma once

#include <vector>
#include <string>

#include "dna_pool.hpp"
#include "dna_strand.hpp"

struct FileAttributes
{
    int pool_id;
    LogicalAttributes logical_attributes;
};

class DNALibrary
{
public:
    DNALibrary(); // default constructor
    FileAttributes add_file(const std::vector<DNAStrand> &strands);
    std::vector<DNAStrand> retrieve_file(const FileAttributes &fa) const;

    std::vector<DNAPool> pools;
    
private:
    int next_available_pool;
    
};