#ifndef SMARTHOMEMANAGER_H
#define SMARTHOMEMANAGER_H

#include <vector>

#include "smart_home.h"
#include "Sensors/lightsensor.h"
#include "Devices/acunit.h"
#include "smarthomestatus.h"
#include "thread_pool.h"
#include "message.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>
#include <sstream> 

namespace smart_home
{

class SmartHomeManager
{
public:
    SmartHomeManager(SmartHome &smart_home);
    void Start();
    void StartServer();
    std::vector<std::string> split(std::string input, std::string delimiter);
    
private:
    void WaitForClientRequests(int* server_fd);
    bool getReqFromClient(int* clientSocket);
    void sendDataToClient(const char* message, int* clientSocket);
    void DoChanges();
    void GetDataFromFile();
    SmartHome& smartHome_;
    std::shared_ptr<std::mutex> mutex_;

};

class SocketDeleter {
public:
    void operator()(int* sockfd) const {
        if (sockfd && *sockfd != -1) {
            close(*sockfd);
            std::cout << "Socket closed" << std::endl;
        }
        delete sockfd;
    }
};
    
} // namespace smart_home

#endif