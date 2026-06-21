#ifndef VCS_CLI_REPO_HH
#define VCS_CLI_REPO_HH
#include <string>

class Repo
{
    public:
    // Misc
    static void initRepo(std::string arg);
    static void setupRepo(std::string arg);
    static void handleDisplayingTheHelpPage();
    static void writeDataToFile(const std::string &location, const std::string &data, bool appendMode);
    static std::string readDataFromFile(const std::string &location);
};


#endif //VCS_CLI_REPO_HH