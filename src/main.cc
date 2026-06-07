#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include "xit.hh"
#include "FileOperations.hh"
#include "pushRepoOperations.hh"

using std::string;
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    if (argc <= 1 || std::string(argv[1]) == "init") {
        xit::setupXitRepo("master");
    }
    else if (std::string(argv[1]) == "patch") {
       xit::handleMakingPatches(argv[2]);
    }
    else if (std::string(argv[1]) == "push") {
        if (fileExists(".xit")) {
            // push changes to repo
            if (std::string(argv[2]) == "-u") {
                handlePushingRepo(argv[3]);
            } else {
                std::cout << "Use arg '-u {username}' to upload the repo to the user's profile" << std::endl;
            }
        }
        else {
            std::cout << "vcs repo not found! Create one using 'xit init'" << std::endl;
            std::cout << "Note: repos's can only be uploaded from the root folder!" << std::endl;
        }
    }
    else if (std::string(argv[1]) == "branch") {
        if (argc <= 2) {
            std::cout << "No branch command set!" << std::endl;
        }
        else if (argc == 3) {
            std::cout << "No branch name set!" << std::endl;
        }
        else if (argc >= 3  && std::string(argv[2]) == "new") {
            xit::makeNewBranch(argv[3]);
        }
        else if (argc >= 3  && std::string(argv[2]) == "change") {
            xit::changeBranch(argv[3]);
        }
        else if (argc >= 3  && std::string(argv[2]) == "remove") {
            xit::removeBranch(argv[3]);
        }
        else if (argc >= 3  && std::string(argv[2]) == "rename") {
            xit::renameBranch(argv[3], argv[4]);
        }
        else
            std::cout << "No worky :/" << std::endl;
    }
    else if (argc == 3 && std::string(argv[1]) == "revert") {
        xit::revertPatches(argv[2]);
    }
    else if (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help" || std::string(argv[1]) == "--help")
    {
        xit::handleDisplayingTheHelpPage();
    }
    return 0;
}