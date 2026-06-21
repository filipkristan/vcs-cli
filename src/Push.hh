#ifndef VCS_CLI_PUSH_HH
#define VCS_CLI_PUSH_HH
#include <string>

using std::string;

class Push {
public:
    static void handlePushingRepo(const string &username);
};

void handlePushingRepo(const string &username);

#endif //VCS_CLI_PUSH_HH
