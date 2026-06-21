#ifndef VCS_CLI_PATCH_HH
#define VCS_CLI_PATCH_HH
#include <string>

extern std::string branch;
extern std::string branchPath;
extern std::string lastPatchPath;

class Patch {
public:
    // Patches
    static void makeFirstPatch();
    static void createNewPatch(const std::string &commitMessage);
    static void revertPatches(const std::string &argv2);
    static void handleMakingPatches(const std::string &commitMessage);
};

#endif //VCS_CLI_PATCH_HH
