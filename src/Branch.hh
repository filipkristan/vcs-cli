#ifndef VCS_CLI_BRANCH_HH
#define VCS_CLI_BRANCH_HH
#include <string>

class Branch {
public:
    // Branches
    static void makeNewBranch(const std::string &arg);
    static void changeBranch(const std::string &arg);
    static void removeBranch(const std::string &arg);
    static void renameBranch(const std::string &arg, const std::string &arg2);
};

#endif //VCS_CLI_BRANCH_HH
