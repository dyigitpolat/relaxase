#pragma once

#include <vector>
#include <string.h>
#include "dna_strand.hpp"
using namespace std;

class DNABlock
{
public:
    DNABlock(); // default constructor

    std::vector<DNAStrand> strands;
};
