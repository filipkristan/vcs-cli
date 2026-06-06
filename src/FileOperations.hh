#ifndef XIT_FILEOPERATIONS_HH
#define XIT_FILEOPERATIONS_HH
#include <filesystem>

class FileOperations {
};

bool fileExists(const std::filesystem::path& p, std::filesystem::file_status s = std::filesystem::file_status{});

#endif //XIT_FILEOPERATIONS_HH
