#include "user/User.h"
#include <thread>
#include <chrono>
#include <mutex>

std::mutex readyMutex;
bool ready = false;

void statusThread() {
    {
        std::lock_guard<std::mutex> lock(readyMutex);
        while (!ready) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));  
        }
    }

    while (true) {
        smart_home::User::getInstance().demoPrintSensorDataFromLivingRoom();
        smart_home::User::getInstance().getDevicesStatus();
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}

int main() {
    smart_home::User::getInstance().controlDevicesDemo();
    smart_home::User::getUserHouse().writeDataToFile();

    {
        std::lock_guard<std::mutex> lock(readyMutex);
        ready = true;
    }

    std::thread printingThread(statusThread);
    printingThread.detach();

    // I noticed in multiple examples that an instruction like this keeps the main thread alive and prevents it from exiting, serving as a placeholder
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); 
    }

    return 0;
}
