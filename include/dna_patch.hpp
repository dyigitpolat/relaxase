#pragma once

#include <vector>

#include "dna_strand.hpp"

class DNAPatch
{
public:
    DNAPatch(); // default constructor

private:
    std::vector<DNAStrand> strands;
};