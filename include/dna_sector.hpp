#pragma once

#include <vector>
#include <string>
#include <inttypes.h>

#include "dna_block.hpp"
#include "dna_patch.hpp"

class DNASector
{
public:
    DNASector(); // default constructor
    DNASector(const DNASector& other); // 1. copy constructor
    DNASector& operator=(const DNASector& other); // 2. copy assignment
    virtual ~DNASector(); // 3. destructor
    DNASector(DNASector&& other); // 4. move constructor
    DNASector& operator=(DNASector&& other); // 5. move assignment

private:
    std::vector<DNABlock> blocks;
    std::vector<DNAPatch> patches;

    std::string primer_one;
    std::string primer_two;

    uint32_t patch_pointer;
};