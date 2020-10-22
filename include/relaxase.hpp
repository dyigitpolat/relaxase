#pragma once

#include <string>
#include <vector>

#include "dna_library.hpp"

class Relaxase
{
public:
    Relaxase(); // default constructor

public:
    std::vector<char> retrieve_file_bytes( const std::string &filename ) const;
    int update_file( const std::string &filename, const std::vector<char> &new_content );
    int create_file( const std::string &filename, const std::vector<char> &new_content );

private:
    DNALibrary lib;
};