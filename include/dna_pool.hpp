#pragma once

#include <vector>

#include "dna_sector.hpp"

class DNAPool
{
public:
    DNAPool();
    virtual ~DNAPool();

private:
    std::vector<DNASector> sectors;
};