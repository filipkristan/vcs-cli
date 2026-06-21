#include "Branch.hh"
#include "Patch.hh"
#include "Repo.hh"
#include <iostream>

void Branch::makeNewBranch(const std::string (&arg)) {
    std::string branchNameToCopy = branch;
    branch = arg;
    std::string command1 = "mkdir .vcs-cli/branch/" + branch;
    std::string command2 = "cp -r .vcs-cli/branch/" + branchNameToCopy + "/* " + ".vcs-cli/branch/" + branch;
    system(command1.c_str());
    system(command2.c_str());
    std::cout << "Created new branch: " << arg << std::endl;
}

void Branch::changeBranch(const std::string (&arg)) {
    std::string currentBranch = Repo::readDataFromFile(".vcs-cli/branch.txt");
    branchPath = ".vcs-cli/branch/" + arg;
    std::string command1 = "rm -rf src && mkdir src"; // Recreates src folder
    std::string command2 = "cp -r " + branchPath + "/new_src/*" + " src"; // Copies branch content to src folder
    system(command1.c_str());
    system(command2.c_str());
    Repo::writeDataToFile(".vcs-cli/branch.txt", arg, false);
    std::cout << "Changed branch to: " << arg << std::endl;
}

void Branch::removeBranch(const std::string (&arg)) {
    std::string command = "rm -rf .vcs-cli/branch/" + arg;
    system(command.c_str());
    std::cout << "Removed branch: " << arg << std::endl;
}

void Branch::renameBranch(const std::string (&arg), const std::string &arg2) {
    std::string command = "mv .vcs-cli/branch/" + arg + " .vcs-cli/branch/" + arg2;
    system(command.c_str());
    std::cout << "Renamed branch from " << arg << " to: " << arg2 << std::endl;
}
