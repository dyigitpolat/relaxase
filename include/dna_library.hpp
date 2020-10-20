#pragma once

#include <vector>

#include "dna_pool.hpp"

class DNALibrary
{
public:
    DNALibrary();
    virtual ~DNALibrary();

private:
    std::vector<DNAPool> pools;

};