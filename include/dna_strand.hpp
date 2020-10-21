#pragma once

#include <string>

class DNAStrand 
{
public:
    DNAStrand(); // default constructor
    DNAStrand(const DNAStrand& other); // 1. copy constructor
    DNAStrand& operator=(const DNAStrand& other); // 2. copy assignment
    virtual ~DNAStrand(); // 3. destructor
    DNAStrand(DNAStrand&& other); // 4. move constructor
    DNAStrand& operator=(DNAStrand&& other); // 5. move assignment

private:
    std::string data;
};