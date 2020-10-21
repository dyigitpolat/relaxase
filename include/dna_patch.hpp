#pragma once

#include <vector>

#include "dna_strand.hpp"

class DNAPatch
{
public:
    DNAPatch();
    virtual ~DNAPatch();

private:
    std::vector<DNAStrand> strands;
};