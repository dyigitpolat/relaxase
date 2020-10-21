#pragma once

#include <vector>
#include <string>
#include <inttypes.h>

#include "dna_block.hpp"
#include "dna_patch.hpp"

class DNASector
{
public:
    DNASector();
    virtual ~DNASector();

private:
    std::vector<DNABlock> blocks;
    std::vector<DNAPatch> patches;

    std::string primer_one;
    std::string primer_two;

    uint32_t patch_pointer;
};