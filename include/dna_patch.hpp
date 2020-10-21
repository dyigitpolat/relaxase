#pragma once

#include <vector>

#include "dna_strand.hpp"

class DNAPatch
{
public:
    DNAPatch(); // default constructor
    DNAPatch(const DNAPatch& other); // 1. copy constructor
    DNAPatch& operator=(const DNAPatch& other); // 2. copy assignment
    virtual ~DNAPatch(); // 3. destructor

private:
    std::vector<DNAStrand> strands;
};