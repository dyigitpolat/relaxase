#include "dna_pool.hpp"
#include "relaxase_configuration.hpp"

DNAPool::DNAPool() :
    next_available_sector(0)
{
    DNASector s;
    sectors.push_back(s);
}

LogicalAttributes DNAPool::add_file(const std::vector<DNAStrand> &strands)
{
    LogicalAttributes la;
    la.sector_id = next_available_sector;
    la.virtual_attributes = sectors[next_available_sector].add_file(strands);

    if(la.virtual_attributes.superblock_id + la.virtual_attributes.number_of_superblocks 
        >= RelaxaseConfiguration::get_instance()->get_superblocks_per_sector())
    {
        DNASector s;
        sectors.push_back(s);
        next_available_sector++;
    }

    return la;
}


std::vector<DNAStrand> DNAPool::retrieve_file(const LogicalAttributes &la) const
{
    return sectors[la.sector_id].retrieve_file(la.virtual_attributes);
}


int DNAPool::add_patch(const LogicalAttributes &la, const std::vector<DNAStrand> &strands, int num_attrib_strands)
{
    return sectors[la.sector_id].add_patch(la.virtual_attributes, strands, num_attrib_strands);
}