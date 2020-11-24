#pragma once

#include <inttypes.h>

class RelaxaseConfiguration
{

public:
    void initialize(
        const uint32_t addressing_depth,
        const uint32_t block_size,
        const uint32_t strand_length,
        const uint32_t primer_length);

    static RelaxaseConfiguration *get_instance();

    uint32_t get_addressing_depth() const;
    uint32_t get_block_size() const;
    uint32_t get_strand_length() const;
    uint32_t get_primer_length() const;

private:
    static RelaxaseConfiguration *instance;
    RelaxaseConfiguration();

    uint32_t addressing_depth;
    uint32_t block_size;
    uint32_t strand_length;
    uint32_t primer_length;
};
