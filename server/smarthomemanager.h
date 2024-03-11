#ifndef SMARTHOMEMANAGER_H
#define SMARTHOMEMANAGER_H

#include <vector>

#include "smart_home.h"
#include "Sensors/lightsensor.h"
#include "Devices/acunit.h"
#include "smarthomestatus.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


namespace smart_home
{

class SmartHomeManager
{
public:
    SmartHomeManager(SmartHome &smart_home);
    void Start();
    void StartServer();

private:
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