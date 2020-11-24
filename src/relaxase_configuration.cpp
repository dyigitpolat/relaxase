#include "relaxase_configuration.hpp"

RelaxaseConfiguration *RelaxaseConfiguration::instance = 0;

RelaxaseConfiguration::RelaxaseConfiguration() : addressing_depth(0),
                                                 block_size(0),
                                                 strand_length(0),
                                                 primer_length(0)
{
}

void RelaxaseConfiguration::initialize(
    const uint32_t addressing_depth,
    const uint32_t block_size,
    const uint32_t strand_length,
    const uint32_t primer_length)
{
    this->addressing_depth = addressing_depth;
    this->block_size = block_size;
    this->strand_length = strand_length;
    this->primer_length = primer_length;
}

RelaxaseConfiguration *RelaxaseConfiguration::get_instance()
{
    if (!instance)
        instance = new RelaxaseConfiguration;
    return instance;
}

uint32_t RelaxaseConfiguration::get_addressing_depth() const
{
    return addressing_depth;
}

uint32_t RelaxaseConfiguration::get_block_size() const
{
    return block_size;
}

uint32_t RelaxaseConfiguration::get_strand_length() const
{
    return strand_length;
}

uint32_t RelaxaseConfiguration::get_primer_length() const
{
    return primer_length;
}