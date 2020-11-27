#pragma once 

#include <cstdio>
#include <iostream>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::string linux_diff(const std::string original, const std::string modified)
{
    std::ofstream orig_file;
    orig_file.open("original_temp.out");
    orig_file << original;
    orig_file.close();

    std::ofstream modified_file;
    modified_file.open("modified_temp.out");
    modified_file << modified;
    modified_file.close();

    return exec( "diff original_temp.out modified_temp.out");
}

std::string linux_apply_patch(const std::string original, const std::string patch)
{
    std::ofstream orig_file;
    orig_file.open("original_temp.out");
    orig_file << original;
    orig_file.close();

    std::ofstream patch_file;
    patch_file.open("patch_temp.out");
    patch_file << patch;
    patch_file.close();

    exec( "patch -s original_temp.out patch_temp.out -o modified_temp.out");
    return( exec( "cat modified_temp.out"));
}