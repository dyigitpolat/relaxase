#pragma once

#include <vector>

#include "dna_sector.hpp"

class DNAPool
{
public:
    DNAPool(); // default constructor
    DNAPool(const DNAPool& other); // 1. copy constructor
    DNAPool& operator=(const DNAPool& other); // 2. copy assignment
    virtual ~DNAPool(); // 3. destructor
    DNAPool(DNAPool&& other); // 4. move constructor
    DNAPool& operator=(DNAPool&& other); // 5. move assignment

private:
    std::vector<DNASector> sectors;
};