#pragma once

#include <vector>

#include "dna_strand.hpp"

class DNAPool
{
public:
    DNAPool();
    virtual ~DNAPool();

private:
    std::vector<DNAStrand> strands;
};