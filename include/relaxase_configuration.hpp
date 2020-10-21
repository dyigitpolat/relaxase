#pragma once

#include <inttypes.h>

class RelaxaseConfiguration
{

public:
    void initialize(const uint32_t addressing_depth);
    static RelaxaseConfiguration *get_instance();

private:
    static RelaxaseConfiguration *instance;
    RelaxaseConfiguration();
    uint32_t addressing_depth;
};