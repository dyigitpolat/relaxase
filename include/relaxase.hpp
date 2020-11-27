#pragma once

#include <string>
#include <vector>
#include <map>

#include "dna_library.hpp"
#include "dna_coder.hpp"

struct PatchAttributes
{
    uint16_t number_of_strands;
    uint16_t extension_pool;
    uint16_t extension_sector;
    uint32_t extension_superblock;
};

class Relaxase
{
public:
    Relaxase(); // default constructor

public:
    std::vector<char> retrieve_file_bytes(const std::string &filename) const;
    int update_file(const std::string &filename, const std::vector<char> &new_content);
    int create_file(const std::string &filename, const std::vector<char> &new_patch);

    std::vector<char> retrieve_file(const std::string &filename);

private:
    std::string bytes_to_dna(const std::vector<char> &new_content);
    std::vector<char> dna_to_bytes(const std::string &dna);

    std::vector<DNAStrand> generate_strands(const std::string &dna);
    std::string coalesce_strands(const std::vector<DNAStrand> &strands);

    DNALibrary lib;
    DNACoder coder;
    std::map<std::string, FileAttributes> files;
};