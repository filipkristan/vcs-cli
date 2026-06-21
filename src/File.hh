#ifndef VCS_CLI_FILE_HH
#define VCS_CLI_FILE_HH
#include <filesystem>

class File {
public:
    static bool fileExists(const std::filesystem::path &p,
                           std::filesystem::file_status s = std::filesystem::file_status{});
};

#endif //VCS_CLI_FIL_HH
