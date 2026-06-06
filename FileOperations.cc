#include "FileOperations.hh"
#include <filesystem>

bool fileExists(const std::filesystem::path& p, std::filesystem::file_status s)
{
    //std::cout << p;
    if (std::filesystem::status_known(s) ? std::filesystem::exists(s) : std::filesystem::exists(p)) {
        //std::cout << " exists\n";
        return true;
    }
    else {
        //std::cout << " does not exist\n";
        return false;
    }
}