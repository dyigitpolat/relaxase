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
    DNAPatch(DNAPatch&& other); // 4. move constructor
    DNAPatch& operator=(DNAPatch&& other); // 5. move assignment

private:
    std::vector<DNAStrand> strands;
};