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
    DNALibrary(DNALibrary&& other); // 4. move constructor
    DNALibrary& operator=(DNALibrary&& other); // 5. move assignment

private:
    std::vector<DNAPool> pools;

};