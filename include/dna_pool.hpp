#pragma once

#include <vector>

#include "dna_sector.hpp"

class DNAPool
{
public:
    DNAPool(); // default constructor

private:
    std::vector<DNASector> sectors;
};