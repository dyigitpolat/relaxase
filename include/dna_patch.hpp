#pragma once

#include <vector>

#include "dna_strand.hpp"

class DNAPatch
{
public:
    DNAPatch(); // default constructor

    std::vector<DNAStrand> strands;
};