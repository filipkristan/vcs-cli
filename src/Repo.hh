#ifndef VCS_CLI_REPO_HH
#define VCS_CLI_REPO_HH
#include <string>

class Repo
{
    public:
    static void createNewPatch(const std::string& commitMessage);
    static void writeDataToFile(const std::string &location, const std::string &data, bool appendMode);
    static std::string readDataFromFile(const std::string &location);
    static void makeFirstPatch();
    static void initRepo(std::string arg);
    static void handleDisplayingTheHelpPage();
    static void handleMakingPatches(const std::string& commitMessage);
    static void setupRepo(std::string arg);
    static void revertPatches(const std::string& argv2);
    static void makeNewBranch(const std::string &arg);
    static void changeBranch(const std::string &arg);
    static void removeBranch(const std::string &arg);
    static void renameBranch(const std::string &arg, const std::string &arg2);
};


#endif //VCS_CLI_REPO_HH