#include "smarthomeconnect.h"


namespace smart_home_client
{

void SmartHomeConnect::StartConnection()
{
	std::unique_ptr<int, SocketDeleter> clientSocket(new int(socket(AF_INET, SOCK_STREAM, 0)));

    if (*clientSocket == -1)
    {
        std::cerr << "Failed to create socket" << std::endl;
        return;
    }
    
	sockaddr_in serverAddress; 
	serverAddress.sin_family = AF_INET; 
	serverAddress.sin_port = htons(8080); 
	serverAddress.sin_addr.s_addr = INADDR_ANY; 

	if(connect(*clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1)
    {
        std::cerr << "Failed to bind socket" << std::endl;
        return;
    } 

    std::string input;

    do{
        std::cin >> input;
    } while (input != "X");

	// sending data 
	const char* message = "Hello, server!"; 
	send(*clientSocket, message, strlen(message), 0); 

}

std::string SmartHomeConnect::RequestString()
{
    std::cout<<"Menu:\n";
    std::cout<<"Press 1 to get the status of one device/sensor/room/entire home\n";
    std::cout<<"Press 2 to add a new device/sensor\n";
    std::cout<<"Press 3 to remove a device/sensor\n";
    std::cout<<"Press X to close the program\n";

    char input;
    bool next = true;
    std::string reqStr; 

    while (next)
    {
        std::cin>>input;

        switch (input)
        {
        case '1':
        {
            reqStr = StatusAction();
            if (reqStr == "")
            {
                /* code */
            }
            
            break;
        }
        case '2':
        {
            
            break;
        }
        case '3':
        {
            
            break;
        }
        case 'X':
        {
            
            break;
        }
        default:
        {
            next = false;
            std::cout<<"Invalid command, please choose one of the options write above\n";
            break;
        }
            
        }
    }
    
}

std::string SmartHomeConnect::StatusAction()
{
    std::cout<<"Press 1 to get the status of a device\n";
    std::cout<<"Press 2 to get the status of a sensor\n";
    std::cout<<"Press 3 to get the status of a room\n";
    std::cout<<"Press 4 to get the status of the entire home\n";
    std::cout<<"Press X to abort the action\n";
    
    char input;
    bool next = true;

    std::cin>>input;

    while (next)
    {
        std::cin>>input;

        switch (input)
        {
        case '1':
        {
            return "Status-Device-"+GetAName();
        }
        case '2':
        {
            return "Status-Sensor-"+GetAName();
        }
        case '3':
        {
            return "Status-Room-"+GetAName();
        }
        case '4':
        {
            return "Status-Home";
        }
        case 'X':
        {
            return "";
        }
        default:
        {
            next = false;
            std::cout<<"Invalid command, please choose one of the options write above\n";
            break;
        }
            
        }
    }

}

std::string SmartHomeConnect::GetAName()
{
    std::string input;
    char opt;
    do
    {
        std::cout<<"\nType the name of the selected object\n";
        std::cin>>input;

        std::cout<<"Are you sure about the name " + input;
        std::cout<<"\nType N for No, and anything else for yes";
        std::cin>>opt;
    } while (opt != 'N');

    return input;
}
}
