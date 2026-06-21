#include "File.hh"
#include <filesystem>

bool File::fileExists(const std::filesystem::path &p, std::filesystem::file_status s) {
    if (std::filesystem::status_known(s) ? std::filesystem::exists(s) : std::filesystem::exists(p)) {
        return true;
    } else {
        //std::cout << " does not exist\n";
        return false;
    }
}
