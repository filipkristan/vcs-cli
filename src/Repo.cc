#include "Repo.hh"
#include "Patch.hh"
#include <fstream>
#include <algorithm>
#include <string>
#include <cctype>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

void Repo::writeDataToFile(const std::string &location, const std::string &data, bool appendMode) {
    std::ofstream file;
    if (appendMode) {
        file.open(location, std::ios::app);
    } else {
        file.open(location, std::ios::out);
    }

    if (file.is_open()) {
        file << data << "\n";
        file.close();
    } else
        std::cout << "File was closed!" << "\n";
}

std::string Repo::readDataFromFile(const std::string &location) {
    std::ifstream stream(location);
    std::string data;
    if (stream) {
        std::ostringstream ss;
        ss << stream.rdbuf();
        data = ss.str();
        std::erase(data, '\n');
    } else {
        std::cout << "Unable to read data from the file!" << '\n';
        std::cout << "File location: " << location << '\n';
    }
    return data;
}

void Repo::initRepo(std::string arg) {
    branch = std::move(arg);
    branchPath = ".vcs-cli/branch/" + branch;
    std::string command1 = "rm -rf src && mkdir src && mkdir -p .vcs-cli/branch && mkdir -p " + branchPath +
                           "/original_src && mkdir -p " + branchPath + "/old_src && mkdir -p " + branchPath +
                           "/new_src && mkdir -p " + branchPath + "/patches && cp -r src " + branchPath +
                           "/original_src/";
    system(command1.c_str());
    Patch::makeFirstPatch();
    Repo::writeDataToFile(".vcs-cli/branch.txt", "master", false);
    std::cout << "vcs-cli repo initialized!" << std::endl;
}

void Repo::handleDisplayingTheHelpPage() {
    std::cout << "Use the command 'vcs-cli init' to initialize a vcs-cli repo." << std::endl;
    std::cout << "Use the command 'vcs-cli new' to create a new patch." << std::endl;
    std::cout << "Use the command 'vcs-cli revert 00XX' to revert back to before that patch." << std::endl;
}

void Repo::setupRepo(std::string arg) {
    std::ifstream DotXitFolderLocationPath(".vcs-cli");
    std::ifstream firstPatchLocationPath(branchPath + "patches/0001.patch");
    if (!DotXitFolderLocationPath.is_open()) {
        Repo::initRepo(std::move(arg));
        DotXitFolderLocationPath.close();
        system(
            "echo \"author = \"John Smith\"\nwebsite = \"www.example.com\" \nprogram_name = \"app\" \nprogram_name_fancy = \"The Example Application\" \nlanguage = \"C++\" \ntags = \"example, portfolio, learning"
            " > info.txt");
    } else
        std::cout << "vcs-cli repo already initialized!" << std::endl;
}
