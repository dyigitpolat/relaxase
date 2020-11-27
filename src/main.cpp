#include <iostream>
#include <string>
#include "relaxase.hpp"
#include "relaxase_configuration.hpp"
#include "dna_coder.hpp"
#include "linux_util.hpp"

int main()
{
    std::cout << "Welcome to relaxase!!" << std::endl;

    uint32_t number_of_pools = 64;
    uint32_t addressing_depth = 0;
    uint32_t blocks_per_superblock = 4;
    uint32_t block_size = 6;
    uint32_t strand_length = 100;
    uint32_t sectors_per_pool = 1000;
    uint32_t superblocks_per_sector = 128*128;

    RelaxaseConfiguration::get_instance()->initialize(
        addressing_depth, 
        block_size,
        strand_length,
        sectors_per_pool,
        number_of_pools,
        blocks_per_superblock,
        superblocks_per_sector
    );
    Relaxase r;
    DNACoder coder;

    std::string fname = "yigit";
    std::string contents = "file contents lolololol";

    r.create_file( fname, coder.string_to_bytes(contents) );
    std::vector<char> retrieved_bytes = r.retrieve_file( fname);
    std::string retrieved_string = &retrieved_bytes[0];

    std::cout << retrieved_string << std::endl;

    std::cout << linux_apply_patch("aaabbb", linux_diff("aaabbb", "aaacccbbb")) << std::endl;

    return 0;
}
