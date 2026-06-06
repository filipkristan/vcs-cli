#include "pushRepoOperations.hh"
#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;
using std::string;
using std::cout;
using std::endl;

void handlePushingRepo(string username) {
    string command = "rsync -avz ./ ";
    command = command.append(username);     // append vcs-web usernames for auth (vcs-web creates an account on linux for the user with proper permissions)
    command = command.append("@");
    command = command.append("127.0.0.1");  // append domain/ip of vcs-web server TODO: Add setting or config for server ip
    command = command.append(":");
    command = command.append("/var/www/html/public/users/");    // append public folder location (this is where sveltekit app will look for the repos when the user tries to download them)
    command = command.append(username);     // append vcs-web username
    command = command.append("/repos/");
    command = command.append(fs::current_path().filename());    // append vcs-cli repo name
    command = command.append("/");
    //std::cout << "Pushing " << argv[3] << "'s repo to the server." << std::endl;
    //std::cout << "Running command: " << command << std::endl;
    system(command.c_str());    // run the command (rsync is needed!)
}