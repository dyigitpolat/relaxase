#pragma once

#include <string>
#include <vector>

#include "dna_library.hpp"

class Relaxase
{
public:
    Relaxase(); // default constructor
    Relaxase(const Relaxase& other); // 1. copy constructor
    Relaxase& operator=(const Relaxase& other); // 2. copy assignment
    virtual ~Relaxase(); // 3. destructor
    Relaxase(Relaxase&& other); // 4. move constructor
    Relaxase& operator=(Relaxase&& other); // 5. move assignment

public:
    std::vector<char> retrieve_file_bytes( const std::string &filename ) const;
    int update_file( const std::string &filename, const std::vector<char> &new_content );
    int create_file( const std::string &filename, const std::vector<char> &new_content );

private:
    DNALibrary* lib;
};