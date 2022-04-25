#ifndef _TRANSAQ_CONNECTOR
#define _TRANSAQ_CONNECTOR
#include <string>
#include <iostream>
#include <fstream>
#include "lib/finam/Functions.hpp"
#include "System.hpp"

#define TACCESS_API  __declspec(dllimport)



bool CALLBACK acceptor(BYTE *pData)
{
    // xmlfile<<pData<<std::endl;
    std::cout << pData << std::endl;

    TRCAPI::FreeMemory(pData);
    return true;
}


class User {
    std::string login;
    std::string password;
public:
    User() {

    }

    User(const std::string& login, const std::string& password) :
        login(login), password(password) {

    }
    ~User() {

    }

    inline std::string getLogin() const {
        return login;
    }

    inline std::string getPassword() const {
        return password;
    }

    inline void setLogin(const std::string& login) {
        this->login = login;
    }

    inline void setPassword(const std::string& password) {
        this->password = password;
    }

    void initialize(const std::string& login, const std::string& password) {
        setLogin(login);
        setPassword(password);
    }

    void print() {
        std::cout << "User: " << login << "\nPassword: " << password << std::endl;
    }
};

class TransaqConnector {
    User user;
    HMODULE hm = 0;

    void initDllsLibs() {
        System::loadLibrary(hm, "D:\\repo\\ScalpAssistant\\src\\lib\\finam\\txmlconnector64.dll");

        if (hm) {
            TRCAPI::initLog = reinterpret_cast<TRCAPI::initialize>(GetProcAddress(hm,"Initialize"));
            TRCAPI::initLog(reinterpret_cast<const BYTE*>("D:\\test"), 2);

            TRCAPI::FreeMemory = reinterpret_cast<TRCAPI::typeFreeMemory>(GetProcAddress(hm, "FreeMemory"));
            TRCAPI::SetCallback = reinterpret_cast<TRCAPI::typeSetCallback>(GetProcAddress(hm, "SetCallback"));
            TRCAPI::SetCallback(acceptor);

            TRCAPI::SendCommand =
                reinterpret_cast<TRCAPI::typeSendCommand>(GetProcAddress(hm,"SendCommand"));
            if (!TRCAPI::SendCommand) {
                System::print("\"SendCommand\" not found (0x" + std::to_string(GetLastError()) + ")\n", System::MessageType::Error);
                System::terminate();
            }
        }
    }
public:
    enum class CommandType {
        CONNECT = 0
    };

    TransaqConnector() {

    }

    TransaqConnector(const std::string& login, const std::string& password) {
        user.setLogin(login);
        user.setPassword(password);
    }

    bool connect() {
        initDllsLibs();

        if (user.getLogin().size() == 0 || user.getPassword().size() == 0) {
            System::print("Check login and password.", System::MessageType::Error);
            return false;
        }

        System::print("TransaqConnector - connected.", System::MessageType::Notification);
        return true;
    }

    void disconnect() {
        System::print("TransaqConnector - disconnected.", System::MessageType::Notification);
    }


    inline User& getUser() {
        return user;
    }

    bool sendCommand() {

        BYTE* ss = TRCAPI::SendCommand(const_cast<BYTE*> (reinterpret_cast<const BYTE*>(
            "<command id='connect'>"
            "<login>KOKS</login><password>koks</password>"
            "<host>192.168.15.15</host><port>3901</port>"
            "<logsdir>.\\LOGS\\</logsdir><loglevel>0</loglevel></command>")));

        std::ofstream out("log.txt");
        out << "123\n";
        out << reinterpret_cast<const char*>(ss);
        out.close();
    
        TRCAPI::FreeMemory(ss);

        return true;
    }

  
    ~TransaqConnector();
};

#endif