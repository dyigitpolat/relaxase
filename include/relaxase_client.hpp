#pragma once

class RelaxaseClient 
{
public:
    RelaxaseClient(); // default constructor
    RelaxaseClient(const RelaxaseClient& other); // 1. copy constructor
    RelaxaseClient& operator=(const RelaxaseClient& other); // 2. copy assignment
    virtual ~RelaxaseClient(); // 3. destructor
    RelaxaseClient(RelaxaseClient&& other); // 4. move constructor
    RelaxaseClient& operator=(RelaxaseClient&& other); // 5. move assignment


private:
    
};