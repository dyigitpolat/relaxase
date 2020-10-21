#include "relaxase_configuration.hpp"

RelaxaseConfiguration *RelaxaseConfiguration::instance = 0;

RelaxaseConfiguration::RelaxaseConfiguration()
{
    
}

void RelaxaseConfiguration::initialize(const uint32_t addressing_depth)
{
    get_instance()->addressing_depth = addressing_depth;
}

RelaxaseConfiguration* RelaxaseConfiguration::get_instance()
{
    if(!instance) instance = new RelaxaseConfiguration;
    return instance;
}