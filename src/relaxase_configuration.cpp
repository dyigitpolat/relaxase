#include "relaxase_configuration.hpp"

RelaxaseConfiguration *RelaxaseConfiguration::instance = 0;

RelaxaseConfiguration::RelaxaseConfiguration() : addressing_depth(0),
                                                 block_size(0),
                                                 strand_length(0),
                                                 sectors_per_pool(0),
                                                 number_of_pools(0),
                                                 blocks_per_superblock(0),
                                                 superblocks_per_sector(0)
{
}

void RelaxaseConfiguration::initialize(
    const uint32_t addressing_depth,
    const uint32_t block_size,
    const uint32_t strand_length,
    const uint32_t sectors_per_pool,
    const uint32_t number_of_pools,
    const uint32_t blocks_per_superblock,
    const uint32_t superblocks_per_sector)
{
    this->addressing_depth = addressing_depth;
    this->block_size = block_size;
    this->strand_length = strand_length;
    this->sectors_per_pool = sectors_per_pool;
    this->number_of_pools = number_of_pools;
    this->blocks_per_superblock = blocks_per_superblock;
    this->superblocks_per_sector = superblocks_per_sector;
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

uint32_t RelaxaseConfiguration::get_sectors_per_pool() const
{
    return sectors_per_pool;
}

uint32_t RelaxaseConfiguration::get_blocks_per_superblock() const
{
    return blocks_per_superblock;
}

uint32_t RelaxaseConfiguration::get_superblocks_per_sector() const
{
    return superblocks_per_sector;
}

uint32_t RelaxaseConfiguration::get_number_of_pools() const
{
    return number_of_pools;
}