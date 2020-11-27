#include "dna_library.hpp"
#include "relaxase_configuration.hpp"

DNALibrary::DNALibrary() :
    next_available_pool(0)
{
    DNAPool p;
    pools.push_back(p);
}

FileAttributes DNALibrary::add_file(const std::vector<DNAStrand> &strands)
{
    FileAttributes fa;
    fa.pool_id = next_available_pool;
    fa.logical_attributes = pools[next_available_pool].add_file(strands);
    
    if(fa.logical_attributes.sector_id >= RelaxaseConfiguration::get_instance()->get_sectors_per_pool())
    {
        DNAPool p;
        pools.push_back(p);
        next_available_pool++;
    }

    return fa;
}


std::vector<DNAStrand> DNALibrary::retrieve_file(const FileAttributes &fa) const
{
    return pools[fa.pool_id].retrieve_file(fa.logical_attributes);
}


int DNALibrary::add_patch(const FileAttributes &fa, const std::vector<DNAStrand> &strands, int num_attrib_strands)
{
    return pools[fa.pool_id].add_patch(fa.logical_attributes, strands, num_attrib_strands);
}