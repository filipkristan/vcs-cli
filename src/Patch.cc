#include "Patch.hh"
#include "Repo.hh"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

std::string branch = "master";
std::string branchPath = ".vcs-cli/branch/" + branch;
std::string lastPatchPath = ".vcs-cli/branch/" + branch + "/lastPatchPath.txt";

void Patch::revertPatches(const std::string &argv2) {
    std::ifstream DotXitFolderLocationPath(".vcs-cli");
    std::ifstream file;
    file.open(lastPatchPath);
    if (file.is_open()) {
        std::vector<std::string> data;
        std::string line;
        while (getline(file, line)) {
            data.push_back(line);
        }
        file.close();
        int start = atoi(data[0].c_str());
        int currentValue = std::stoi(data[0]) + 1;
        std::string command;
        std::string zeroPadding;
        for (int i = atoi(argv2.c_str()) - 1; i < start; ++i) {
            currentValue--;
            std::string newValue = std::to_string(currentValue);
            if (newValue.length() == 1) {
                zeroPadding = "000";
            } else if (newValue.length() == 2) {
                zeroPadding = "00";
            } else if (newValue.length() == 3) {
                zeroPadding = "0";
            } else {
                zeroPadding = "";
            }
            std::string value = zeroPadding + newValue;
            //command = "patch -s -p1 -d " + branchPath + "/new_src -R < " + branchPath + "/patches/" + value + ".patch";
            command.append("patch -s -p1 -d ");
            command.append(branchPath);
            command.append("/new_src -R < ");
            command.append(branchPath);
            command.append("/patches/");
            command.append(value);
            command.append(".patch");
            system(command.c_str());
            //std::string command2 = "rm " + branchPath + "/patches/" + value + ".patch";
            std::string command2 = "rm ";
            command2.append(branchPath);
            command2.append("/patches/");
            command2.append(value);
            command2.append(".patch");
            system((command2).c_str());
            int subtract = atoi(value.c_str()) - 1;
            system(("echo " + std::to_string(subtract) + " > .vcs-cli/lastPatchPath.txt").c_str());
        }
        std::string command2 = "cp -r .vcs-cli/new_src/ src/";
        system("rm -rf src");
        system(command2.c_str());
        system("rm -rf src/*.orig");
        std::cout << "Reverted patches!" << std::endl;
    } else
        std::cout << "Idk, this shouldn't happen!" << std::endl;
}

void Patch::makeFirstPatch() {
    // Create a diff between src dir and vcs-cli src dir and save patch in patches folder
    std::ofstream file;
    file.open(lastPatchPath.c_str());
    std::string value = "0001";
    if (file.is_open()) {
        file << value << "\n";
        std::string command1 = "diff -ruN " + branchPath + "/original_src/ src/ > " + branchPath +
                               "/patches/0001.patch";
        std::string command2 = "cp -r src/ " + branchPath + "/new_src";
        system(command1.c_str());
        system(command2.c_str());
        file.close();
    }
}

void Patch::handleMakingPatches(const std::string &commitMessage) {
    std::string command = branchPath + "/patches/0001.patch";
    std::ifstream first_patch_location_path(command.c_str());
    std::ifstream XitLocationPath(".vcs-cli");
    if (XitLocationPath.is_open()) {
        if (first_patch_location_path.is_open()) {
            Patch::createNewPatch(commitMessage);
            first_patch_location_path.close();
        } else {
            Patch::makeFirstPatch();
        }
        XitLocationPath.close();
    } else
        std::cout << "vcs-cli repo not yet initialized!" << std::endl;
}

void Patch::createNewPatch(const std::string &commitMessage) {
    std::ifstream lastPatchPathLocationRead;
    lastPatchPathLocationRead.open(lastPatchPath.c_str());
    if (lastPatchPathLocationRead.is_open()) {
        std::string zeroPadding;
        std::vector<std::string> data;
        std::string line;

        while (getline(lastPatchPathLocationRead, line)) {
            data.push_back(line);
        }

        int num = std::stoi(data[0]) + 1;
        std::string newValue = std::to_string(num);
        std::ofstream lastPatchLocationInsert;
        lastPatchLocationInsert.open(lastPatchPath.c_str());
        if (newValue.length() == 1) {
            zeroPadding = "000";
        } else if (newValue.length() == 2) {
            zeroPadding = "00";
        } else if (newValue.length() == 3) {
            zeroPadding = "0";
        } else {
            zeroPadding = "";
        }
        std::string value = zeroPadding + newValue;

        if (lastPatchLocationInsert.is_open()) {
            // Update the last patch
            lastPatchLocationInsert << value << "\n";

            // Make a new patch
            branch = Repo::readDataFromFile(".vcs-cli/branch.txt");
            branchPath = ".vcs-cli/branch/" + branch;
            std::string command = "diff -ruN " + branchPath + "/new_src/ src > " + branchPath + "/patches/" + value +
                                  ".patch";
            std::string command2 = "cp -r src " + branchPath + "/new_src/";
            std::string patchMessagesLocation = ".vcs-cli/branch/" + branch + "/patchMessages/";
            std::string command3 = "mkdir " + patchMessagesLocation;
            system(command.c_str());
            system(command2.c_str());
            if (std::filesystem::exists(patchMessagesLocation)) {
                std::cout << "File exists \n";
            } else {
                system(command3.c_str());
            }
            std::string dataLocation = ".vcs-cli/branch/" + branch + "/patchMessages/" + value;
            Repo::writeDataToFile(dataLocation, commitMessage, false);
            lastPatchLocationInsert.close();
        } else
            lastPatchPathLocationRead.close();
        std::cout << "Created a new patch!" << std::endl;
    } else
        std::cout << "Xit repo not yet initialized!" << "\n";
}
