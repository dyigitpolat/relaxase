#pragma once

#include <inttypes.h>

class RelaxaseConfiguration
{

public:
    void initialize(
        const uint32_t addressing_depth,
        const uint32_t block_size,
        const uint32_t strand_length,
        const uint32_t sectors_per_pool,
        const uint32_t number_of_pools,
        const uint32_t blocks_per_superblock,
        const uint32_t superblocks_per_sector);

    static RelaxaseConfiguration *get_instance();

    uint32_t get_addressing_depth() const;
    uint32_t get_block_size() const;
    uint32_t get_strand_length() const;
    uint32_t get_sectors_per_pool() const;
    uint32_t get_number_of_pools() const;
    uint32_t get_blocks_per_superblock() const;
    uint32_t get_superblocks_per_sector() const;

private:
    static RelaxaseConfiguration *instance;
    RelaxaseConfiguration();

    uint32_t number_of_pools;
    uint32_t addressing_depth;
    uint32_t blocks_per_superblock;
    uint32_t block_size;
    uint32_t strand_length;
    uint32_t sectors_per_pool;
    uint32_t superblocks_per_sector;
};
