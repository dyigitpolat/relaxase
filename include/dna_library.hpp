#pragma once

#include <vector>

#include "dna_pool.hpp"

class DNALibrary
{
public:
    DNALibrary(); // default constructor

private:
    std::vector<DNAPool> pools;
};