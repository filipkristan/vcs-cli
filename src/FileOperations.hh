#ifndef VCS_CLI_FILEOPERATIONS_HH
#define VCS_CLI_FILEOPERATIONS_HH
#include <filesystem>

class FileOperations {
};

bool fileExists(const std::filesystem::path& p, std::filesystem::file_status s = std::filesystem::file_status{});

#endif //VCS_CLI_FILEOPERATIONS_HH
