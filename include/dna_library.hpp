#pragma once

#include <vector>

#include "dna_pool.hpp"

class DNALibrary
{
public:
    DNALibrary(); // default constructor
    DNALibrary(const DNALibrary& other); // 1. copy constructor
    DNALibrary& operator=(const DNALibrary& other); // 2. copy assignment
    virtual ~DNALibrary(); // 3. destructor

private:
    std::vector<DNAPool> pools;

};