#include "relaxase.hpp"
#include "relaxase_configuration.hpp"
#include "dna_coder.hpp"

Relaxase::Relaxase()
{
    
}

int Relaxase::create_file(const std::string &filename, const std::vector<char> &new_content)
{
    if(files.find(filename) != files.end())
    {
        throw "already exists";
    }

    std::string dna_string = bytes_to_dna(new_content);
    std::vector<DNAStrand> strands = generate_strands(dna_string);
    FileAttributes fa = lib.add_file(strands);
    files[filename] = fa;

    return 0;
}

std::vector<char> Relaxase::retrieve_file(const std::string &filename)
{
    std::vector<char> bytes;
    std::string dna_string;
    std::vector<DNAStrand> strands;
    FileAttributes fa;
    if(files.find(filename) != files.end())
    {
        fa = files[filename];
    }
    else
    {
        throw "no such file";
    }
    
    strands = lib.retrieve_file(fa);
    dna_string = coalesce_strands(strands);
    bytes = dna_to_bytes(dna_string);

    return bytes;
}


int Relaxase::update_file(const std::string &filename, const std::vector<char> &new_patch)
{
    std::vector<char> bytes;
    std::string dna_string;
    std::vector<DNAStrand> strands;
    FileAttributes fa;
    if(files.find(filename) != files.end())
    {
        fa = files[filename];
    }
    else
    {
        throw "no such file";
    }

    return 0;
}

std::string Relaxase::bytes_to_dna(const std::vector<char> &new_content)
{
    std::string s;
    for(int i = 0; i < new_content.size(); i++)
    {
        s += coder.byteToDNA(new_content[i]);
    }

    return s;
}


std::vector<char> Relaxase::dna_to_bytes(const std::string &dna)
{
    std::vector<char> bytes;

    for(int i = 0; i < dna.length(); i+=4)
    {
        std::string cur;
        cur += dna[i];
        cur += dna[i+1];
        cur += dna[i+2];
        cur += dna[i+3];
        bytes.push_back( coder.DNAtoByte(cur) );
    }

    return bytes;
}

std::vector<DNAStrand> Relaxase::generate_strands(const std::string &dna)
{
    std::vector<DNAStrand> strands;
    int strand_length = RelaxaseConfiguration::get_instance()->get_strand_length();
    int number_of_strands = dna.length() / strand_length;
    number_of_strands += (dna.length() % strand_length == 0) ? 0 : 1;

    for(int i = 0; i < number_of_strands; i++)
    {
        std::string s;
        for(int j = 0; j < strand_length; j++)
        {
            if(i*strand_length + j < dna.length())
            {
                s += dna[i*strand_length + j];
            }
            else
            {
                s += "A"; //0
            }
        }
        
        DNAStrand strand(i, s);
        strands.push_back(strand);
    }

    return strands;
}

std::string Relaxase::coalesce_strands(const std::vector<DNAStrand> &strands)
{
    std::string dna_string;
    int strand_length = RelaxaseConfiguration::get_instance()->get_strand_length();

    for(int i = 0; i < strands.size(); i++)
    {
        for(int j = 0; j < strand_length; j++)
        {
            dna_string += strands[i].data[j];
        }
    }

    return dna_string;
}